#include <bits/stdc++.h>
using namespace std;

#define int long long int
#define vi vector<int>
#define endl '\n'

const int M = 1e9+7;

signed main(){
    cin.tie(0); cout.tie(0);
    ios_base::sync_with_stdio(0);

    int n; cin >> n;

    vi dp(n+1);
    dp[0] = 1;
    
    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= 6; j++){
            if (i-j >= 0) {dp[i] += dp[i-j]; dp[i] %= M;}
        }
    }
    cout << dp[n] << endl;
    
    return 0;
}