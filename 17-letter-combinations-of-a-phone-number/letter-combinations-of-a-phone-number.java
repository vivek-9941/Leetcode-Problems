class Solution {
    void solve(Map<Character,String> mpp , String digits , int index ,List<String > lst ,String s,int digitsindex){
        if(s.length() == digits.length()){
            lst.add(s);
            return;
        }
        String current  = mpp.get(digits.charAt(digitsindex));
        for(int  i  = index ; i < current.length(); i++){
            solve(mpp, digits, 0 , lst , s + current.charAt(i), digitsindex +1 );
        }

    }
    public List<String> letterCombinations(String digits) {
        Map<Character, String> mpp = new HashMap<>();
        mpp.put('2' , "abc");
        mpp.put('3' , "def");
        mpp.put('4' , "ghi");
        mpp.put('5' , "jkl");
        mpp.put('6' , "mno");
        mpp.put('7' , "pqrs");
        mpp.put('8' , "tuv");
        mpp.put('9' , "wxyz");
        List<String > lst  = new ArrayList<>();
        if(digits.length()== 0)return lst;
        solve(mpp, digits , 0 ,lst , "",0);
        return lst;
    }
}