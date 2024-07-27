#include <iostream>
#include <cstring>
#include <stack>
#include <map>

using namespace std;

int main() {
    char charArray[100001];
    cin.getline(charArray, 100001);
    long n = strlen(charArray);
    long countAnimal {1}, countTraps {0}, count {0};
    stack<long> animalStack, trapStack;
    stack<char> myStack;
    map<long, long> resMap;
    bool check;

    for (long i {0}; i < n; i ++) {
        check = false;
        if (isupper(charArray[i])) {
            trapStack.push(countTraps);
            countTraps++;
            if (!myStack.empty() && islower(myStack.top()) && toupper(myStack.top()) == charArray[i]) {
                check = true;
            }
        } else {
            animalStack.push(countAnimal);
            countAnimal++;
            if (!myStack.empty() && isupper(myStack.top()) && tolower(myStack.top()) == charArray[i]) {
                check = true;
            }
        }
        if (check) {
            resMap[trapStack.top()] = animalStack.top();
            trapStack.pop();
            animalStack.pop();
            myStack.pop();
            count++;
        } else {
            myStack.push(charArray[i]);
        }
    }

    if (count == n / 2) {
        cout << "Possible" << endl;
        for (long i {0}; i < n / 2; i++) {
            cout << resMap[i] << " ";
        }
    } else {
        cout << "Impossible";
    }
    return 0;
}