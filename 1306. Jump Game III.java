class Solution {
    public boolean canReach(int[] arr, int start) {
        if (start >= 0 && start < arr.length && arr[start] >= 0) {
            if (arr[start] == 0) {
                return true;
            }

            arr[start] = -arr[start];

            return canReach(arr, start + arr[start]) || canReach(arr, start - arr[start]);
        }

        return false;
    }
    
    public boolean canReach1(int[] arr, int start) {
        int len = arr.length;

        Queue<Integer> queue = new LinkedList<>();
        queue.add(start);

        while (!queue.isEmpty()) {
            int curPos = queue.poll();

            if (arr[curPos] == 0) {
                return true;
            }

            if (arr[curPos] < 0) {
                continue;
            }

            int forwardPos = curPos + arr[curPos];
            if (forwardPos < len) {
                queue.offer(forwardPos);
            }

            int backwardPos = curPos - arr[curPos];

            if (backwardPos >= 0) {
                queue.offer(backwardPos);
            }
            
            arr[curPos] = -arr[curPos];
        }

        return false;
    }
}
