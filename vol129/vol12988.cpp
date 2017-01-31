#include <iostream>
#include <fstream>
#include <vector>
#include <string>
using namespace std;

class Sudoku4 {
public:
    void Read(istream& stream) {
        board.clear();
        board.resize(4);
        for (int r=0; r<4; r++) {
            for (int c=0; c<4; c++) {
                char ch;
                stream >> ch;
                board[r].push_back(ch);
            }
        }
    }

    void Solve() {
        backtrack(0, 0);
    }

    bool backtrack(int r, int c) {
        if (c == 4) {
            c = 0;
            ++r;
        }
        if (r == 4) return true;

        if (board[r][c] != '*') return backtrack(r, c+1);

        for (char v='1'; v<='4'; v++) {
            if (!check(r, c, v)) continue;

            board[r][c] = v;
            if (backtrack(r, c+1)) return true;
            board[r][c] = '*';
        }

        return false;
    }

    void Print() {
        for (int r=0; r<4; r++) {
            cout << board[r] << endl;
        }
    }

private:
    vector<string> board;

    bool check(int row, int col, char v) {

        for (int c=0; c<4; c++) {
            if (board[row][c] == v) return false;
        }

        for (int r=0; r<4; r++) {
            if (board[r][col] == v) return false;
        }

        int br = row / 2, bc = col / 2;
        for (int sr=0; sr<2; sr++) {
            for (int sc=0; sc<2; sc++) {
                if (board[br*2+sr][bc*2+sc] == v) return false;
            }
        }

        return true;
    }
};

int main(int argc, char** argv) {
    freopen(argv[1], "r", stdin);

    int T;
    cin >> T;
    for (int t=1; t<=T; t++) {
        Sudoku4 sudoku;
        sudoku.Read(cin);
        sudoku.Solve();
        cout << "Case #" << to_string(t) << ":" << endl;
        sudoku.Print();
    }
    return 0;
}
