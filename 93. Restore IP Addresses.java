class Solution {
    public List<String> restoreIpAddresses(String s) {
        List<String> allIpAddresses = new ArrayList<>();

        snapshotIpAddress(allIpAddresses, s, 0, new String[4], 0);

        return allIpAddresses;
    }

    private void snapshotIpAddress(List<String> allIpAddresses, String s, int idx, String[] ipSnapshot, int segment) {
        // Find a valid IP address
        if (segment == 4 && idx == s.length()) {
            String ipAddress = String.join(".", ipSnapshot[0], ipSnapshot[1], ipSnapshot[2], ipSnapshot[3]);
            allIpAddresses.add(ipAddress);
        } else if (segment == 4 && idx != s.length()) {
            return;
        }

        for (int len = 1; len <= 3 && idx + len <= s.length(); ++len) {
            String snapshot = s.substring(idx, idx + len);
            int value = Integer.parseInt(snapshot);

            if (value > 255 || (len >= 2 && s.charAt(idx) == '0')) {
                break;
            }

            ipSnapshot[segment] = snapshot;

            snapshotIpAddress(allIpAddresses, s, idx + len, ipSnapshot, segment + 1);

        }
    }
}
