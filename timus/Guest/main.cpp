#include <iostream>
#include <set>
using namespace std;


int main() {
    size_t n, sumi = 0, count;
    cin >> n;
    count = n * (n - 1);
    multiset<long> coordX, coordY;
    long arrX[n], arrY[n];
    long x, y;
    for (size_t i = 0; i < n; i++) {
        cin >> x >> y;
        coordX.insert(x);
        coordY.insert(y);
    }
    long countNum = 0;
    for (long i : coordX) {
        arrX[countNum] = i;
        countNum++;
    }
    countNum = 0;
    for (long i : coordY) {
        arrY[countNum] = i;
        countNum++;
    }
    for (long i = n - 1; i > 0; i--) {
        sumi += (arrX[i] - arrX[i - 1] + arrY[i] - arrY[i - 1]) * (n - i) * i * 2;
    }
    cout << sumi / count;
    return 0;
}