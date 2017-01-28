#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

class Solution {
public:
    // 0-1 knapsack
    int maxval(vector<int>& prices, vector<int>& weights, vector<int>& carry) {
        
    }
};

int main(int argc, char** argv) {
    freopen(argv[1], "r", stdin);
    int T;
    cin >> T;
    Solution sol;
    for (int t=0; t<T; t++) {
        int N;
        cin >> N;
        vector<int> prices(N), weights(N);
        for (int n=0; n<N; n++) {
            cin >> prices[n] >> weights[n];
        }
        int G;
        cin >> G;
        vector<int> carry(G);
        for (int g=0; g<G; g++) {
            cin >> carry[g];
        }
        cout << sol.maxval(prices, weights, carry) << endl;
    }
    return 0;
}
