#include <iostream>
#include <list>
using namespace std;

int main() {
    long n;
    char input;
    int number, count = 0;
    list<int> goblinList;
    auto mid = goblinList.begin();
    cin >> n;
    for (long i = 0; i < n; i++) {
        cin >> input;
        if (count == 1) {
            mid = goblinList.begin();
        }
        if (input != '-') {
            cin >> number;
            if (input == '+') {
                goblinList.push_front(number);
                mid--;
                count++;
            } else {
                goblinList.insert(mid, number);
                mid--;
                count++;
            }
            if (count % 2 == 0) {
                mid++;
            }
        } else {
            cout << goblinList.back() << endl;
            goblinList.pop_back();
            count--;
            if (count % 2  != 0) {
                mid--;
            }
        }
    }
    return 0;
}
