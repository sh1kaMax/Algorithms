#include <iostream>
#include <vector>
#include <set>
using namespace std;


struct dot {
    int number;
    vector<pair<int, struct dot*>> keyTo;
};


void findMaxWay(vector<bool>* visited, vector<int>* prices, struct dot* now_dot, int destination, int price) {
    if (!(*visited)[now_dot->number]) {
        (*visited)[now_dot->number] = true;
        (*prices)[now_dot->number - 1] = price;
    } else {
        if ((*prices)[now_dot->number - 1] < price) {
            (*prices)[now_dot->number - 1] = price;
        } else {
            return;
        }
    }
    for (int i = 0; i < now_dot->keyTo.size(); i++) {
        findMaxWay(visited, prices, now_dot->keyTo[i].second, destination, price + now_dot->keyTo[i].first);
    }
}


int main() {
    int n, m, from, to, price;
    cin >> n >> m;
    struct dot* dots_massive[n];
    for (int i = 0; i < n; i++) {
        dots_massive[i] = new struct dot;
        dots_massive[i]->number = i + 1;
    }
    for (int i = 0; i < m; i++) {
        cin >> from >> to >> price;
        from--;
        to--;
        dots_massive[from]->keyTo.push_back(pair(price, dots_massive[to]));
    }
    cin >> from >> to;
    from--;
    to--;
    vector<bool> visited(n, false);
    vector<int> dots_prices(n, 0);
    findMaxWay(&visited, &dots_prices, dots_massive[from], to, 0);
    if (dots_prices[to] != 0) {
        cout << dots_prices[to];
    } else {
        cout << "No solution";
    }
    return 0;
}
