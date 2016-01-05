#include <iostream>
#include <fstream>
#include <string>

#define MAX2(a,b) ((a)>(b)?(a):(b))

using namespace std;

int main(int argc, char** argv)
{
	freopen(argv[1], "r", stdin);

	string x, y;
	while (cin >> x >> y)
	{
		if (x == "0" && y == "0") return 0;

		int xlen = x.length();
		int ylen = y.length();

		int carry = 0, sum = 0;
		for (int d=0; d<MAX2(xlen,ylen); d++)
		{
			int xind = xlen - 1 - d;
			int yind = ylen - 1 - d;
			int xnum = xind < 0 ? 0 : x[xind] - '0';
			int ynum = yind < 0 ? 0 : y[yind] - '0';
			if (carry + xnum + ynum > 9)
			{
				carry = 1;
				sum++;
			}
			else
			{
				carry = 0;
			}
		}

		if (sum == 0)
		{
			cout << "No carry operation." << endl;;
		}
		else if (sum == 1)
		{
			cout << sum << " carry operation." << endl;;
		}
		else
		{
			cout << sum << " carry operations." << endl;
		}
	}


	return 0;
}
