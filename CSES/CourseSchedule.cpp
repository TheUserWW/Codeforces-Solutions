//Course Schedule Topological Sort
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

static vector<vector<ll>> graph;
static vector<ll> indegree;

vector<ll> kahn() {
    vector<ll> res;
    queue<ll> q;
    for(ll i=1;i< indegree.size();i++) {
        if (indegree[i] == 0) {
            q.push(i);
        }
    }

    while(!q.empty()) {
        auto u = q.front();
        q.pop();
        res.emplace_back(u);
        for(ll v : graph[u]) {
            indegree[v]--;
            if (indegree[v] == 0) {
                q.push(v);
            }
        }
    }
    if (res.size() != graph.size()-1) {
        return {};
    }
    return res;
}

int main() {
    setIO("");
    ll n,m;
    cin >> n >> m;
    graph.resize(n+1);
    indegree.resize(n+1);
    for (ll i = 1; i <= m; i++) {
        ll u,v;
        cin >> u >> v;
        graph[u].emplace_back(v);
        indegree[v]++;
    }

    vector<ll> res = kahn();
    if (res.empty()) {
        cout <<"IMPOSSIBLE";
    }
    else {
        for (ll i = 0; i < n; i++) {
            cout << res[i] << " ";
        }
    }
}
