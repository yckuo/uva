#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

int main(int argc, char** argv) {
    freopen(argv[1], "r", stdin);
    int T;
    cin >> T;
    for (int t=1; t<=T; t++) {
        vector<int> a(4), b(4);
        cin >> a[0] >> a[1] >> a[3] >> a[2];
        cin >> b[0] >> b[1] >> b[3] >> b[2];

        bool possible = false;
        for (int offset=0; offset<4; offset++) {
            if (a[(0+offset)%4] == b[0] && a[(1+offset)%4] == b[1] && a[(2+offset)%4] == b[2] && a[(3+offset)%4] == b[3]) {
                possible = true;
                break;
            }
        }

        cout << "Case #" << to_string(t) << ": ";
        if (possible) cout << "POSSIBLE";
        else cout << "IMPOSSIBLE";
        cout << endl;
    }

    return 0;
}
