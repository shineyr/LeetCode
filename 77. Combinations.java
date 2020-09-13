class Solution {
    public List<List<Integer>> combine(int n, int k) {
        List<List<Integer>> combinations = new ArrayList<>();

        combine(combinations, new ArrayList<>(), n, k, 1);

        return combinations;
    }

    private void combine(List<List<Integer>> combinations, List<Integer> combination, int n, int k, int idx) {
        if (combination.size() == k) {
            combinations.add(new ArrayList<>(combination));
            return;
        }

        for (int i = idx; i <= n; ++i) {

            combination.add(i);

            combine(combinations, combination, n, k, i + 1);

            combination.remove(combination.size() - 1);
        }
    }
}
