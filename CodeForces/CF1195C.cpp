#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define i128 __int128
#define vl vector<ll>
#define vb vector<bool>
#define vec vector
#define umap unordered_map
#define uset unordered_set
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(),v.rend()
#define init(n) ll n; cin >> n;
#define printVec(v) for(int i = 0; i < v.size(); i++) cout << v[i] << " ";
#define printlnVec(v) for(int i = 0; i < v.size(); i++) cout << v[i] << " "; cout << "\n";


void setIO(string name = "") {
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);
    if (!name.empty()) {
        freopen((name + ".in").c_str(), "r", stdin);
        freopen((name + ".out").c_str(), "w", stdout);
    }
}


int main() {
    setIO();
    int n;
    cin >> n;
    vector<ll> rowA(n),rowB(n);
    for(ll i=0;i<n;i++) {
        cin >> rowA[i];
    }
    for(ll i=0;i<n;i++) {
        cin >> rowB[i];
    }
    //Space complexity O(3n) solution
    /*
    vector<vector<ll>> dp(n+1, vector<ll>(3, 0));
    dp[0][0] = 0; //pick a person if we choose at 1 row
    dp[0][1] = 0; //pick a person if we choose at 2 row
    dp[0][2] = 0; // pass
    dp[1][0] = rowA[0];
    dp[1][1] = rowB[0];
    dp[1][2] = 0;
    for(ll i=2;i<=n;i++) {
        dp[i][0] = max({dp[i-1][1],dp[i-2][0],dp[i-1][2]})+rowA[i-1];
        dp[i][1] = max({dp[i-2][1],dp[i-1][0],dp[i-1][2]})+rowB[i-1];
        dp[i][2] = max({dp[i-1][0],dp[i-1][1],dp[i-1][2]});
    }
    cout<<max(dp[n][0],max(dp[n][1],dp[n][2]))<<endl;
     */




    /*
    *    vector<vector<ll>> dp(n+1, vector<ll>(2, 0));
    dp[0][0] = 0; //pick a person if we choose at 1 row
    dp[0][1] = 0; //pick a person if we choose at 2 row
    dp[1][0] = rowA[0];
    dp[1][1] = rowB[0];
    ll ans = max(dp[1][0], dp[1][1]);
    for(ll i=2;i<=n;i++) {
        dp[i][0] = max({dp[i-2][0],dp[i-1][1],dp[i-2][1]}) + rowA[i-1];
        dp[i][1] = max({dp[i-1][0],dp[i-2][1],dp[i-2][0]}) + rowB[i-1];
        ans = max({ans,dp[i][1],dp[i][0]});
    }
    cout<<ans<<endl;
     *
     *
     **/

    if (n == 1) {
        cout << max(rowA[0], rowB[0]) << endl;
        return 0;
    }
    
    ll p2_0 = rowA[0], p2_1 = rowB[0];
    ll p1_0 = max(p2_1, 0LL) + rowA[1];
    ll p1_1 = max(p2_0, 0LL) + rowB[1];
    
    ll ans = max({p2_0, p2_1, p1_0, p1_1});

    for(ll i = 3; i <= n; i++) {
        ll cur_0 = max({p2_0, p1_1, p2_1}) + rowA[i-1];
        ll cur_1 = max({p1_0, p2_1, p2_0}) + rowB[i-1];
        
        ans = max({ans, cur_0, cur_1});
        
        p2_0 = p1_0;
        p2_1 = p1_1;
        p1_0 = cur_0;
        p1_1 = cur_1;
    }

    cout << ans << endl;
    return 0;
}
