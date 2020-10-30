class Solution {
    public String getHint(String secret, String guess) {
        int bulls = 0, cows = 0;
        int[] count = new int[10];

        for (int i = 0; i < secret.length(); ++i) {
            int sNum = secret.charAt(i) - '0';
            int gNum = guess.charAt(i) - '0';

            if (sNum == gNum) {
                ++bulls;
            } else {
                // When count[sNum] < 0 means sNum shows in guess
                if (count[sNum] < 0) {
                    ++cows;
                }

                // When count(gNum) > 0 means gNum shows in secret
                if (count[gNum] > 0) {
                    ++cows;
                }

                ++count[sNum];
                --count[gNum];
            }
        }

        return bulls + "A" + cows + "B";
    }
    
    public String getHint1(String secret, String guess) {
        int sLen = secret.length(), gLen = guess.length();

        Map<Character, Integer> locationMap = new HashMap<>();

        int bulls = 0, cows = 0;
        for (int i = 0 ; i < sLen; ++i) {
            char sNum = secret.charAt(i);
            char gNum = guess.charAt(i);
            if (sNum == gNum) {
                ++bulls;
            } else {
                if (!locationMap.containsKey(sNum)) {
                    locationMap.put(sNum, 0);
                }

                locationMap.put(sNum, locationMap.get(sNum) + 1);
            }
        }

        for (int j = 0; j < gLen; ++j) {
            char sNum = secret.charAt(j);
            char gNum = guess.charAt(j);

            if (sNum == gNum) {
                continue;
            } else {
                if (locationMap.containsKey(gNum) && locationMap.get(gNum) > 0) {
                    ++cows;
                    locationMap.put(gNum, locationMap.get(gNum) - 1);
                }
            }
        }

        return bulls + "A" + cows + "B";
    }
}
