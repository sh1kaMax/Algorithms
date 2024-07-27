#include <iostream>
#include <set>
using namespace std;

int main() {
    long n;
    int k;
    int number;
    long long price {0};
    cin >> n >> k;
    multiset<int> prices;
    for (long i {0}; i < n; i++) {
        cin >> number;
        price += number;
        prices.insert(number);
    }
    long i {0};
    for (auto pr : prices) {
        if ((n - i) % k == 0) {
            price -= pr;
        }
        i++;
    }
    cout << price;
    return 0;
}
