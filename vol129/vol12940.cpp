#include <iostream>
#include <fstream>
#include <string>
using namespace std;

class Solution {
public:
    string next(string cur) {
        int n = cur.size();

        bool all9 = true;
        for (char ch : cur) {
            if (ch != '9') {
                all9 = false;
                break;
            }
        }

        if (all9) {
            return "1" + string(n-1, '0') + "1";
        }

        int left = n/2 - 1, right = (n+1)/2;
        while (left >= 0 && cur[left] == cur[right]) {
            --left;
            ++right;
        }

        if (left < 0) { // already a palindrome
            return add1mid(cur);
        } else {
            bool needToAdd1 = false;
            if (cur[left] < cur[right]) {
                needToAdd1 = true;
            }
                
            for (; right<n; right++, left--) {
                cur[right] = cur[left];
            }

            if (needToAdd1) return add1mid(cur);
            return cur;
        }
    }

    string add1mid(string cur) {
        int n = cur.size(), left = n/2 - 1, right = (n+1)/2;
        int carry = 0;
        if (n % 2 == 1) {
            if (cur[n/2] == '9') {
                carry = 1;
                cur[n/2] = '0';
            } else {
                cur[n/2]++;
            }
        } else {
            if (cur[left] == '9') {
                carry = 1;
                cur[left] = '0';
                cur[right] = '0';
            } else {
                cur[left]++;
                cur[right]++;
                carry = 0;
            }
            left--;
            right++;
        }

        while (left >= 0 && carry > 0) {
            if (cur[left] == '9') {
                carry = 1;
                cur[left] = '0';
                cur[right] = '0';
            } else {
                cur[left]++;
                cur[right]++;
                carry = 0;
            }
            left--;
            right++;
        }

        if (carry > 0) {
            cur = "1" + cur + "1";
        }

        return cur;
    }
};

int main(int argc, char** argv) {
    freopen(argv[1], "r", stdin);
    Solution sol;
    int N;
    string D;
    while (cin >> N >> D) {
        for (int n=0; n<N; n++) {
            D = sol.next(D);
            cout << D << endl;
        }
    }

    return 0;
}
