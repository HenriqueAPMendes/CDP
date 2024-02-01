#include <bits/stdc++.h>
using namespace std;

#define int long long int
#define endl '\n'
#define vi vector<int>
#define ii pair<int,int>

signed main(){
    cin.tie(0); cout.tie(0);
    ios_base::sync_with_stdio(0);

    string s; cin >> s;

    vi v(26);
    for (int i = 0; i < s.length(); i++) v[s[i]-'a']++;

    int maxF = 0;
    char ans;

    for (int i = 0; i < 26; i++){
        if (v[i] > maxF){
            maxF = v[i];
            ans = 'a'+i;
        }
    }

    cout << ans << endl;

    return 0;
}