#include <bits/stdc++.h>
using namespace std;

int main (){
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    int n, s, k, p, q, ans = 0;
    cin >> n >> s >> k;

    while (n--){
        cin >> p >> q;
        ans += p*q;
    }
    if (ans >= s) cout << ans << '\n';
    else cout << ans+k << '\n';

    return 0;
}