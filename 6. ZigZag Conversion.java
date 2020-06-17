import java.util.ArrayList;
import java.util.List;
import java.util.stream.Collectors;

/**
 * https://leetcode.com/problems/zigzag-conversion/
 * 6. ZigZag Conversion
 */
public class NO_6 {
    Solution solution = new Solution();

    public static void main(String[] args) {
        System.out.println(new NO_6().solution.convert("AB", 1));
    }

    class Solution {
        public String convert(String s, int numRows) {
            if (numRows == 1) {
                return s;
            }

            numRows = Math.min(s.length(), numRows);
            List<StringBuilder> strRows = new ArrayList<>(numRows);
            for (int idx = 0; idx < numRows; ++idx) {
                strRows.add(new StringBuilder());
            }

            int rowIdx = 0;
            boolean goDown = false;
            for (char c : s.toCharArray()) {
                strRows.get(rowIdx).append(c);

                // Should switch
                if (rowIdx == 0 || rowIdx == numRows - 1) {
                    goDown = !goDown;
                }

                rowIdx += goDown ? 1 : -1;
            }

            return String.join("", strRows);
        }
    }
}
