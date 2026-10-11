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


void dijkstra(int start, vector<vector<pair<ll,ll>>> &graph) {
    size_t n = graph.size()-1;
    vector<ll> dist(n+1, LLONG_MAX);
    vector<ll> prev(n+1, -1);
    priority_queue<pair<ll,ll>,vector<pair<ll,ll>>,greater<>> pq;
    dist[start] = 0;

    pq.emplace(0,start);
    while (!pq.empty()) {
        auto [w,v] = pq.top();
        pq.pop();
        if (w != dist[v]) {
            continue;
        }


        for (auto [u,w] : graph[v]) {
            if (dist[u] > dist[v] + w) {
                dist[u] = dist[v] + w;
                prev[u] = v;
                pq.emplace(dist[u],u);
            }
        }
    }
    if (dist[n] == LLONG_MAX) {
        cout << -1;
        return;
    }

    vector<ll> ans;
    for (ll cur = n; cur != -1; cur = prev[cur]) {
        ans.push_back(cur);
    }
    reverse(ans.begin(),ans.end());
    for (auto i : ans){ cout << i << " "; }

}

int main() {
    setIO("");
    int n, m;
    cin >> n >> m;
    vector<vector<pair<ll,ll>>> graph;
    graph.resize(n + 1);
    for (int i = 0; i < m; i++) {
        int u, v, w;
        cin >> u >> v >> w;

        graph[u].emplace_back(v,w);
        graph[v].emplace_back(u,w);
    }
    dijkstra(1,graph);
}
