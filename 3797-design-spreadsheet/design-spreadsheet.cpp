class Spreadsheet {
    int n;
    vector<vector<int>> hash; // will initialize in constructor
public:
    Spreadsheet(int rows) {
        n = rows;
        hash.assign(n + 1, vector<int>(26, 0)); // 1-based row indexing
    }
    
    void setCell(string cell, int value) {
        char col = cell[0];
        string rest(cell.begin() + 1, cell.end());
        int rowno = stoi(rest);
        hash[rowno][col - 'A'] = value;
    }
    
    void resetCell(string cell) {
        char col = cell[0];
        string rest(cell.begin() + 1, cell.end());
        int rowno = stoi(rest);
        hash[rowno][col - 'A'] = 0;
    }
    
    int getValue(string formula) {
        string part1 = "", part2 = "";
        int i;
        for (i = 1; i < formula.size(); i++) {
            if (formula[i] == '+') break;
            part1 += formula[i];
        }
        i++;
        for (int j = i; j < formula.size(); j++) {
            part2 += formula[j];
        }

        int firstcompute, secondcompute;

        // compute part1
        if (isalpha(part1[0])) {
            char col = part1[0];
            string rest(part1.begin() + 1, part1.end());
            int rowno = stoi(rest);
            firstcompute = hash[rowno][col - 'A'];
        } else {
            firstcompute = stoi(part1);
        }

        // compute part2
        if (isalpha(part2[0])) {
            char col = part2[0];
            string rest(part2.begin() + 1, part2.end());
            int rowno = stoi(rest);
            secondcompute = hash[rowno][col - 'A'];
        } else {
            secondcompute = stoi(part2);
        }

        return firstcompute + secondcompute;
    }
};
