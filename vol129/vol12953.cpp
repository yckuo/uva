#include <iostream>
#include <fstream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <queue>
#include <algorithm>
using namespace std;

class Solution {
public:

    static bool compare(pair<string, int>& p1, pair<string, int>& p2) {
        return p1.first < p2.first;
    }

    vector<pair<string, int>> solve(vector<vector<string>>& matrix, vector<int>& rowsums, vector<int>& colsums, int L, int W) {
        
        unordered_map<string, int> solved;
        bool finished = false;
        while (!finished) {
            queue<string> q;
            finished = true;
            for (int l=0; l<L; l++) {
                
                int sum = rowsums[l];
                unordered_map<string, int> count;
                for (int w=0; w<W; w++) {
                    string entry = matrix[l][w];
                    if (solved.count(entry)) {
                        sum -= solved[entry];
                    } else {
                        count[entry]++;
                    }
                }

                if (count.size() == 1) {
                    
                    string entry = count.begin()->first;
                    solved[entry] = sum /count[entry];
                    finished = false;
                }
            }

            for (int w=0; w<W; w++) {

                int sum = colsums[w];
                unordered_map<string, int> count;
                for (int l=0; l<L; l++) {
                    string entry = matrix[l][w];
                    if (solved.count(entry)) {
                        sum -= solved[entry];
                    } else {
                        count[entry]++;
                    }
                }

                if (count.size() == 1) {
                    
                    string entry = count.begin()->first;
                    solved[entry] = sum/count[entry];
                    finished = false;
                }
            }
        }

        vector<pair<string, int>> ret;
        for (auto it : solved) {
            ret.push_back({it.first, it.second});
        }

        sort(ret.begin(), ret.end(), compare);
        return ret;
    }
};

int main(int argc, char** argv) {
    freopen(argv[1], "r", stdin);
    Solution sol;
    int L, W;
    while (cin >> L >> W) {
        vector<vector<string>> matrix(L, vector<string>(W));
        vector<int> rowsums(L), colsums(W);
        for (int l=0; l<L; l++) {
            for (int w=0; w<W; w++) {
                cin >> matrix[l][w];
            }
            cin >> rowsums[l];
        }
        for (int w=0; w<W; w++) {
            cin >> colsums[w];
        }

        vector<pair<string, int>> ans = sol.solve(matrix, rowsums, colsums, L, W);
        for (pair<string, int> p : ans) {
            cout << p.first << " " << to_string(p.second) << endl;
        }
    }

    return 0;
}

