#include <iostream>
#include <set>
using namespace std;

struct node {
    size_t startPosition;
    size_t size;
    bool free;
    struct node* next;
    struct node* previous;
};

int main() {
    long long operation, index;
    size_t n, m, size;
    multiset<pair<size_t, struct node*>, greater<>> freeNodes;
    cin >> n >> m;
    struct node* operations[m];
    struct node firstNode = {.startPosition = 1, .size = n, .free = true, .next = nullptr, .previous = nullptr};
    struct node* firstFreeNode = &firstNode;
    freeNodes.insert(pair(firstFreeNode->size, firstFreeNode));
    for (size_t i = 0; i < m; i++) {
        cin >> operation;
        if (operation > 0) {
            if (freeNodes.begin()->first >= operation) {
                if (freeNodes.begin()->first == operation) {
                    freeNodes.begin()->second->free = false;
                    operations[i] = freeNodes.begin()->second;
                    cout << freeNodes.begin()->second->startPosition << endl;
                    freeNodes.erase(freeNodes.begin());
                } else {
                    node* newNode = new node();
                    newNode->startPosition = freeNodes.begin()->second->startPosition;
                    newNode->size = operation;
                    newNode->free = false;
                    newNode->next = freeNodes.begin()->second;
                    newNode->previous = freeNodes.begin()->second->previous;
                    if (freeNodes.begin()->second->previous != nullptr) {
                        freeNodes.begin()->second->previous->next = newNode;
                    }
                    freeNodes.begin()->second->startPosition += operation;
                    freeNodes.begin()->second->previous = newNode;
                    freeNodes.begin()->second->size -= operation;
                    freeNodes.insert(pair(freeNodes.begin()->first - operation, freeNodes.begin()->second));
                    freeNodes.erase(freeNodes.begin());
                    operations[i] = newNode;
                    cout << newNode->startPosition << endl;
                }
            } else {
                operations[i] = nullptr;
                cout << -1 << endl;
            }
        } else {
            index = abs(operation) - 1;
            if (operations[index] != nullptr) {
                operations[index]->free = true;
                size = operations[index]->size;
                if (operations[index]->previous != nullptr || operations[index]->next != nullptr) {
                    if (operations[index]->previous != nullptr) {
                        if (operations[index]->previous->free) {
                            freeNodes.erase(pair(operations[index]->previous->size, operations[index]->previous));
                            size += operations[index]->previous->size;
                            operations[index]->size += operations[index]->previous->size;
                            operations[index]->startPosition = operations[index]->previous->startPosition;
                            if (operations[index]->previous->previous != nullptr) {
                                operations[index]->previous->previous->next = operations[index];
                            }
                            operations[index]->previous = operations[index]->previous->previous;
                        }
                    }
                    if (operations[index]->next != nullptr) {
                        if (operations[index]->next->free) {
                            freeNodes.erase(pair(operations[index]->next->size, operations[index]->next));
                            size += operations[index]->next->size;
                            operations[index]->size += operations[index]->next->size;
                            if (operations[index]->next->next != nullptr) {
                                operations[index]->next->next->previous = operations[index];
                            }
                            operations[index]->next = operations[index]->next->next;
                        }
                    }
                }
                freeNodes.insert(pair(size, operations[index]));
            }
        }
    }
    return 0;
}
