#include <bits/stdc++.h>
using namespace std;

#define int long long int
#define vi vector<int>
#define endl '\n'
#define INF 1234567890

const int M = 1e9+7;

signed main(){
    cin.tie(0); cout.tie(0);
    ios_base::sync_with_stdio(0);

    int n, x;
    cin >> n >> x;
    
    vi coin(n);

    for (int i = 0; i < n; i++) cin >> coin[i];

    vi dp(x+1);
    dp[0] = 1;

    for (auto c : coin)
        for (int i = c; i <= x; i++)
            {dp[i] += dp[i-c]; dp[i] %= M;}
    

    cout << dp[x] << endl;

    return 0;
}