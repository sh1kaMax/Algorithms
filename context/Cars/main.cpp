#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <deque>
#include <queue>
using namespace std;


int main() {
    size_t n, k, p, count = 0, sumi = 0;
    cin >> n >> k >> p;
    unordered_map<size_t, deque<size_t>> indexMap;
    unordered_set<size_t> carOnFloor;
    priority_queue<pair<size_t, size_t>> maxIndex;
    size_t carsOperations[p];
    pair<size_t, size_t> deletePair;
    for (int i = 0; i < p; i++) {
        cin >> carsOperations[i];
        indexMap[carsOperations[i]].push_front(i);
    }
    for (int i = 0; i < p; i++) {
        if (sumi < k && carOnFloor.find(carsOperations[i]) == carOnFloor.end()) {
            carOnFloor.insert(carsOperations[i]);
            sumi++;
            count++;
        } else if (carOnFloor.find(carsOperations[i]) != carOnFloor.end()) {
            indexMap[carsOperations[i]].pop_back();
            if (indexMap[carsOperations[i]].empty()) {
                maxIndex.emplace(1000000, carsOperations[i]);
            } else {
                maxIndex.emplace(indexMap[carsOperations[i]].back(), carsOperations[i]);
            }
            continue;
        } else if (sumi == k) {
            if (sumi == 1 || i + 1 == p) {
                count++;
            } else {
                deletePair = maxIndex.top();
                maxIndex.pop();
                carOnFloor.erase(deletePair.second);
                carOnFloor.insert(carsOperations[i]);
                count++;
            }
        }
        indexMap[carsOperations[i]].pop_back();
        if (indexMap[carsOperations[i]].empty()) {
            maxIndex.emplace(1000000, carsOperations[i]);
        } else {
            maxIndex.emplace(indexMap[carsOperations[i]].back(), carsOperations[i]);
        }
    }
    cout << count;
    return 0;
}
