class Solution {
public:
    void solve(vector<string> &arr , int n , int o ,int c,string str){
        if(o ==0 && c ==0 ){
            arr.push_back(str);
            return ;
        }
        if(o > 0){
           
            solve(arr,n,o-1,c,str+'(');

        }
        if(c>o){
            
            solve(arr,n,o,c-1,str+')');

        }
    }
    vector<string> generateParenthesis(int n) {
        vector<string> arr;
        int o =n,c=n;
        string str = "";
        solve(arr, n, o,c,str);

        return arr;
    }
};