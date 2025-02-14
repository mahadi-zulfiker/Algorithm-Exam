#include <bits/stdc++.h>
using namespace std;

int n, m;
vector<vector<char>> grid;
vector<vector<bool>> visited;
int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};

int bfs(int startX, int startY) {
    queue<pair<int, int>> q;
    q.push(make_pair(startX, startY));
    visited[startX][startY] = true;
    
    int area = 0;
    while (!q.empty()) {
        pair<int, int> cell = q.front();
        q.pop();
        int x = cell.first, y = cell.second;
        area++;

        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i], ny = y + dy[i];

            if (nx >= 0 && nx < n && ny >= 0 && ny < m && !visited[nx][ny] && grid[nx][ny] == '.') {
                visited[nx][ny] = true;
                q.push(make_pair(nx, ny));
            }
        }
    }
    return area;
}

int main() {
    cin >> n >> m;
    grid.resize(n, vector<char>(m));
    visited.assign(n, vector<bool>(m, false));

    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            cin >> grid[i][j];

    int minArea = INT_MAX;
    bool foundComponent = false;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (grid[i][j] == '.' && !visited[i][j]) {
                int area = bfs(i, j);
                minArea = min(minArea, area);
                foundComponent = true;
            }
        }
    }

    cout << (foundComponent ? minArea : -1) << endl;
    return 0;
}
