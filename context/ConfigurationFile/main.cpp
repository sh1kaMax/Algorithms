#include <iostream>
#include <sstream>
#include <map>
#include <vector>
#include <stack>
using namespace std;

int main() {
    map<string, long> massive;
    stack<pair<string, long>> myVector;
    stack<long> countVector;
    bool check {false};
    long count {0};
    string input;
    while (getline(cin, input)) {
        if (input == "{") {
            countVector.push(count);
            check = true;
            count = 0;
        } else if (input == "}") {
            long j {0};
            if (count != 0) {
                j = count;
                for (long i{0}; i < j; i++) {
                    pair<string, int> pairElements = myVector.top();
                    myVector.pop();
                    massive[pairElements.first] = pairElements.second;
                }
            }
            count = countVector.top();
            countVector.pop();
        } else {
            size_t signPos = input.find('=');
            string name = input.substr(0, signPos);
            if (check) {
                myVector.push(pair(name, massive[name]));
                count++;
            }
            try {
                long value = stol(input.substr(signPos + 1, input.length()));
                massive[name] = value;
            } catch (const invalid_argument& e) {
                string valueName = input.substr(signPos + 1, input.length());
                long value = massive[valueName];
                massive[name] = value;
                cout << value << endl;
            }
        }
    }
    return 0;
}