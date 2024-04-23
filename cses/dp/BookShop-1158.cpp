#include <bits/stdc++.h>
using namespace std;

#define INF 1123456789
#define endl '\n'
#define vi vector<int>

// int peso[1002], valor[1002];
// int dp[100002][1002];


int main(){
    cin.tie(0); cout.tie(0);
    ios_base::sync_with_stdio(0);

    int n, x;
    cin >> n >> x;

    vi peso(n), valor(n);
    vector<vi> dp(x+1, vi(n+1));

    for (int i = 0; i < n; i++)
        cin >> peso[i];
    for (int i = 0; i < n; i++)
        cin >> valor[i];

    for (int i = 1; i <= x; i++)
        for (int j = 1; j <= n; j++){
            int r1 = dp[i][j-1];
            int r2 = i-peso[j-1] >= 0 ? dp[i-peso[j-1]][j-1] + valor[j-1] : -INF;
            dp[i][j] = max(r1, r2);
        }

    cout << dp[x][n] << endl;

    return 0;
}
// int main () { 
//     cin.tie(0); cout.tie(0);
//     ios_base::sync_with_stdio(0);
//     int n, x;
//     cin >> n >> x;
//     vector<int> h(n), v(n);
//     for (int i = 0; i < n; i++) cin >> h[i];
//     for (int i = 0; i < n; i++) cin >> v[i];
//     vector<vector<int>> dp(n+1, vector<int> (x+1, -1));
//     dp[0][x] = 0;
//     for (int i = 0; i < n; i++) {
//         for (int j = x; j >= 0; j--) {
//             if (dp[i][j] >= 0) {
//                 dp[i+1][j] = max(dp[i+1][j], dp[i][j]);
//                 if (j >= h[i]) dp[i+1][j-h[i]] = max(dp[i+1][j-h[i]], dp[i][j] + v[i]);
//             }
//         }
//     }
//     int ans = 0;
//     for (int i = x; i >= 0; i--) ans = max(ans, dp[n][i]);
//     cout << ans << '\n';
//     return 0;
// }