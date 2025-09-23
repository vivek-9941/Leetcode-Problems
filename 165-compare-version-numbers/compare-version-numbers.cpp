class Solution {
public:
    int compareVersion(string version1, string version2) {
        int l = 0, r = 0;

        while (l < version1.size() || r < version2.size()) {
            int first = 0, second = 0;

            // parse number from version1
            if (l < version1.size()) {
                int x = l;
                while (l < version1.size() && version1[l] != '.') l++;
                string one(version1.begin() + x, version1.begin() + l);
                first = stoi(one);
                if (l < version1.size() && version1[l] == '.') l++;
            }

            // parse number from version2
            if (r < version2.size()) {
                int y = r;
                while (r < version2.size() && version2[r] != '.') r++;
                string two(version2.begin() + y, version2.begin() + r);
                second = stoi(two);
                if (r < version2.size() && version2[r] == '.') r++;
            }

            if (first > second) return 1;
            else if (first < second) return -1;
        }
        return 0;
    }
};
