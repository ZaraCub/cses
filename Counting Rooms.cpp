#include <iostream>
#include <vector>
using namespace std;

int n, m;
vector<vector<char>> map;
vector<vector<bool>> visited;

void dfs(int x, int y) {
    // Provera granica
    if (x < 0 || x >= n || y < 0 || y >= m || visited[x][y] || map[x][y] == '#') {
        return;
    }
    visited[x][y] = true;

    dfs(x + 1, y); // dole
    dfs(x - 1, y); // gore
    dfs(x, y + 1); // desno
    dfs(x, y - 1); // levo
}

int main() {
    cin >> n >> m;
    map.resize(n, vector<char>(m));
    visited.resize(n, vector<bool>(m, false));

    // Učitavanje mape
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cin >> map[i][j];
        }
    }
    int roomCount = 0;
    
    // Prolazak kroz svaku ćeliju na mapi
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            // Ako je pod nije posećen, našli smo novu prostoriju
            if (map[i][j] == '.' && !visited[i][j]) {
                dfs(i, j); // Označimo sve povezane podove
                roomCount++;
            }
        }
    }
    cout << roomCount << endl;
    return 0;
}
