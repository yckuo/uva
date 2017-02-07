#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

int main(int argc, char** argv) {
    freopen(argv[1], "r", stdin);

    int J, R;
    while (cin >> J >> R) {
        
        vector<int> points(J, 0);
        for (int r=0; r<R; r++) {
            for (int j=0; j<J; j++) {
                int point;
                cin >> point;
                points[j] += point;
            }
        }

        int maxpoint = 0;
        for (int j=0; j<J; j++) {
            maxpoint = max(maxpoint, points[j]);
        }

        for (int j=J-1; j>=0; j--) {
            if (points[j] == maxpoint) {
                cout << to_string(j+1) << endl;
                break;
            }
        }
    }

    return 0;
}
