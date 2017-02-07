#include <iostream>
#include <fstream>
#include <vector>
#include <climits>
#include <unordered_map>
using namespace std;

vector<int> fact;
unordered_map<int, int> memo;

int calc(int N) {
    if (memo.count(N)) return memo[N];
    if (N == 1) return memo[N] = 1;

    int ret = INT_MAX;
    for (int i=1; i<10; i++) {
        if (fact[i] == N) {
            return memo[N] = 1;
        } else if (fact[i] < N) {
            ret = min(ret, 1 + calc(N - fact[i]));
        } else {
            break;
        }
    }

    return memo[N] = ret;
}

int main(int argc, char** argv) {
    freopen(argv[1], "r", stdin);
    fact.resize(10);
    fact[0] = fact[1] = 1;
    for (int i=2; i<10; i++) {
        fact[i] = i * fact[i-1];
    }

    int N;
    while (cin >> N) {
        cout << calc(N) << endl;
    }

    return 0;
}
