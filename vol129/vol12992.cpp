#include <iostream>
#include <fstream>
using namespace std;

int main(int argc, char** argv) {
    freopen(argv[1], "r", stdin);
    int T;
    cin >> T;
    for (int t=1; t<=T; t++) {
        int N;
        cin >> N;
        cout << "Case #" << to_string(t) << ": ";
        cout << to_string(N * 2 - 1) << endl;
    }
    return 0;
}
