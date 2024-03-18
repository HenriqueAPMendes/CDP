#include <bits/stdc++.h>
using namespace std;

#define int long long int
#define endl '\n'
#define vi vector<int>

void printst(multiset<int> st){
    cout << "set: ";
    for (auto x : st) cout << x << ' ';
    cout << endl; 
}

int calcCost(vi v, int d){
    int m = v.size();
    vi dp(m, 1e9);
    multiset<int> st = {1};
    dp[0] = 1; // initial cost
    for (int i = 1; i < m-1; i++){
        dp[i] = *st.begin() + v[i] + 1; // current cost is min cost until now plus this cost
        if (i - d - 1 >= 0)
            st.erase(st.find(dp[i-d-1])); // remove cost from the d distance to the left ???
        st.insert(dp[i]); // add current cost ???
        printst(st);
    }
    dp[m-1] = 1 + *st.begin();
    return dp[m-1];

}

void solve(){
    int n, m, k, d;
    cin >> n >> m >> k >> d;
    vector<vi> river(n, vi(m));
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            cin >> river[i][j];
        
    vi cost(n);
    for (int i = 0; i < n; i++) cost[i] = calcCost(river[i], d); 

    int totalcost = 0;
    for (int i = 0; i < k; i++) totalcost += cost[i];

    int minCost = totalcost;
    for (int i = 0; i < n-k; i++) {
        totalcost += cost[i+k] - cost[i];
        minCost = min(minCost, totalcost);
    }

    cout << minCost << endl;

}

signed main(){
    cin.tie(0); cout.tie(0);
    ios_base::sync_with_stdio(0);

    int t; 
    cin >> t;
    while(t--) solve();

    return 0;
}