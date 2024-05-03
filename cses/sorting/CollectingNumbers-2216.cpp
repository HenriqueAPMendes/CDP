#include <bits/stdc++.h>
using namespace std;

#define int long long int
#define endl '\n'
#define vi vector<int>

signed main(){
    cin.tie(0); cout.tie(0);
    ios_base::sync_with_stdio(0);

    int n, x; cin >> n;
    vi index(n+1);
    for (int i = 0; i < n; i++){
        cin >> x;
        index[x] = i;
    }
    int ans = n;
    for (int i = 2; i <= n; i++){
        if (index[i] > index[i-1]) ans--;
    }
    cout << ans << endl;

    return 0;
}
