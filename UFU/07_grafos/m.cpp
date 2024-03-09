#include <bits/stdc++.h>
using namespace std;

#define int long long int
#define endl '\n'
#define vi vector<int>
#define ii pair<int,int>

signed main(){
    cin.tie(0); cout.tie(0);
    ios_base::sync_with_stdio(0);

    int n, k;
    cin >> n >> k;
    vi v(n);
    for (int i = 0; i < n; i++) cin >> v[i];
    sort(v.rbegin(), v.rend());

    int ans = 0, val = 0;
    int i = 0;
    while (val < k){
        val += v[i];
        i = (i == 0) ? 1 : 0;
        ans++;
    }
    cout << ans << endl;

    return 0;
}