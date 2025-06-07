import java.util.*;

class obj {
    int sum;
    int first;
    int second;
    int indexInNums2;

    obj(int sum, int first, int second, int j) {
        this.sum = sum;
        this.first = first;
        this.second = second;
        this.indexInNums2 = j;
    }
}

class Solution {
    public List<List<Integer>> kSmallestPairs(int[] nums1, int[] nums2, int k) {
        PriorityQueue<obj> pq = new PriorityQueue<>(new Comparator<obj>() {
            public int compare(obj o1, obj o2) {
                return o1.sum - o2.sum;
            }
        });

        for (int i = 0; i < Math.min(nums1.length, k); i++) {
            pq.offer(new obj(nums1[i] + nums2[0], nums1[i], nums2[0], 0));
        }

        List<List<Integer>> lst = new ArrayList<>();

        while (k-- > 0 && !pq.isEmpty()) {
            obj top = pq.poll();
            List<Integer> pair = new ArrayList<>();
            pair.add(top.first);
            pair.add(top.second);
            lst.add(pair);

            // If possible, pair top.first with next element in nums2
            int nextIndex = top.indexInNums2 + 1;
            if (nextIndex < nums2.length) {
                pq.offer(new obj(top.first + nums2[nextIndex], top.first, nums2[nextIndex], nextIndex));
            }
        }

        return lst;
    }
}
