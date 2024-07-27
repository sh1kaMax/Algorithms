#include <iostream>
#include <map>
using namespace std;

int main() {
    map<char, long> alphabetCount;
    multimap <long, char, greater<>> alphabetPrice;
    long price, count {0}, begin, end;
    string input, output;
    cin >> input;
    for (char letter = 'a'; letter <= 'z'; letter++) {
        alphabetCount[letter] = 0;
        cin >> price;
        alphabetPrice.insert({price, letter});
    }
    for (char letter : input) {
        count++;
        alphabetCount[letter]++;
    }
    begin = 0;
    end = count;
    output.assign(count, ' ');
    for (pair<long, char> pair : alphabetPrice) {
        if (alphabetCount[pair.second] >= 2) {
            output[begin] = pair.second;
            output[end - 1] = pair.second;
            begin++;
            end--;
            alphabetCount[pair.second] -= 2;
        }
    }
    for (pair<char, long> pair : alphabetCount) {
        if (pair.second > 0) {
            for (long i = 0; i < pair.second; i++) {
                output[end - 1] = pair.first;
                end--;
            }
        }
    }
    cout << output;
    return 0;
}
