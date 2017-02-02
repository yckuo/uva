#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

int main(int argc, char ** argv) {
    freopen(argv[1], "r", stdin);
    int T;
    cin >> T;
    for (int t=1; t<=T; t++) {
        int N, L;
        cin >> N >> L;
        vector<int> mangobytypes(N);

        int summango = 0;
        for (int n=0; n<N; n++) {
            cin >> mangobytypes[n];
            summango += mangobytypes[n];
        }

        bool fail = false;
        for (int n=0; n<N; n++) {
            int limit;
            cin >> limit;
            if (limit < mangobytypes[n]) {
                fail = true;
                break;
            }
        }

        cout << "Case " << to_string(t) << ": ";
        if (fail || summango > L) cout << "No";
        else cout << "Yes";
        cout << endl;
    }
    return 0;
}
