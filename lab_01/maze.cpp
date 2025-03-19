#include <iostream>
#include <string>
#include <queue>
#include <utility>

using namespace std;

int n, m, r, c;
int maze[999][999];
int visited[999][999];
int step[999][999];
queue<pair<int, int>> q;

 
void input() {
    cin >> n >> m >> r >> c;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> maze[i][j];
            visited[i][j] = 0;
        }
    }
}

int bfs() {
    q.push(make_pair(r - 1, c - 1));
    step[r - 1][c - 1] = 0;
    if(maze[r - 1][c - 1] == 1) return -1;
    while (!q.empty()) {
        pair<int, int> p = q.front();
        q.pop();
        visited[p.first][p.second] = 1;
        if (p.first == n - 1 || p.second == m - 1 || p.first == 0 || p.second == 0) {
            return step[p.first][p.second] + 1;
        }
        if (p.first + 1 < n && maze[p.first + 1][p.second] == 0 && visited[p.first + 1][p.second] == 0) {
            q.push(make_pair(p.first + 1, p.second));
            visited[p.first + 1][p.second] = 1;
            step[p.first + 1][p.second] = step[p.first][p.second] + 1;
        }
        if (p.first - 1 >= 0 && maze[p.first - 1][p.second] == 0 && visited[p.first - 1][p.second] == 0) {
            q.push(make_pair(p.first - 1, p.second));
            visited[p.first - 1][p.second] = 1;
            step[p.first - 1][p.second] = step[p.first][p.second] + 1;
        }
        if (p.second + 1 < m && maze[p.first][p.second + 1] == 0 && visited[p.first][p.second + 1] == 0) {
            q.push(make_pair(p.first, p.second + 1));
            visited[p.first][p.second + 1] = 1;
            step[p.first][p.second + 1] = step[p.first][p.second] + 1;
        }
        if (p.second - 1 >= 0 && maze[p.first][p.second - 1] == 0 && visited[p.first][p.second - 1] == 0) {
            q.push(make_pair(p.first, p.second - 1));
            visited[p.first][p.second - 1] = 1;
            step[p.first][p.second - 1] = step[p.first][p.second] + 1;
        }
    }
    return -1;
}


int main() {
    input();
    cout << bfs() << endl;
    return 0;
}
