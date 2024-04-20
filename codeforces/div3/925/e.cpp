#include <bits/stdc++.h>
using namespace std;

#define int long long int
#define vi vector<int>
#define ii pair<int,int>
#define iii pair<int,ii>
#define endl '\n'

void solve(){
    int n, m;
    cin >> n >> m;
    vector<pair<string,int>> v(n);
    for (int i = 0; i < n; i++) cin >> v[i].first;\

    int totalLength = 0;

    for (int i = 0; i < n; i++){
        string s = v[i].first;
        totalLength += s.length();
        int j;

        // size of 0's sufix
        int suf = 0;
        for (int j = s.length()-1; j >= 0; j--){
            if (s[j] != '0') break;
            suf++;
        }
        v[i].second = suf;
    }

    vi options;

    for (auto &[s, suf] : v)
        if (suf) options.push_back(suf);
    
    sort(options.rbegin(), options.rend());

    int removedByAnna = 0;
    for (int i = 0; i < options.size(); i+=2)
        removedByAnna += options[i];

    // cout << totalLength << ' ' << removedByAnna << ' ';

    if (totalLength - removedByAnna > m) cout << "Sasha" << endl;
    else cout << "Anna" << endl;
    
}

signed main(){
    cin.tie(0); cout.tie(0);
    ios_base::sync_with_stdio(0);

    int t; cin >> t;
    while(t--) solve();

    return 0;
}