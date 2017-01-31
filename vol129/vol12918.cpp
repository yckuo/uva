#include <iostream>
#include <fstream>
using namespace std;

int main(int argc, char** argv) {
    freopen(argv[1], "r", stdin);

    int T;
    cin >> T;
    for (int t=1; t<=T; t++) {
        int n, m;
        cin >> n >> m;
        cout << n * (m - n) + n * (n-1)/2 << endl;
    }

    return 0;
}
