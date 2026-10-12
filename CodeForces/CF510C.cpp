//topological sort
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

bool convert(vector<string> nameList) {
    size_t n = nameList.size();
    for(ll i=0;i<n-1;i++) {
        ll j = 0;
        bool flag = true;
        while ( j < nameList[i].size() && j < nameList[i+1].size() ) {
            if (nameList[i][j] != nameList[i+1][j]) {
                graph[nameList[i][j]-'a'+1].push_back(nameList[i+1][j]-'a'+1);
                flag = false;
                break;
            }
            j++;
        }
        if (flag == true && nameList[i].size() > nameList[i+1].size()) {
            return false;
        }
    }

    for(ll u = 1; u < graph.size(); u++) {
        for(long long v : graph[u]) {
            indegree[v] ++;
        }
    }
    return true;
}

int main() {
    setIO("");
    ll n;
    cin >> n;
    vector<string> nameList(n);
    for(ll i=0;i<n;i++) {
        cin >> nameList[i];
    }
    //1-based index
    graph = vector<vector<ll>> (27);
    indegree = vector<ll> (27);
    const bool check = convert(nameList);
    if (!check) {
        cout<<"Impossible"<<endl;
        return 0;
    }
    const vector<ll> res = kahn();
    if (res.empty()) {
        cout<<"Impossible"<<endl;
        return 0;
    }
    for(const auto re : res) {
        cout<<static_cast<char>(re + 'a'-1);
    }
    return 0;
}
