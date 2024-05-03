#include <bits/stdc++.h>
using namespace std;

#define int long long int
#define vi vector<int>
#define endl '\n'
#define INF 1123456789


signed main(){
    cin.tie(0); cout.tie(0);
    ios_base::sync_with_stdio(0);

    int n; cin >> n;
    vi v(n);
    vi maxSum(n,-INF);
    for (int i = 0; i < n; i++) cin >> v[i];

    int ans = maxSum[0] = v[0];
    for (int i = 1; i < n; i++) {
        maxSum[i] = max(maxSum[i-1]+v[i], v[i]);
        ans = max(ans, maxSum[i]);
    }
    cout << ans << endl;

    return 0;
}
