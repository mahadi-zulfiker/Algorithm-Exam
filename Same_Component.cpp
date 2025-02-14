#include <bits/stdc++.h>
using namespace std;

int n, m;
vector<vector<char>> grid;
vector<vector<bool>> visited;
int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};  

void dfs(int x, int y) {
    visited[x][y] = true;
    for (int i = 0; i < 4; i++) {
        int nx = x + dx[i], ny = y + dy[i];
        if (nx >= 0 && nx < n && ny >= 0 && ny < m && !visited[nx][ny] && grid[nx][ny] == '.') {
            dfs(nx, ny);
        }
    }
}

int main() {
    cin >> n >> m;
    grid.resize(n, vector<char>(m));
    visited.resize(n, vector<bool>(m, false));

    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            cin >> grid[i][j];

    int x1, y1, x2, y2;
    cin >> x1 >> y1 >> x2 >> y2;

    if (grid[x1][y1] == '-' || grid[x2][y2] == '-') {
        cout << "NO\n";
        return 0;
    }

    dfs(x1, y1);

    cout << (visited[x2][y2] ? "YES" : "NO") << endl;
    return 0;
}
