#include <bits/stdc++.h>
#include <ios>
using namespace std;

#define vi vector<int>
#define int long long int
#define endl '\n'

signed main(){
    cin.tie(0); cout.tie(0);
    ios_base::sync_with_stdio(0);

    int n; cin >> n;
    vi v(n);
    int sum = 0;
    for (int i = 0; i < n; i++) { cin >> v[i]; sum += v[i]; }

    int avg = sum/n;

    int ans = 0;
    for (int i = 0; i < n; i++) ans += abs(v[i]-avg);

    cout << ans << endl;

    return 0;
}
