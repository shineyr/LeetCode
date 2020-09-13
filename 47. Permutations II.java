class Solution {
    public List<List<Integer>> permuteUnique(int[] nums) {
        List<List<Integer>> permutations = new ArrayList<>();

        boolean[] visited = new boolean[nums.length];
        for (int i = 0; i < nums.length; ++i) {
            visited[i] = false;
        }

        Arrays.sort(nums);

        permuteUnique(permutations, new ArrayList<>(), nums, visited, 0);

        return permutations;
    }

    private void permuteUnique(List<List<Integer>> permutations, List<Integer> permutation, int[] nums, boolean[] visited, int count) {
        if (count == nums.length) {
            permutations.add(new ArrayList<>(permutation));
        }

        for (int i = 0; i < nums.length; ++i) {
            if (!visited[i]) {
                if (i != 0 && nums[i] == nums[i-1] && !visited[i-1]) {
                    continue;
                }
                permutation.add(nums[i]);
                visited[i] = true;

                permuteUnique(permutations, permutation, nums, visited, count + 1);

                permutation.remove(permutation.size() - 1);
                visited[i] = false;
            }
        }
    }
}
