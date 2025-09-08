class Solution {
    boolean nonzero(int n){
        String s =  String.valueOf(n);
        if(s.contains("0")){
            return false;
        }
        return true;
    }
    public int[] getNoZeroIntegers(int n) {
        int i =1 ;
        while(true){
            int a = n-i;
            int b = i;
            if(nonzero(a) && (nonzero(b)))
            {
                return new int[]{a,b};
            }
            i++;

        }
      
    }
}