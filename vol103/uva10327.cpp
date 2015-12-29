#include <iostream>
#include <fstream>
#include <string>

#define NMAX 1000

using namespace std;

int main(int argc, char **argv)
{
	// reading input
	freopen(argv[1], "r", stdin);

	int N, I[NMAX];
	while (cin >> N)
	{
		int count = 0;
		for (int n=0; n<N; n++)
		{
			cin >> I[n];
		}

		// bubble sort
		for (int i=N-1; i>0; i--)
		{
			for (int j=0; j<i; j++)
			{
				if (I[j] > I[j+1])
				{
					// swap I[j] and I[j+1]
					int temp = I[j];
					I[j] = I[j+1];
					I[j+1] = temp;
					count++;
				}
			}
		}

		// output Minimum exchange operations : 0
		cout << "Minimum exchange operations : " << count << endl;
	}

	return 0;
}
