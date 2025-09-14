class Solution {
    string tovowel(string s) {
        for (auto &w : s) {
            if (w == 'a' || w == 'e' || w == 'i' || w == 'o' || w == 'u' ||
                w == 'A' || w == 'E' || w == 'I' || w == 'O' || w == 'U') {
                w = '*';
            }
        }
        return s;
    }

    string to_lowercase(string s) {   // renamed to avoid conflict
        for (auto &c : s) {
            c = ::tolower(c);   // explicitly use global tolower from <cctype>
        }
        return s;
    }

public:
    vector<string> spellchecker(vector<string>& wordlist, vector<string>& queries) {
        unordered_set<string> exact(wordlist.begin(), wordlist.end());
        unordered_map<string, string> caselist, vowels;

        for (auto s : wordlist) {
            string lowerc = to_lowercase(s);
            string vowelc = tovowel(to_lowercase(s));
            if (!caselist.count(lowerc)) caselist[lowerc] = s;
            if (!vowels.count(vowelc)) vowels[vowelc] = s;
        }

        vector<string> result;
        for (auto q : queries) {
            if (exact.count(q)) {
                result.push_back(q);
            } else {
                string lower = to_lowercase(q);
                string vo = tovowel(to_lowercase(q));
                if (caselist.count(lower)) result.push_back(caselist[lower]);
                else if (vowels.count(vo)) result.push_back(vowels[vo]);
                else result.push_back("");
            }
        }
        return result;
    }
};
