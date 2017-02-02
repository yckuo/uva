#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> sums;

pair<int, int> missing(int N) {
    bool last = false;
    if (sums.back() <= N) last = true;
    while (sums.back() <= N) {
        int L = sums.size();
        sums.push_back(sums.back() + L);
    }

    if (last) {
        int L = sums.size();
        return { sums.back() - N, L - 1 };
    } else {
        auto it = upper_bound(sums.begin(), sums.end(), N);
        return { *it - N, (it - sums.begin()) };
    }
}

int main(int argc, char** argv) {
    freopen(argv[1], "r", stdin);
    sums = { 0, 1 };
    
    int N;
    while (cin >> N && N != 0) {
        pair<int, int> ans = missing(N);
        cout << ans.first << " " << ans.second << endl;
    }
    return 0;
}
