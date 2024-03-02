#include <bits/stdc++.h>
using namespace std;

#define int long long int
#define vi vector<int>
#define endl '\n'

signed main(){
    cin.tie(0); cout.tie(0);
    ios_base::sync_with_stdio(0);

    int t; cin >> t;
    while(t--){
        string s; cin >> s;
        int ans = 0;
        for (int i = 0; i < 8; i++) ans += ((s[i]-'0') << (8-i-1));
        cout << ans << '.';
        ans = 0;
        for (int i = 8; i < 16; i++) ans += ((s[i]-'0') << (16-i-1));
        cout << ans << '.';
        ans = 0;
        for (int i = 16; i < 24; i++) ans += ((s[i]-'0') << (24-i-1));
        cout << ans << '.';
        ans = 0;
        for (int i = 24; i < 32; i++) ans += ((s[i]-'0') << (32-i-1));
        cout << ans << endl;
    }

    return 0;
}