class Solution {
    public boolean canFinish(int numCourses, int[][] prerequisites) {
        Map<Integer, Set<Integer>> prevCoursesMap = new HashMap<>();
        Map<Integer, Set<Integer>> nextCoursesMap = new HashMap<>();
        
        for(int i = 0; i < prerequisites.length; ++i) {
            int course = prerequisites[i][0], prevCourse = prerequisites[i][1];
            
            Set<Integer> prevCourses = prevCoursesMap.getOrDefault(course, new HashSet<Integer>());
            
            Set<Integer> nextCourses = nextCoursesMap.getOrDefault(prevCourse, new HashSet<Integer>());

            
            prevCourses.add(prevCourse);
            nextCourses.add(course);
            
            prevCoursesMap.put(course, prevCourses);
            nextCoursesMap.put(prevCourse, nextCourses);
        }
        
        
        
        // Records the courses which do not have prev courses
        Queue<Integer> queue = new LinkedList<>();
        
        for (int i = 0; i < numCourses; ++i) {
            if (!prevCoursesMap.containsKey(i)) {
                queue.offer(i);
            } 
        }
        
        boolean[] finished = new boolean[numCourses];
        while(!queue.isEmpty()) {
            int course = queue.poll();
            
            finished[course] = true;
            
            if (!nextCoursesMap.containsKey(course)) {
                continue;
            }
            
            for (Integer nextCourse : nextCoursesMap.get(course)) {
                Set<Integer> prevCourses = prevCoursesMap.get(nextCourse);
                prevCourses.remove(course);
                
                if (prevCourses.isEmpty()) {
                    prevCoursesMap.remove(nextCourse);
                    queue.add(nextCourse);
                }
            }
        }
        
        boolean ret = true;
        for(int i = 0; i < numCourses; ++i) {
            ret &= finished[i];
        }
        
        return ret;
    }
}
