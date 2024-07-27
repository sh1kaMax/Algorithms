#include <iostream>
using namespace std;

int main() {
    long n, k;
    long long sumi {0}, maxi {0};
    cin >> n;
    for (long i {0}; i < n; i++) {
        cin >> k;
        if (k >= 0) {
            sumi += k;
        } else {
            if ((sumi + k) > 0) {
                maxi = max(sumi, maxi);
                sumi += k;
            } else {
                maxi = max(sumi, maxi);
                sumi = 0;
            }
        }
    }
    maxi = max(sumi, maxi);
    cout << maxi;
    return 0;
}
