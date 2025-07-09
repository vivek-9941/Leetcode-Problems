class Solution {
    public String largestOddNumber(String num) {
        int ind = -1;
        int i = num.length()-1;
        while(i >=0){
            char ch  = num.charAt(i);
            if((ch - '0')% 2==1  ){

                ind = i;
                break;
            }
            i--;
        }
        if(ind == -1)return "";
        return num.substring(0,ind+1);
    }
}