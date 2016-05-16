#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

int find(int n, vector<int>& root) {
	if (root[n] == n) return n;
	return root[n] = find(root[n], root);
}

int main(int argc, char** argv) {
	freopen(argv[1], "r", stdin);

	int M, N;
	while (cin >> N >> M && (M != 0 || N != 0)) {

		vector<int> root(N);
		for (int n=0; n<N; n++) root[n] = n;

		for (int m=0; m<M; m++) {
			int K;
			cin >> K;
			if (K <= 0) continue;
			int s1;
			cin >> s1;
			for (int k=1; k<K; k++) {
				int sk;
				cin >> sk;
				root[find(sk, root)] = find(s1, root); // union
			}
		}

		int suspect = find(0, root), count = 0;
		for (int n=0; n<N; n++) {
			if (find(n, root) == suspect) count++;
		}
		cout << count << endl;
	}	

	return 0;
}
