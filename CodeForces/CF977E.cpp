#include <bits/stdc++.h>
using namespace std;
#define ll long long

vector<vector<ll>> graph;
vector<bool> visited;
ll n, m;
bool isCycle; 

void dfs(ll v) {
    visited[v] = true;
    if (graph[v].size() != 2) isCycle = false;
    for (ll u : graph[v]) {
        if (!visited[u]) dfs(u);
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);

    cin >> n >> m;
    graph.resize(n + 1);
    visited.assign(n + 1, false);
    for (ll i = 0; i < m; i++) {
        ll u, v;
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    ll ans = 0;
    for (ll i = 1; i <= n; i++) {
        if (!visited[i]) {
            isCycle = true;
            dfs(i);       
            if (isCycle) ans++;
        }
    }
    cout << ans << endl;
}
