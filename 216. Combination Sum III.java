class Solution {
    public List<List<Integer>> combinationSum3(int k, int n) {
        List<List<Integer>> combinations = new ArrayList<>();

        dfs(combinations, new ArrayList<>(), 1, n, k);

        return combinations;
    }

    private void dfs(List<List<Integer>> combinations, List<Integer> combination, int idx, int diff, int k) {
        if (diff == 0 && combination.size() == k) {
            combinations.add(new ArrayList<>(combination));
            return;
        } else if (diff < 0 || combination.size() == k) {
            return;
        }

        for (int i = idx; i <= 9; ++i) {
            combination.add(i);

            dfs(combinations, combination, i + 1, diff - i, k);

            combination.remove(combination.size() - 1);
        }
    }
}
