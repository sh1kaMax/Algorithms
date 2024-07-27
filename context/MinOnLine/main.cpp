#include <iostream>
#include <queue>
#include <map>
using namespace std;

int main() {
    map<long, long> minMap;
    long n;
    int k;
    cin >> n >> k;
    long numbers[n];
    for (long i = 0; i < n; i++) {
        cin >> numbers[i];
    }
    for (long i = 0; i < n; i++) {
        if (i > k - 1) {
            cout << minMap.begin()->first << " ";
            if (minMap[numbers[i - k]] - 1 == 0) {
                minMap.erase(numbers[i - k]);
            } else {
                minMap[numbers[i - k]]--;
            }
        }
        minMap[numbers[i]]++;
    }
    cout << minMap.begin()->first;
    return 0;
}
