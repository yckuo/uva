#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

class Solution {
public:
    void replace(int &x1, int &y1, int x2, int y2) {
        if (x2 > x1 || x2 == x1 && y2 > y1) {
            x1 = x2;
            y1 = y2;
        }
    }

    int solve(string s, vector<bool>& special) {
        int N = s.size();
        vector<vector<int>> score(N, vector<int>(N, 0)), dp(N, vector<int>(N, 0));
        
        for (int i=0; i<N; i++) {
            dp[i][i] = 1;
            score[i][i] = special[i] ? 1 : 0;
        }

        for (int i=0; i+1<N; i++) {
            dp[i][i+1] = s[i] == s[i+1] ? 2 : 1;
            score[i][i+1] = s[i] == s[i+1] ? score[i][i] + score[i+1][i+1] : max(score[i][i], score[i+1][i+1]);
        }

        for (int len=3; len<=N; len++) {
            for (int left=0; left+len-1<N; left++) {
                int right = left + len - 1;

                if (s[left] == s[right]) {
                    replace(score[left][right], dp[left][right], score[left+1][right-1] + score[left][left] + score[right][right], dp[left+1][right-1] + 2);
                }

                // do not use left
                replace(score[left][right], dp[left][right], score[left+1][right], dp[left+1][right]);

                // do not use right
                replace(score[left][right], dp[left][right], score[left][right-1], dp[left][right-1]);
            }
        }

        return dp[0][N-1];
    
    }
};

int main(int argc, char** argv) {
    freopen(argv[1], "r", stdin);
    Solution sol;
    string s;
    while (cin >> s) {
        int N;
        cin >> N;
        vector<bool> special(s.size(), false);
        for (int n=0; n<N; n++) {
            int p;
            cin >> p;
            special[p-1] = true;
        }
        cout << sol.solve(s, special) << endl;
    }
    return 0;
}
