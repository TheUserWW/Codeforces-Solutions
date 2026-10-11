//https://cses.fi/problemset/task/1671/
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

static vector<vector<pair<ll,ll>>> graph;
static vector<ll> dist;

void dijkstra(ll start) {
    priority_queue<pair<ll, ll>,vector<pair<ll,ll>>,greater<>> pq;
    dist[start] = 0;
    pq.emplace(dist[start], start);
    while (!pq.empty()) {
        auto [d,u] = pq.top();
        pq.pop();
        if (dist[u] != d) {
            continue;
        }
        for (auto [v,w] : graph[u]) {
            if (dist[v] > dist[u] + w) {
                dist[v] = dist[u] + w;
                pq.emplace(dist[v], v);
            }
        }
    }
    for (int i = 1; i <= graph.size()-1; i++) {
        cout << dist[i] << " ";
    }
}

int main() {
    setIO("");
    ll n, m;
    cin >> n >> m;
    graph.resize(n+1);
    dist.assign(n+1,LLONG_MAX);
    for (ll i = 0; i < m; i++) {
        ll u,v,w;
        cin >> u >> v>> w;
        graph[u].emplace_back(v,w);
    }
    dijkstra(1);
}
