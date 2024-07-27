#include <iostream>
#include <set>
#include <vector>
using namespace std;

vector<int> colors(100, 0);

struct dot {
    int number;
    set<struct dot*> dotsTo;
};


bool checkGraph(struct dot* dot, int color) {
    colors[dot->number] = color;

    for (struct dot* child : dot->dotsTo) {
        if (colors[child->number] == 0) {
            if (color == 1) {
                if (!checkGraph(child, 2)) {
                    return false;
                }
            } else {
                if (!checkGraph(child, 1)) {
                    return false;
                }
            }
        } else if (colors[child->number] == color) {
            return false;
        }
    }
    return true;
}


int main() {
    int input1, input2, n, m;
    bool check;
    cin >> n >> m;
    struct dot* dotMassive[n];
    for (int i = 0; i < n; i++) {
        dotMassive[i] = new struct dot;
        dotMassive[i]->number = i;
    }
    for (int i = 0; i < m; i++) {
        cin >> input1 >> input2;
        input1--;
        input2--;
        dotMassive[input1]->dotsTo.insert(dotMassive[input2]);
        dotMassive[input2]->dotsTo.insert(dotMassive[input1]);
    }

    for (int i = 0; i < n; i++) {
        if (colors[i] == 0) {
            check = checkGraph(dotMassive[i], 1);
        }
        if (!check) {
            cout << "NO";
            return 0;
        }
    }
    cout << "YES";
    return 0;
}
