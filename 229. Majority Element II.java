class Solution {
    public List<Integer> majorityElement(int[] nums) {
        List<Integer> majorities = new ArrayList<>();

        // There're at most two numbers which show up more than n/3 times
        int count1 = 0, count2 = 0;
        Integer candidate1 = null, candidate2 = null;

        for (int i = 0; i < nums.length; ++i) {
            if (candidate1 != null && candidate1 == nums[i]) {
                ++count1;
            } else if (candidate2 != null && candidate2 == nums[i]) {
                ++count2;
            } else if (count1 == 0) {
                candidate1 = nums[i];
                ++count1;
            } else if (count2 == 0) {
                candidate2 = nums[i];
                ++count2;
            } else {
                --count1;
                --count2;
            }
        }

        // Verify whether these two numbers are majority ones
        count1 = 0;
        count2 = 0;
        for (int i = 0; i < nums.length; ++i) {
            if (candidate1 == nums[i]) {
                ++count1;
            } else if (candidate2 == nums[i]) {
                ++count2;
            }
        }

        if (count1 > nums.length / 3) {
            majorities.add(candidate1);
        }

        if (count2 > nums.length / 3) {
            majorities.add(candidate2);
        }

        return majorities;
    }

    public List<Integer> majorityElement2(int[] nums) {
        List<Integer> ret = new ArrayList<>();

        int len = nums.length, majority = len/3;
        if (len == 0) {
            return ret;
        } 

        Arrays.sort(nums);

        int count = 1;
        for(int i = 1; i < len; ++i) {
            if (nums[i] != nums[i-1]) {
                if (count > majority) {
                    ret.add(nums[i-1]);
                } 
                count = 1;
            } else {
                ++count;
            }
        }
        
        if (count > majority) {
            ret.add(nums[len-1]);
        }

        return ret;
    }

    public List<Integer> majorityElement1(int[] nums) {
        List<Integer> ret = new ArrayList<>();
        Map<Integer, Integer> times = new HashMap<>();

        int len = nums.length, majority = len/3;
        if (len == 0) {
            return ret;
        }

        for (int i = 0; i < len; ++i) {
            if (!times.containsKey(nums[i])) {
                times.put(nums[i], 1);
            } else {
                times.put(nums[i], times.get(nums[i]) + 1);
            }
        }

        for (Map.Entry entry : times.entrySet()) {
            if ((int)entry.getValue() > majority) {
                ret.add((int)entry.getKey());
            }
        }

        return ret;
    }
}
