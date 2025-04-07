class Solution {
    public int[] dailyTemperatures(int[] temperatures) {
        int n = temperatures.length;
        Stack<Integer> st = new Stack();
        int [] arr = new int[n];
        for(int  i = n-1; i >= 0; i--){
            
            while(!st.empty() && temperatures[st.peek()] <= temperatures[i]){
                st.pop();
                
            }
            if(st.empty() ){
                arr[i] = 0;
            }
            else{
                arr[i] =  st.peek() -i;
            }
            st.push(i);
        }
        return arr;
    }
}