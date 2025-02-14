#include <bits/stdc++.h>
using namespace std;

int N, M;
vector<vector<char>> maze;
vector<vector<bool>> visited;
vector<vector<pair<int, int>>> parent;

vector<pair<int, int>> directions = {{0, 1}, {0, -1}, {-1, 0}, {1, 0}};

void bfs(int startX, int startY) {
    queue<pair<int, int>> q;
    q.push(make_pair(startX, startY));
    visited[startX][startY] = true;

    while (!q.empty()) {
        pair<int, int> current = q.front();
        int x = current.first, y = current.second;
        q.pop();

        if (maze[x][y] == 'D') {
            pair<int, int> curr = make_pair(x, y);
            while (curr != make_pair(startX, startY)) {
                pair<int, int> p = parent[curr.first][curr.second];
                if (maze[p.first][p.second] != 'R') 
                    maze[p.first][p.second] = 'X';
                curr = p;
            }
            return;
        }

        for (size_t i = 0; i < directions.size(); i++) {
            int dx = directions[i].first, dy = directions[i].second;
            int nx = x + dx, ny = y + dy;

            if (nx >= 0 && nx < N && ny >= 0 && ny < M && !visited[nx][ny] && (maze[nx][ny] == '.' || maze[nx][ny] == 'D')) {
                visited[nx][ny] = true;
                q.push(make_pair(nx, ny));
                parent[nx][ny] = make_pair(x, y);
            }
        }
    }
}

int main() {
    cin >> N >> M;
    maze.resize(N, vector<char>(M));
    visited.assign(N, vector<bool>(M, false));
    parent.assign(N, vector<pair<int, int>>(M, make_pair(-1, -1)));

    int startX, startY;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> maze[i][j];
            if (maze[i][j] == 'R') {
                startX = i;
                startY = j;
            }
        }
    }

    bfs(startX, startY);

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cout << maze[i][j];
        }
        cout << "\n";
    }

    return 0;
}
