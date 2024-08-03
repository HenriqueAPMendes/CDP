#include <bits/stdc++.h>
using namespace std;

#define endl '\n'

void solve(){
    int n, c;
    cin >> n >> c;
    map<string,int> freq;
    while(n--){
        string s;
        cin >> s;
        for (int i = 0; i < c; i++)
            if (s[i] == '*'){
                string s2 = s;
                for (char a = 'a'; a <= 'z'; a++){
                    s2[i] = a;
                    freq[s2]++;
                }
            }
    }
    string ans;
    int freqAns = -1;
    for (auto [s, c]: freq){
        if (c == freqAns)
            ans = min(ans, s);
        else if (c > freqAns)
            ans = s, freqAns = c;
    }
    cout << ans << ' ' << freqAns << endl;
}

signed main(){
    cin.tie(0); cout.tie(0);
    ios_base::sync_with_stdio(0);
    solve();
    return 0;
}