#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> adj; // Lista susedstva za graf
vector<bool> visited;    // Vektor za označavanje posećenih čvorova

// DFS funkcija za obilazak čvorova unutar jedne komponente
void dfs(int node) {
    visited[node] = true;
    for (int neighbor : adj[node]) {
        if (!visited[neighbor]) {
            dfs(neighbor);
        }
    }
}

int main() {
    int n, m;
    cin >> n >> m;

    adj.resize(n + 1);
    visited.resize(n + 1, false);

    // Učitavanje puteva
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    vector<int> components;

    // Pronalazak svih komponenti povezanosti
    for (int i = 1; i <= n; i++) {
        if (!visited[i]) {
            components.push_back(i); // Dodajemo predstavnika nove komponente
            dfs(i); // Obilazimo sve čvorove unutar te komponente
        }
    }

    int roads_needed = components.size() - 1;
    cout << roads_needed << endl;

    // Dodajemo puteve između susednih komponenti
    for (int i = 1; i < components.size(); i++) {
        cout << components[i - 1] << " " << components[i] << endl;
    }

    return 0;
}
