#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

vector<vector<int>> memo;

vector<int> pascal(int n) {
    if (!memo[n].empty()) return memo[n];
    if (n == 1) {
        return memo[n] = { 1 };
    }

    vector<int> prev = pascal(n-1);
    vector<int> ret = { 1 };
    for (int i=1; i<prev.size(); i++) {
        ret.push_back(prev[i] + prev[i-1]);
    }
    ret.push_back(1);
    return memo[n] = ret;
}

long long calc(int n) {
    if (n == 1) return 1;
    long long sum = 0;
    vector<int> pasc = pascal(n);
    for (int x : pasc) sum += x;
    return 4 * (sum - 1);
}

int main(int argc, char** argv) {
    freopen(argv[1], "r", stdin);
    memo.resize(31);

    int T;
    cin >> T;
    for (int t=0; t<T; t++) {
        int n;
        cin >> n;
        cout << calc(n) << endl;
    }
    return 0;
}
