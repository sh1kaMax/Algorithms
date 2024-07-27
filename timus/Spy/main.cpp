#include <iostream>
#include <set>
using namespace std;

int main() {
    int n;
    string s;
    cin >> n >> s;
    multiset<pair<char, int>> chars;
    int index = 0, i = 0, count = 0;
    for (char ch : s) {
        chars.insert(pair(ch, index));
        index++;
        count++;
    }
    pair<char, long> arr[count];
    for (pair<char, long> p : chars) {
        arr[i] = p;
        i++;
    }
    index = n - 1;
    for (int j = 0; j < s.size(); j++) {
        cout << arr[index].first;
        index = arr[index].second;
    }
    cout << endl;
    return 0;
}