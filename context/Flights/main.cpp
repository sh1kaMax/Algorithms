#include <iostream>
#include <vector>
#include <set>
using namespace std;
int counter;

void checkProgressNormal(vector<vector<int>>* edges, int checkDistance, int nowVertex, set<int>* visited, int size) {
    counter++;
    (*visited).insert(nowVertex);
    for (int i = 0; i < size; i++) {
        if ((*visited).find(i) == (*visited).end() && (*edges)[nowVertex][i] <= checkDistance) {
            checkProgressNormal(edges, checkDistance, i, visited, size);
        }
    }
}

void checkProgressInverted(vector<vector<int>>* edges, int checkDistance, int nowVertex, set<int>* visited, int size) {
    counter++;
    (*visited).insert(nowVertex);
    for (int i = 0; i < size; i++) {
        if ((*visited).find(i) == (*visited).end() && (*edges)[i][nowVertex] <= checkDistance) {
            checkProgressInverted(edges, checkDistance, i, visited, size);
        }
    }
}


bool checkDistance(vector<vector<int>>* edges, set<int>* visited, int checkDistance, int size) {
    counter = 0;
    (*visited).clear();
    checkProgressNormal(edges, checkDistance, 0, visited, size);
    if (counter == size) {
        counter = 0;
        (*visited).clear();
        checkProgressInverted(edges, checkDistance, 0, visited, size);
        if (counter == size) {
            return true;
        }
    }
    return false;
}


int main() {
    int n, input, left = 0, right = 1000000000, distance;
    cin >> n;
    vector<vector<int>> edges(n, vector<int> (n, 0));
    set<int> visited;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j ++) {
            cin >> input;
            edges[i][j] = input;
        }
    }
    while (left < right - 1) {
        distance = (left + right) / 2;
        if (checkDistance(&edges, &visited, distance, n)) {
            right = distance;
        } else {
            left = distance;
        }
    }
    if (checkDistance(&edges, &visited, left, n)) {
        cout << left;
    } else {
        cout << right;
    }
    return 0;
}
