#include <iostream>
#include <fstream>
#include <string>

using namespace std;

// Expected number of inversions in bubble sort.
// By math it is n(n-1)/4
int main(int argc, char** argv)
{
	freopen(argv[1], "r", stdin);

	int T;
	cin >> T;
	for (int t=1; t<=T; t++)
	{
		long n, p, q;
		cin >> n;
		p = n * (n-1);
		q = 4;

		cout << "Case " << t << ": ";

		if (p % 4 == 0)
		{
			cout << p/4;
		}
		else
		{
			if (p%2 == 0)
			{
				p = p/2;
				q = 2;
			}
			cout << p << "/" << q;
		}
		cout << endl;
	}
	

	return 0;
}
