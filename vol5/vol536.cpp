#include <iostream>
#include <fstream>
#include <string>
using namespace std;

string findpostorder(string preord, string inord) {
	if (preord.empty()) return "";

	int N = preord.size();
	char root = preord[0];
	int i=0;
	for (; i<N; i++) {
		if (inord[i] == root) {
			break;
		}
	}

	// inord[i] == root
	// 0, ..., i-1 left tree
	// i+1 ..., N-1 right tree
	
	string left = findpostorder(preord.substr(1, i), inord.substr(0, i));
	string right = findpostorder(preord.substr(i+1, N-i-1), inord.substr(i+1, N-i-1));
	return left + right + root;
}

int main(int argc, char** argv) {
	freopen(argv[1], "r", stdin);
	string preord, inord;
	while (cin >> preord >> inord) {
		cout << findpostorder(preord, inord) << endl;
	}

	return 0;
}
