import java.util.*;

class Pair {
    int key;        // frequency
    String value;   // character as string

    public Pair(String v, int k) {
        key = k;
        value = v;
    }
}

class Solution {
    public String frequencySort(String s) {
        Map<Character, Integer> mpp = new HashMap<>();
        for (int i = 0; i < s.length(); i++) {
            mpp.put(s.charAt(i), mpp.getOrDefault(s.charAt(i), 0) + 1);
        }

        PriorityQueue<Pair> pq = new PriorityQueue<>(
            (a, b) -> {
                if (a.key != b.key)
                    return Integer.compare(b.key, a.key);  // max-heap on frequency
                else
                    return b.value.compareTo(a.value);     // tie-breaker: lexicographically descending
            }
        );

        // Insert map entries into the priority queue
        for (Map.Entry<Character, Integer> entry : mpp.entrySet()) {
            pq.offer(new Pair(String.valueOf(entry.getKey()), entry.getValue()));
        }

        // Build the result
        StringBuilder sb = new StringBuilder();
        while (!pq.isEmpty()) {
            Pair top = pq.poll();
            sb.append(top.value.repeat(top.key));
        }

        return sb.toString();
    }
}
