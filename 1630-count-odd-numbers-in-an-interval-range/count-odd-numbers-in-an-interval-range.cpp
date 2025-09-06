class Solution {
public:
    int countOdds(int low, int high) {
    //  7 8 9 10 =-> l-h+1 -> 4 -> 1 odd -> 4/2
    //  7 8 9 10 11 -> 5 > 5/2 +1 ->2 odd
    //  6 7 8 9 10 -> -> 0 odd -> 5 -> 5/2;
        int sum = (high - low +1 )/2;
        if(high %2 == 1 && low%2 == 1)
        {
            sum++;
        }
        return sum;
    }
};