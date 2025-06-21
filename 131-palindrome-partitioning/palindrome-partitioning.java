class Solution {
    boolean check(String s) {
        StringBuilder sb = new StringBuilder(s);
        if (s.equals(sb.reverse().toString()))
            return true;
        return false;
    }

    void solve(String s, int start, List<List<String>> lst, int index, String str, List<String> ds) {
        if (s.length() == index) {
            lst.add(new ArrayList(ds));
            return;
        }

        for (int i = index; i < s.length(); i++) {
            if (check(s.substring(start, i+1))) {
                ds.add(s.substring(start, i+1));
                solve(s, i + 1, lst, i + 1, str, ds);
                ds.remove(ds.size()-1);
            }

        }
    }

    public List<List<String>> partition(String s) {
        List<List<String>> lst = new ArrayList<>();
        solve(s, 0, lst, 0, "", new ArrayList());
        return lst;
    }
}