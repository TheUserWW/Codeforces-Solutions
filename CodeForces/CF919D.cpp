//https://codeforces.com/problemset/problem/919/D


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

vector<vector<ll>> graph;
vector<ll> indegrees;
vector<vector<ll>> dp;
string s;

void kahn() {
    queue<size_t> q;
    ll cnt = 0;
    for (size_t i = 1; i < indegrees.size(); ++i) {
        if (indegrees[i] == 0) {
            q.push(i);
        }
    }
    while (!q.empty()) {
        cnt++;
        size_t v = q.front();
        q.pop();
        dp[v][s[v-1] - 'a']++;
        for (ll u : graph[v]) {
            indegrees[u]--;
            if (indegrees[u] == 0) {
                q.push(u);
            }
            for (size_t c = 0; c < 26; c++) {
                dp[u][c] = max(dp[u][c], dp[v][c]);
            }
        }
    }


    if (cnt < indegrees.size()-1) {
        cout<<-1;
    }
    else {
        ll ans = 0;
        for (size_t i = 1; i <= indegrees.size()-1; ++i) {
            for (size_t j = 0; j <= 25; ++j) {
                ans = max(ans, dp[i][j]);
            }
        }
        cout<<ans;
    }
}
int main() {
    setIO();
    ll n, m;
    cin >> n >> m;
    cin >> s;
    graph.resize(n + 1);
    indegrees.resize(n + 1);
    dp.assign(n+1, vector<ll>(26,0));
    for (ll i = 0; i < m; ++i) {
        ll u,v;
        cin >> u >> v;
        graph[u].push_back(v);
        indegrees[v]++;
    }
    kahn();
    return 0;
}
