#include <iostream>
#include <fstream>
#include <string>
using namespace std;

#define MAX 10000

int main(int argc, char** argv)
{
    freopen(argv[1], "r", stdin);

    // find all primes < 10000.
    int prime[MAX], prime_count = 0;
    for (int candidate=2; candidate<MAX; candidate++) {
        bool isPrime = true;
        for (int attempt_factor=2; attempt_factor<=candidate/2; attempt_factor++) {
            if (candidate % attempt_factor == 0) {
                isPrime = false;
                break;
            }
        }
        if (isPrime) {
            prime[prime_count++] = candidate;
        }
    }

    // 
    for (int c=0; c<prime_count; c++) {
        cout << prime[c] << ", ";
    }

    return 0;
}
