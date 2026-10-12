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

struct Edge {
    ll u, v, w;
};

int main() {
    setIO();

    ll n, m;
    cin >> n >> m;

    vector<Edge> edges(m);
    vector<ll> dist(n + 1, 0);
    vector<ll> parent(n + 1, -1);

    for (ll i = 0; i < m; i++) {
        cin >> edges[i].u >> edges[i].v >> edges[i].w;
    }

    ll x = -1;

    for (int i = 1; i <= n; i++) {
        x = -1;

        for (auto &e : edges) {
            if (dist[e.u] + e.w < dist[e.v]) {
                dist[e.v] = dist[e.u] + e.w;
                parent[e.v] = e.u;
                x = e.v;
            }
        }
    }

    if (x == -1) {
        cout << "NO\n";
        return 0;
    }

    ll y = x;

    for (int i = 0; i < n; i++) {
        y = parent[y];
    }

    vector<ll> cycle;
    ll cur = y;

    do {
        cycle.push_back(cur);
        cur = parent[cur];
    } while (cur != y);

    cycle.push_back(y);
    reverse(cycle.begin(), cycle.end());

    cout << "YES\n";
    for (ll v : cycle) {
        cout << v << ' ';
    }
    cout << '\n';

    return 0;
}
