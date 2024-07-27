#include <iostream>
#include <cmath>

using namespace std;

int main() {
    long long a, b, c, d;
    long long k;
    double res;
    cin >> a >> b >> c >> d >> k;
    if (k > 1000) {
        if ((a * b - c) > a) {
            res = static_cast<double>(d);
        } else if ((a * b - c) < a) {
            res = 0;
        } else {
            res = static_cast<double>(a);
        }
    } else {
        if ((a * b - c) > d) {
            a = d;
            k--;
        }
        res = b == 1 ? a - c * k : a + ((a * b - c) - a) * (1 + (b * (pow(b, k - 1) - 1)) / (b - 1));
    }
    if (res >= static_cast<double>(d)) {
        cout << d;
    } else if (res <= 0) {
        cout << 0;
    } else {
        cout << res;
    }
    return 0;
}
