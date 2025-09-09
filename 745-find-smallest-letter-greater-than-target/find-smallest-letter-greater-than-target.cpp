class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char target) {
        int n = letters.size();
        int l =  0;
        int r = n-1;
        while( l <= r){
            int mid = (l+r)/2;
            if(letters[mid] <= target )l= mid +1;
            else r= mid- 1;
        }
        if(l == n )return letters[0]; 
        return letters[l];
    }
};