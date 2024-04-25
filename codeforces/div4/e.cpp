#include <bits/stdc++.h>
using namespace std;

#define int long long int
#define vi vector<int>
#define endl '\n'

void solve(){
    int n;
    cin >> n;
    vector<vi> freq(22, vi(22));
    int ans = 0;
    while (n--){
        string s;
        cin >> s;
        // soma com exatamente uma letra igual
        for (int i = 0; i < 22; i++)
            if (i == s[0] - 'a') continue;
            else ans += freq[i][s[1] - 'a'];
        for (int i = 0; i < 22; i++)
            if (i == s[1] - 'a') continue;
            else ans += freq[s[0] - 'a'][i];

        freq[s[0] - 'a'][s[1] - 'a']++;
    }
    cout << ans << endl;
}

signed main(){
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(0);

    int t;
    cin >> t;
    while (t--)
        solve();

    return 0;
}