#include <bits/stdc++.h>
using namespace std;

#define int long long int
#define vi vector<int>
#define endl '\n'
#define ii pair<int,int>

signed main(){
    cin.tie(0); cout.tie(0);
    ios_base::sync_with_stdio(0);

    int n, k;
    cin >> n >> k;
    vector<ii> ab(n);
    for (int i = 0; i < n; i++) cin >> ab[i].first >> ab[i].second;

    int l = 0, r = 2e18 + 1;
    int m = (l+r)>>1;
    while(l != r){
        m = (l+r)>>1;
        int sum = 0;
        for (auto [a,b] : ab){
            sum += (m-a)/b + 1;
            if (sum > 1e14) break;
        }
        if (sum >= k) r = m;
        else l = m+1;
    }
    m = (l+r)>>1;
    cout << m << endl;

    return 0;
}
