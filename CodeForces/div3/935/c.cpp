#include <bits/stdc++.h>
using namespace std;

#define int long long int
#define vi vector<int>
#define endl '\n'

void solve(){
    int n; cin >> n;
    string s; cin >> s;
    vi a(n), presum(n);
    for (int i = 0; i < n; i++) a[i] = s[i]-'0';
    
    presum[0] = a[0];
    for (int i = 1; i < n; i++) presum[i] = presum[i-1] + a[i];

    double mindist = 1234567890;
    int minI = 0;
    for (int i = 0; i <= n; i++){
        int leftsatisfied, rightsatisfied;
        if (i > 0) {
            leftsatisfied = i-presum[i-1];
            rightsatisfied = presum[n-1] - presum[i-1];
        } else {
            leftsatisfied = i;
            rightsatisfied = presum[n-1];
        }
        int minleft = i/2;
        int minright = (n-i)/2;
        if (i%2) minleft++;
        if ((n-i)%2) minright++;
        if (leftsatisfied >= minleft && rightsatisfied >= minright) {
            if (mindist > abs(n/2.0 - i)){
                mindist = abs(n/2.0 - i);
                minI = i;
            }
        }
    }
    cout << minI << endl;
}

signed main(){
    cin.tie(0); cout.tie(0);
    ios_base::sync_with_stdio(0);

    int t; cin >> t;
    while(t--) solve();

    return 0;
}