#include <iostream>
#include <stack>
using namespace std;

int main() {
    stack<size_t> scoredPools;
    size_t topPool = 0;
    size_t n;
    cin >> n;
    size_t pools[n];
    for (size_t i = 0; i < n; i++) {
        cin >> pools[i];
    }
    for (size_t i = 0; i < n; i++) {
        if (pools[i] > topPool) {
            size_t pool = topPool + 1;
            while (pool < pools[i]) {
                scoredPools.push(pool);
                pool++;
            }
            topPool = pools[i];
        } else if (pools[i] == scoredPools.top()) {
            scoredPools.pop();
        } else {
            cout << "Cheater";
            return 0;
        }
    }
    cout << "Not a proof";
    return 0;
}
