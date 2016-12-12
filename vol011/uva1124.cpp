#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main(int argc, char** argv) {
	freopen(argv[1], "r", stdin);
	string line;
	while (getline(cin, line)) {
		cout << line << endl;
	}

	return 0;
}

