import java.util.ArrayList;
import java.util.Collections;
import java.util.List;

/**
 * 1268. Search Suggestions System
 *
 * Given an array of strings products and a string searchWord.
 * We want to design a system that suggests at most three product names from products after each character of searchWord is typed.
 * Suggested products should have common prefix with the searchWord.
 * If there are more than three products with a common prefix return the three lexicographically minimums products.
 *
 * Return list of lists of the suggested products after each character of searchWord is typed.
 */
public class NO_1268 {
    Solution solution = new Solution();

    public static void main(String[] args) {
        System.out.println(new NO_1268().solution.suggestedProducts(new String[] {"mobile","mouse","moneypot","monitor","mousepad"}, "mouse"));

        System.out.println(new NO_1268().solution.suggestedProducts(new String[] {"havana"}, "havana"));

        System.out.println(new NO_1268().solution.suggestedProducts(new String[] {"bags","baggage","banner","box","cloths"}, "bags"));

    }

    class Solution {
        public List<List<String>> suggestedProducts(String[] products, String searchWord) {

            List<List<String>> suggestedProducts = new ArrayList<>();

            for (int i=0; i<searchWord.length(); ++i) {
                String subStr = searchWord.substring(0, i+1);

                List<String> subSuggestedProducts = new ArrayList<>();
                for (int j=0; j<products.length; ++j) {
                    if (products[j].startsWith(subStr)) {
                        subSuggestedProducts.add(products[j]);
                    }
                }

                Collections.sort(subSuggestedProducts);

                if (subSuggestedProducts.size() >= 3) {
                    suggestedProducts.add(subSuggestedProducts.subList(0, 3));
                } else {
                    suggestedProducts.add(subSuggestedProducts);
                }
            }

            return suggestedProducts;
        }
    }
}
