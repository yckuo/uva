#include <iostream>
#include <fstream>
using namespace std;

string compare(string i1, string i2) {
    if (i1.size() > i2.size()) return "Bigger";
    else if (i1.size() < i2.size()) return "Smaller";
    else if (i1 < i2) return "Smaller";
    else if (i1 > i2) return "Bigger";
    else return "Same";
}

int main(int argc, char** argv) {
    freopen(argv[1], "r", stdin);
    string n1, n2;
    int i = 0;
    while (cin >> n1 >> n2) {
        cout << "Case " << ++i << ": ";
        int idx = 0;
        while (idx < n1.size() && n1[idx] != '.') idx++;
        string i1 = n1.substr(0, idx), p1 = n1.substr(idx+1);
        idx = 0;
        while (idx < n2.size() && n2[idx] != '.') idx++;
        string i2 = n2.substr(0, idx), p2 = n2.substr(idx+1);

        if (i1 != i2) {
            cout << compare(i1, i2);
        } else {
            if (p1.size() > p2.size()) {
                int diff = p1.size() - p2.size();
                for (int i=0; i<diff; i++) p2 = p2 + "0";
            } else if (p2.size() > p1.size()) {
                int diff = p2.size() - p1.size();
                for (int i=0; i<diff; i++) p1 = p1 + "0";
            }
            
            cout << compare(p1, p2);
        }

        cout << endl;
    }

    return 0;
}
