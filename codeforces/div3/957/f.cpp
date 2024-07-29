#include <bits/stdc++.h>
using namespace std;
#define MULTIPLE true

#define int long long int
#define endl '\n'

void solve() {
    int n, x, ans = 1, in; 
    cin >> n >> x;
    set<int> divisors;
    for (int i = 0; i < n; i++){
        cin >> in;
        if (x%in) continue;
        cout << "inserting: " << in << endl; 
        for (auto v : divisors) 
            divisors.insert(v*in);
        divisors.insert(in);
        if (divisors.find(x) != divisors.end()) {
            cout << "at " << i << endl;
            ans++;
            divisors.clear();
            divisors.insert(in);
        }

    }
    cout << ans << endl;

}

signed main(){
    cin.tie(0); cout.tie(0);
    ios_base::sync_with_stdio(0);
    int t = 1; 
    if (MULTIPLE) cin >> t;
    while(t--) solve();
    return 0;
}