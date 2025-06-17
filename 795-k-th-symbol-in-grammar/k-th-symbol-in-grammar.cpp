class Solution {
    int solve(int n , int k , int mid){
       if(n == 1 && k ==1 )return 0;
        if(k <= mid){
            return solve(n-1, k ,  mid/2);
        }
        else{
            return !solve(n-1 , k -mid, mid/2);
        }
    }
public:
    int kthGrammar(int n, int k) {
       int len = pow(2,n-1);
       int mid  = len/2;
       return solve(n, k, mid);

    }
};