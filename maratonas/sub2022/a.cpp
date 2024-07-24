#include <bits/stdc++.h>
using namespace std;

#define int long long int
#define endl '\n'
#define ii pair<int,int>
#define vi vector<int>
#define vvi vector<vi>
#define ii pair<int,int>
#define vii vector<ii>
#define vvii vector<vii>

void solve(){
   int n; cin >> n;
   string s; cin >> s;
   int cnt = 0, ans = 0;
   for (int i = 0; i < n; i++){
    if (s[i] == 'a') cnt++;
    else {
        if (cnt >= 2) ans += cnt;
        cnt = 0;
    }
   }
   if (cnt >= 2) ans += cnt;
   cout << ans << endl;
}

signed main(){
    cin.tie(0); cout.tie(0);
    ios_base::sync_with_stdio(0);
    solve();
    return 0;
}