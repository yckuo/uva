#include <iostream>
#include <fstream>
#include <cmath>
using namespace std;

class Solution {
public:
    int Ways(int n) {
        int ret = 0;
        for (int d=1; d<=1000; d*=10) {
            int cur = (n / d) % 10;
            for (int next=0; next<10; next++) {
                if (cur == next) continue;
                if (d == 1000 && next == 0) continue;
                int m = n - cur * d + next * d;
                int m2 = sqrt(m);
                if ((m2 * m2) == m) ret++;
            }
        }
        return ret;
    }
};

int main(int argc, char** argv) {
    freopen(argv[1], "r", stdin);
    Solution sol;
    int T;
    cin >> T;
    for (int t=0; t<T; t++) {
        int n;
        cin >> n;
        cout << "Case " << to_string(t+1) << ": " << sol.Ways(n) << endl;
    }
    return 0;
}
