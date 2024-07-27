#include <iostream>
using namespace std;

int main() {
    long n, k, left, right, distance, cow;
    long long allDistance, previousCow, nowCow;
    cin >> n >> k;
    long long cows[n];
    for (long i {0}; i < n; i++) {
        cin >> cows[i];
    }
    left  = 0;
    right = cows[n - 1];
    while (left < right - 1) {
        distance = (right + left) / 2;
        cow = 1;
        allDistance = 0;
        previousCow = cows[0];
        for (long i {1}; i < n; i++) {
            nowCow = cows[i];
            allDistance += nowCow - previousCow;
            if (allDistance >= distance) {
                cow++;
                allDistance = 0;
            }
            previousCow = nowCow;
        }
        if (cow < k) {
            right = distance;
        } else {
            left = distance;
        }
    }
    cout << right - 1;
    return 0;
}
