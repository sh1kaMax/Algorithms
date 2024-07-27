#include <iostream>
#include <vector>
#include <cmath>

using namespace std;
long long count = 1;

void fill(int n, int x, int y, vector<vector<long long>>& board, bool check, int xLeftCorn, int yLeftCorn) {
    int half = pow(2, n - 1);
    if (n == 1 && !check) {
        board[xLeftCorn + x - 1][yLeftCorn + y - 1] = 0;
        fill(1, x, y, board, true, xLeftCorn, yLeftCorn);
        return;
    }
    if (x <= half && y <= half) {
        board[xLeftCorn + half - 1][yLeftCorn + half] = count;
        board[xLeftCorn + half][yLeftCorn + half - 1] = count;
        board[xLeftCorn + half][yLeftCorn + half] = count;
        count++;
        if (!check) {
            fill(n - 1, x, y, board, false, xLeftCorn, yLeftCorn);
            fill(n - 1, half, 1, board, true, xLeftCorn, yLeftCorn + half);
            fill(n - 1, 1, half, board, true, xLeftCorn + half, yLeftCorn);
            fill(n - 1, 1, 1, board, true, xLeftCorn + half, yLeftCorn + half);
        } else {
            if (n != 1) {
                fill(n - 1, x, y, board, true, xLeftCorn, yLeftCorn);
                fill(n - 1, half, 1, board, true, xLeftCorn, yLeftCorn + half);
                fill(n - 1, 1, half, board, true, xLeftCorn + half, yLeftCorn);
                fill(n - 1, 1, 1, board, true, xLeftCorn + half, yLeftCorn + half);
            } else {
                return;
            }
        }
    } else if (x <= half && y > half) {
        board[xLeftCorn + half - 1][yLeftCorn + half - 1] = count;
        board[xLeftCorn + half][yLeftCorn + half - 1] = count;
        board[xLeftCorn + half][yLeftCorn + half] = count;
        count++;
        if (!check) {
            fill(n - 1, x, y - half, board, false, xLeftCorn, yLeftCorn + half);
            fill(n - 1, half, half, board, true, xLeftCorn, yLeftCorn);
            fill(n - 1, 1, half, board, true, xLeftCorn + half, yLeftCorn);
            fill(n - 1, 1, 1, board, true, xLeftCorn + half, yLeftCorn + half);
        } else {
            if (n != 1) {
                fill(n - 1, x, y - half, board, true, xLeftCorn, yLeftCorn + half);
                fill(n - 1, half, half, board, true, xLeftCorn, yLeftCorn);
                fill(n - 1, 1, half, board, true, xLeftCorn + half, yLeftCorn);
                fill(n - 1, 1, 1, board, true, xLeftCorn + half, yLeftCorn + half);
            } else {
                return;
            }
        }
    } else if(x > half && y <= half) {
        board[xLeftCorn + half - 1][yLeftCorn + half - 1] = count;
        board[xLeftCorn + half - 1][yLeftCorn + half] = count;
        board[xLeftCorn + half][yLeftCorn + half] = count;
        count++;
        if (!check) {
            fill(n - 1, x - half, y, board, false, xLeftCorn + half, yLeftCorn);
            fill(n - 1, half, half, board, true, xLeftCorn, yLeftCorn);
            fill(n - 1, half, 1, board, true, xLeftCorn, yLeftCorn + half);
            fill(n - 1, 1, 1, board, true, xLeftCorn + half, yLeftCorn + half);
        } else {
            if (n != 1) {
                fill(n - 1, x - half, y, board, true, xLeftCorn + half, yLeftCorn);
                fill(n - 1, half, half, board, true, xLeftCorn, yLeftCorn);
                fill(n - 1, half, 1, board, true, xLeftCorn, yLeftCorn + half);
                fill(n - 1, 1, 1, board, true, xLeftCorn + half, yLeftCorn + half);
            } else {
                return;
            }
        }
    } else {
        board[xLeftCorn + half - 1][yLeftCorn + half - 1] = count;
        board[xLeftCorn + half - 1][yLeftCorn + half] = count;
        board[xLeftCorn + half][yLeftCorn + half - 1] = count;
        count++;
        if (!check) {
            fill(n - 1, x - half, y - half, board, false, xLeftCorn + half, yLeftCorn + half);
            fill(n - 1, half, half, board, true, xLeftCorn, yLeftCorn);
            fill(n - 1, half, 1, board, true,  xLeftCorn, yLeftCorn + half);
            fill(n - 1, 1, half, board, true, xLeftCorn + half, yLeftCorn);
        } else {
            if (n != 1) {
                fill(n - 1, x - half, y - half, board, true, xLeftCorn + half, yLeftCorn + half);
                fill(n - 1, half, half, board, true, xLeftCorn, yLeftCorn);
                fill(n - 1, half, 1, board, true,  xLeftCorn, yLeftCorn + half);
                fill(n - 1, 1, half, board, true, xLeftCorn + half, yLeftCorn);
            } else {
                return;
            }
        }
    }
}

int main() {
    int n, x, y;
    cin >> n >> x >> y;

    vector<vector<long long>> board(1 << n, vector<long long>(pow(2, n), -1));

    fill(n, x, y, board, false, 0, 0);

    for (int i = 0; i < pow(2, n); i++) {
        for (int j = 0; j < pow(2, n); j++) {
            cout << board[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}
