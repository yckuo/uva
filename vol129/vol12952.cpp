#include <iostream>
#include <fstream>
using namespace std;

int main(int argc, char** argv) {
    freopen(argv[1], "r", stdin);

    int a, b;
    while (cin >> a >> b) {
        cout << max(a, b) << endl;
    }

    return 0;
}
