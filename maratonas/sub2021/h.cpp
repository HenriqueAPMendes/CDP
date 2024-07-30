#include <bits/stdc++.h>
using namespace std;

#define int long long int
#define endl '\n'
#define vi vector<int>
#define ii pair<int,int>
#define vii vector<ii>

void solve(){
    int n, k;
    cin >> n >> k;
    vii v(n), original(n);
    for (int i  = 0; i < n; i++){
        cin >> v[i].first >> v[i].second;
        original[i] = v[i];
    }
    sort(v.begin(), v.end());
    bool ok = true;
    for (int i = 0; i < n; i++)
        if (v[i].second != original[i].second)
            ok = false;

    cout << (ok ? 'Y' : 'N') << endl;
}

signed main(){
    cin.tie(0); cout.tie(0);
    ios_base::sync_with_stdio(0);
    solve();
    return 0;
}