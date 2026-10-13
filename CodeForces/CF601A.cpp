//https://codeforces.com/problemset/problem/601/A
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define umap unordered_map
#define uset unordered_set
void setIO(const string& name = "") {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    if (!name.empty()) {
        freopen((name + ".in").c_str(), "r", stdin);
        freopen((name + ".out").c_str(), "w", stdout);
    }
}
constexpr ll INF = (ll)4e18;

vector<vector<ll>> graphA,graphB;
vector<ll> dist;
vector<bool> visited;

ll bfs(ll start , vector<vector<ll>>& graphA) {
    ll n = graphA.size()-1;
    dist[start] = 0;
    queue<ll> q;
    q.push(start);
    while (!q.empty()) {
        ll u = q.front();
        q.pop();
        for (ll v= 1; v <= n; v++) {
            if (graphA[u][v] != 0 && dist[v] == INF) {
                dist[v] = dist[u]+1;
                q.push(v);
            }
        }
    }
    return dist[n];
}

int main() {
    setIO();
    ll n, m;
    cin >> n >> m;
    graphA.resize(n+1,vector<ll>(n+1));
    graphB.resize(n+1,vector<ll>(n+1,0));
    dist.resize(n+1,INF);
    for (ll i = 1; i <= m; i++) {
        ll u,v;
        cin >> u >> v;
        graphA[v][u] = 1;
        graphA[u][v] = 1;
    }

    for (ll i = 1; i <= n; i++) {
        for (ll j = 1; j <= n; j++) {
            if (i == j) continue;
            graphB[i][j] = !graphA[i][j];
        }
    }

    ll ans1 = bfs(1,graphA);
    dist.assign(n+1,INF);
    ll ans2 = bfs(1,graphB);
    if (ans1 == INF || ans2 == INF) {
        cout << -1 << endl;
    }
    else {
        cout << max(ans1, ans2) << endl;
    }
    return 0;
}
