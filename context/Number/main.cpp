#include <iostream>
#include <vector>

using namespace std;

int main() {
    string input;
    vector<string> myVector;
    while(cin >> input) {
        myVector.push_back(input);
    }
    for (size_t i {0}; i + 1 < myVector.size(); i++) {
        for (size_t j {0}; j < myVector.size() - i - 1; j++) {
            if (myVector[j] + myVector[j + 1] > myVector[j + 1] + myVector[j]) {
                swap(myVector[j], myVector[j + 1]);
            }
        }
    }
    for (size_t i {myVector.size() - 1}; i < myVector.size(); i--) {
        cout << myVector[i];
    }
    return 0;
}
