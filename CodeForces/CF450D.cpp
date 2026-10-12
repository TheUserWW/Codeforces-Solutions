//https://codeforces.com/contest/450/problem/D
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

vector<vector<pair<ll,ll>>> graph;
vector<ll> dist;
vector<char> byTrain;

void dijkstra() {
    ll n = graph.size() - 1;
    priority_queue<pair<ll,ll>, vector<pair<ll,ll>>, greater<>> pq;
    for (ll i = 1; i <= n; i++)
        if (dist[i] < INF) pq.emplace(dist[i], i);

    while (!pq.empty()) {
        auto [d, u] = pq.top(); pq.pop();
        if (dist[u] != d) continue;

        for (auto [v, w] : graph[u]) {
            if (dist[u] + w < dist[v]) {
                dist[v] = dist[u] + w;
                byTrain[v] = 0;
                pq.emplace(dist[v], v);
            } else if (dist[u] + w == dist[v]) {
                byTrain[v] = 0;
            }
        }
    }
}

int main() {
    setIO();

    ll n, m, k;
    cin >> n >> m >> k;

    graph.assign(n + 1, {});
    for (ll i = 0; i < m; i++) {
        ll u, v, w;
        cin >> u >> v >> w;
        graph[u].emplace_back(v, w);
        graph[v].emplace_back(u, w);
    }

    vector<ll> trainDist(n + 1, INF);
    ll ans = 0;
    for (ll i = 0; i < k; i++) {
        ll s, y;
        cin >> s >> y;
        if (y < trainDist[s]) {
            if (trainDist[s] != INF) ans++;
            trainDist[s] = y;
        } else {
            ans++;
        }
    }

    dist.assign(n + 1, INF);
    byTrain.assign(n + 1, 0);
    dist[1] = 0;
    for (ll s = 2; s <= n; s++) {
        if (trainDist[s] < dist[s]) {
            dist[s] = trainDist[s];
            byTrain[s] = 1;
        }
    }

    dijkstra();

    for (ll s = 2; s <= n; s++) {
        if (trainDist[s] == INF) continue;
        if (!(trainDist[s] == dist[s] && byTrain[s])) ans++;
    }

    cout << ans << '\n';
    return 0;
}
