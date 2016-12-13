#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

class Solution {
public:
    Solution() {
        digits.resize(10);
        digits[0] = { 1, 1, 1, 0, 1, 1, 1 };
        digits[1] = { 0, 0, 1, 0, 0, 1, 0 };
        digits[2] = { 1, 0, 1, 1, 1, 0, 1 };
        digits[3] = { 1, 0, 1, 1, 0, 1, 1 };
        digits[4] = { 0, 1, 1, 1, 0, 1, 0 };
        digits[5] = { 1, 1, 0, 1, 0, 1, 1 };
        digits[6] = { 1, 1, 0, 1, 1, 1, 1 };
        digits[7] = { 1, 0, 1, 0, 0, 1, 0 };
        digits[8] = { 1, 1, 1, 1, 1, 1, 1 };
        digits[9] = { 1, 1, 1, 1, 0, 1, 1 };
    }

    void Run(int s, string num) {
        display(0, s, num);
        display(1, 2, s, num);
        display(3, s, num);
        display(4, 5, s, num);
        display(6, s, num);
        cout << endl;
    }

private:
    // horizontal display
    void display(int seg, int s, string num) {
        string line = "";
        for (char ch : num) {
            if (!line.empty()) line = line + " ";
            line = line + " " + string(s, digits[ch - '0'][seg] ? '-' : ' ') + " ";
        }
        cout << line << endl;
    }

    // vertical display
    void display(int seg1, int seg2, int s, string num) {
        string line = "";
        for (char ch : num) {
            if (!line.empty()) line = line + " ";
            int d = ch - '0';
            line = line + (digits[d][seg1] ? "|" : " ");
            line = line + string(s, ' ');
            line = line + (digits[d][seg2] ? "|" : " ");
        }

        for (int i=0; i<s; i++) cout << line << endl;
    }

    vector<vector<bool>> digits;
};


int main(int argc, char** argv) {
    freopen(argv[1], "r", stdin);
    Solution sol;
    int s;
    string num;
    while (cin >> s >> num && s != 0) {
        sol.Run(s, num);
    }

    return 0;
}
