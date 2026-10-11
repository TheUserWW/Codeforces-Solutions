#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define umap unordered_map
#define uset unordered_set
void setIO(string name = "") {
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);
    if (!name.empty()) {
        freopen((name + ".in").c_str(), "r", stdin);
        freopen((name + ".out").c_str(), "w", stdout);
    }
}
vector<ll> price;

void dijkstra(auto& graph, auto& price) {
    size_t n = graph.size()-1;
    vector<ll> dist(n+1,LLONG_MAX);
    priority_queue<pair<ll,ll>, vector<pair<ll,ll>>,greater<>> pq;
    for (int i = 1; i <= n; i++) {
        dist[i] = price[i];
        pq.emplace(dist[i],i);
    }
    while (!pq.empty()) {
        auto [w,v] = pq.top();
        pq.pop();
        if (w != dist[v]) {
            continue;
        }
        for (auto [u,d] : graph[v]) {
            if (dist[u]  > dist[v] + 2LL*d) {
                dist[u] = dist[v] + 2LL*d;
                pq.emplace(dist[u],u);
            }
        }
    }
    for (int i = 1; i <= n; i++) {
        cout << dist[i] << " ";
    }
}


int main() {
    setIO("");
    ll n, m;
    cin >> n >> m;
    vector<vector<pair<ll,ll>>> graph;
    graph.resize(n + 1);
    for (ll i = 0; i < m; i++) {
        ll u, v, w;
        cin >> u >> v >> w;

        graph[u].emplace_back(v,w);
        graph[v].emplace_back(u,w);
    }
    price.resize(n+1);
    for (ll i = 1; i <= n; i++) {
        cin >> price[i];
    }
    dijkstra(graph,price);

}
