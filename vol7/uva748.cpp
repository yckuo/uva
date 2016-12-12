#include <iostream>
#include <fstream>
#include <limits>
#include <string>
using namespace std;

class Solution {
public:
    string Pow(string base, int exp) {
        if (exp == 0) return "1.0";
        if (exp == 1) return base;
        string b2 = Mult(base, base);
        return Mult(Pow(b2, exp/2), Pow(base, exp%2));
    }
private:
    string Mult(string a, string b) {
        int dot1 = Dot(a), dot2 = Dot(b), d1 = a.size() - dot1 - 1, d2 = b.size() - dot2 - 1;
        a = a.substr(0, dot1) + a.substr(dot1+1);
        b = b.substr(0, dot2) + b.substr(dot2+1);

        string ret = "";
        for (int i=0; i<b.size(); i++) {
            ret = ret + "0";
            string tmp = Mult(a, b[i] - '0');
            ret = AddNoDot(ret, tmp);
        }

        int N = ret.size();
        string p1 = ret.substr(0, N - d1 - d2), p2 = ret.substr(N - d1 - d2);
        return p1 + "." + p2;
    }

    string Mult(string a, int b) {
        string ret = "";
        int carry = 0;
        for (int i=a.size()-1; i>=0; i--) {
            if (a[i] == '.') {
                ret = "." + ret;
            } else {
                carry += b * (a[i] - '0');
                ret = to_string(carry % 10) + ret;
                carry /= 10;
            }
        }
        if (carry > 0) ret = to_string(carry % 10) + ret;
        return ret;
    }

    string AddNoDot(string a, string b) {
        string ret = "";
        int i1 = a.size() - 1, i2 = b.size() - 1, carry = 0;
        while (i1 >= 0 || i2 >= 0) {
            int v1 = 0, v2 = 0;
            if (i1 >= 0) v1 = a[i1--] - '0';
            if (i2 >= 0) v2 = b[i2--] - '0';
            carry += v1 + v2;
            ret = to_string(carry % 10) + ret;
            carry /= 10;
        }
        if (carry > 0) ret = to_string(carry % 10) + ret;
        return ret;
    }

    int Dot(string a) {
        int dot = 0;
        while (dot < a.size() && a[dot] != '.') dot++;
        return dot;
    }
};

int main(int argc, char** argv) {
    freopen(argv[1], "r", stdin);
    Solution sol;
    string base;
    int exp;
    while (cin >> base >> exp) {
        string res = sol.Pow(base, exp);
        while (res[0] == '0') res = res.substr(1);
        int len = res.size();
        while (len > 0 && res[len-1] == '0') len--;
        cout << res.substr(0, len) << endl;
    }

    return 0;
}
    
