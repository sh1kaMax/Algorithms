#include <iostream>

using namespace std;

int main() {
    long start {1}, finish, n, x, y, z, maxStart {1}, maxFinish {1};
    cin >> n;
    for (long i {1}; i <= n; i++) {
        cin >> x;
        if ((x == y && x == z) || i == n) {
            if (i != n || (x == y && x == z && i == n)) {
                finish = i - 1;
            } else {
                finish = i;
            }
            if (maxFinish - maxStart < finish - start) {
                maxStart = start;
                maxFinish = finish;
            }
            start = finish;
        }
        z = y;
        y = x;
    }

    cout << maxStart << " " << maxFinish;
    return 0;
}
