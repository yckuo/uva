#include <iostream>
#include <fstream>

using namespace std;

int main(int argc, char** argv)
{
	freopen(argv[1], "r", stdin);

	int T;
	cin >> T;
	for (int t=1; t<=T; t++)
	{
		// reading the input
		long N;
		cin >> N;
		long D[100000], base, next;
		cin >> base;
		D[0] = base;
		for (long n=1; n<N; n++)
		{
			cin >> next;
			D[n] = next - base;
			base = next;
		}

		// debug
		// for (long n=0; n<N; n++)
		// {
		// 	cout << D[n] << " ";
		// }
		// cout << endl;

		// dynamic programming
		long ans[100000];
		ans[N-1] = D[N-1];	
		for (long n=N-2; n>=0; n--)
		{
			// find ans[n] based on ans[n+1]
			if (D[n] < ans[n+1])
			{
				ans[n] = ans[n+1];
			}
			else if (D[n] == ans[n+1])
			{
				ans[n] = ans[n+1] + 1;
			}
			else
			{
				ans[n] = D[n];
			}
		}
		cout << "Case " << t << ": " << ans[0] << endl;
	}

	return 0;
}
