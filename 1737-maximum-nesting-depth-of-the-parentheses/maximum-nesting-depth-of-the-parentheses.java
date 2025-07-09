class Solution {
    public int maxDepth(String s) {
        int cnt  =0;
        int maxi = 0;
        for(int i =0 ; i  < s.length(); i++){
            if(s.charAt(i) == '(')cnt++;
            else if(s.charAt(i) == ')'){
                maxi = Math.max(maxi,cnt);
                cnt--;
            }
        }
        return maxi;
    }
}