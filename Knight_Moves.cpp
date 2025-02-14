#include <bits/stdc++.h>
using namespace std;

vector<pair<int, int>> moves = {
    {-2, -1}, {-2, 1}, {2, -1}, {2, 1},
    {-1, -2}, {-1, 2}, {1, -2}, {1, 2}
};

int minKnightMoves(int N, int M, int Ki, int Kj, int Qi, int Qj) {
    queue<pair<int, int>> q;
    vector<vector<int>> visited(N, vector<int>(M, 0));
    q.push({Ki, Kj});
    visited[Ki][Kj] = 1;
    
    int steps = 0;
    while (!q.empty()) {
        int size = q.size();
        while (size--) {
            pair<int, int> curr = q.front(); q.pop();
            int x = curr.first, y = curr.second;
            
            if (x == Qi && y == Qj) return steps;
            
            for (const auto& move : moves) {
                int dx = move.first, dy = move.second;
                int nx = x + dx, ny = y + dy;
                if (nx >= 0 && nx < N && ny >= 0 && ny < M && !visited[nx][ny]) {
                    visited[nx][ny] = 1;
                    q.push({nx, ny});
                }
            }
        }
        steps++;
    }
    return -1;
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        int N, M, Ki, Kj, Qi, Qj;
        cin >> N >> M >> Ki >> Kj >> Qi >> Qj;
        cout << minKnightMoves(N, M, Ki, Kj, Qi, Qj) << "\n";
    }
    return 0;
}
