#include <iostream>
#include <vector>
#include <set>
#include <map>
using namespace std;

struct dot {
    int number;
    struct dot* keyTo;
    int size = 0;
    vector<struct dot*> keyFrom;
};


struct dot* find(set<int> visited, struct dot* dot) {
    if (dot->keyTo != nullptr && visited.find(dot->keyTo->number) == visited.end()) {
        visited.insert(dot->number);
        return find(visited, dot->keyTo);
    } else {
        return dot;
    }
}


set<int> visitAllDots(set<int> visited, struct dot* dot) {
    if (visited.find(dot->number) == visited.end()) {
        visited.insert(dot->number);
    } else {
        return visited;
    }
    set<int> visits;
    for (int i = 0; i < dot->size; i++) {
        visits = visitAllDots(visited, dot->keyFrom[i]);
        for (int j : visits) {
            visited.insert(j);
        }
    }
    return visited;
}


int main() {
    int dotCount, index, breakCount = 0;
    cin >> dotCount;
    struct dot* dotMassive[dotCount];
    map<int, bool> dotAlive;
    for (int i = 0; i < dotCount; i++) {
        dotMassive[i] = new struct dot;
        dotAlive[i] = true;
    }
    for (int i = 0; i < dotCount; i++) {
        cin >> index;
        index--;
        dotMassive[i]->keyTo = dotMassive[index];
        dotMassive[i]->number = i;
        dotMassive[index]->keyFrom.push_back(dotMassive[i]);
        dotMassive[index]->size++;
    }
    for (int i = 0; i < dotCount; i++) {
        if (dotAlive[i]) {
            struct dot* deleteFrom = find(set<int> {}, dotMassive[i]);
            set<int> toDelete = visitAllDots(set<int> {}, deleteFrom);
            for (int j : toDelete) {
                dotAlive[j] = false;
            }
            breakCount++;
        }
    }
    cout << breakCount;
    return 0;
}
