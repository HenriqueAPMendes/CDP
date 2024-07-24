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
    int n, c;
    cin >> n >> c;
    map<string,int> cnt;
    while(n--){
        string s;
        cin >> s;
        for (int i = 0; i < c; i++)
            if (s[i] == '*'){
                string s2 = s;
                for (char a = 'a'; a <= 'z'; a++){
                    s2[i] = a;
                    cnt[s2]++;
                }
            }
    }
    string ans;
    int cntAns = -1;
    for (auto [s, c]: cnt){
        if (c == cntAns)
            ans = min(ans, s);
        else if (c > cntAns)
            ans = s, cntAns = c;
    }
    cout << ans << ' ' << cntAns << endl;
}

signed main(){
    cin.tie(0); cout.tie(0);
    ios_base::sync_with_stdio(0);
    solve();
    return 0;
}