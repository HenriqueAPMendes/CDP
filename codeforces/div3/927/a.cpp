#include <bits/stdc++.h>
using namespace std;

#define int long long int
#define ii pair<int,int>
#define endl '\n'

signed main(){
    cin.tie(0); cout.tie(0);
    ios_base::sync_with_stdio(0);

    int t; cin >> t;
    while(t--){
        int n; cin >> n;
        string s; cin >> s;
        int ans = 0;
        for (int i = 0; i < s.length(); i++){
            if (s[i] == '.') continue;
            else if (s[i] == '@') ans++;
            else if (s[i] == '*' && i>=1 && s[i-1] == '*') break;
        }
        cout << ans << endl;
    }

    return 0;
}