class Solution {
    // numTrees[4] = numTrees[0] * numTrees[3] +
    //               numTrees[1] * numTrees[2] +
    //               numTrees[2] * numTrees[1] +
    //               numTrees[3] * numTrees[0]
    public int numTrees(int n) {
        int[] numTrees = new int[n+1];

        numTrees[0] = 1; // empty tree
        numTrees[1] = 1; // tree with only one root

        for (int node = 1; node < n + 1; ++node) {
            int totalTrees = 0;

            for (int root = 1; root < node + 1; ++root) {
                int leftNodes = root - 1;
                int rightNodes = node - root;

                totalTrees += numTrees[leftNodes] * numTrees[rightNodes];
            }

            numTrees[node] = totalTrees;
        }

        return numTrees[n];
    }
}
