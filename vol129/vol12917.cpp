#include <iostream>
#include <fstream>
using namespace std;

class Solution {
public:
    string calc(int P, int H, int O) {
        if (H > O - P) return "Hunters win!";
        return "Props win!";
    }
};

int main(int argc, char** argv) {
    freopen(argv[1], "r", stdin);
    Solution sol;
    int P, H, O;
    while (cin >> P >> H >> O) {
        cout << sol.calc(P, H, O) << endl;
    }
    return 0;
}
