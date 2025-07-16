class Solution {
public:
    string removeKdigits(string num, int k) {
        int n = num.size();
        stack<char> st;
        for (int i = 0; i < n; i++) {
            while (!st.empty() && st.top() - '0' > num[i] - '0' && k > 0) {
                st.pop();
                k--;
            }
            st.push(num[i]);
        }
        while (k--) {
            st.pop();
        }
        if (st.empty())
            return "0";
        string res = "";
        while (!st.empty()) {
            res += st.top();
            st.pop();
        }
        //  while(res.size()!= 0 && res.back() == '0')res.pop_back();

        if (res.size() == 0)
            return "";
        reverse(res.begin(), res.end());      // Step 1: get actual number
        while (!res.empty() && res[0] == '0') // Step 2: remove leading zeros
            res.erase(res.begin());

        if (res.empty())
            return "0"; // Step 3: handle empty result

        return res;
    }
};