#include <iostream>
#include <fstream>
#include <string>
using namespace std;

#define MAX 5000

int main(int argc, char** argv)
{
    freopen(argv[1], "r", stdin);

    string word;
    int qnum[MAX], period_original[MAX], count = 0;
    while (cin >> word && word == "Register") {
        cin >> qnum[count] >> period_original[count];
        count++;
    }

    int period[MAX];
    for (int c=0; c<count; c++) {
        period[c] = period_original[c];
    }

    int K;
    cin >> K;
    for (int k=0; k<K; k++) {
        // find the minimum across all periods.
        int min=0;
        for (int n=1; n<count; n++) {
            if (period[n] < period[min] || (period[n] == period[min] && qnum[n] < qnum[min])) {
                min = n;
            }
        }
        cout << qnum[min] << endl;
        period[min] += period_original[min];
    }

    return 0;
}
