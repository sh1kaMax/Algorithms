#include <iostream>
#include <vector>
#include <queue>
using namespace std;
const int MAX_SIZE = (1 << 31) - 1;

int main() {
    int n, m, x1, y1, x2, y2, newDistance;
    string input, output = "";
    bool check;
    cin >> n >> m >> x1 >> y1 >> x2 >> y2;
    int massive[n][m];
    for (int i = 0; i < n; i++) {
        cin >> input;
        for (int j = 0; j < m; j++) {
            if (input[j] == '.') {
                massive[i][j] = 1;
            } else if (input[j] == 'W') {
                massive[i][j] = 2;
            } else {
                massive[i][j] = -1;
            }
        }
    }
    int size = n * m;
    pair<int, int> minDistance[size];
    vector<bool> visited(size, false);
    vector<vector<pair<int, int>>> connections(size, vector<pair<int, int>>(4, pair(0, 0)));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (i != 0) {
                connections[i * m + j][0] = pair((i - 1) * m + j, massive[i - 1][j]);
            }
            if (i != n - 1) {
                connections[i * m + j][1] = pair((i + 1) * m + j, massive[i + 1][j]);
            }
            if (j != 0) {
                connections[i * m + j][2] = pair(i * m + j - 1, massive[i][j - 1]);
            }
            if (j != m - 1) {
                connections[i * m + j][3] = pair(i * m + j + 1, massive[i][j + 1]);
            }
        }
    }
    int indexes[4] = {-m, m, -1, 1};
    for (int i = 0; i < size; i++) {
        minDistance[i] = pair(MAX_SIZE, i);
    }
    int beginIndex = (x1 - 1) * m + y1 - 1;
    minDistance[beginIndex] = pair(0, beginIndex);
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> distances;
    distances.push(pair(0, beginIndex));
    pair<int, int> now_pair;
    do {
        now_pair = distances.top();
        if (now_pair.first != MAX_SIZE) {
            for (int i = 0; i < 4; i++) {
                if (connections[now_pair.second][i].second > 0) {
                    newDistance = now_pair.first + connections[now_pair.second][i].second;
                    if (newDistance < minDistance[connections[now_pair.second][i].first].first) {
                        minDistance[connections[now_pair.second][i].first].first = newDistance;
                        distances.push(pair(newDistance, now_pair.second + indexes[i]));
                    }
                }
            }
            distances.pop();
        }
    } while (!distances.empty());
    int index = (x2 - 1) * m + y2 - 1;
    if (minDistance[index].first < MAX_SIZE) {
        cout << minDistance[index].first << endl;
        while (minDistance[index].first > 0) {
            check = true;
            if (index - m >= 0) {
                if (check && minDistance[index - m].first + connections[index - m][1].second == minDistance[index].first) {
                    output = "S" + output;
                    index -= m;
                    check = false;
                }
            }
            if (index - 1 >= 0) {
                if (check && minDistance[index - 1].first + connections[index - 1][3].second == minDistance[index].first) {
                    output = "E" + output;
                    index--;
                    check = false;
                }
            }
            if (index + 1 < size) {
                if (check && minDistance[index + 1].first + connections[index + 1][2].second == minDistance[index].first) {
                    output = "W" + output;
                    index++;
                    check = false;
                }
            }
            if (index + m < size) {
                if (check & minDistance[index + m].first + connections[index + m][0].second == minDistance[index].first){
                    output = "N" + output;
                    index += m;
                }
            }
        }
        cout << output;
    } else {
        cout << -1;
    }
    return 0;
}
