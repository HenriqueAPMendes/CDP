#include <bits/stdc++.h>
using namespace std;

#define int long long int
#define endl '\n'
#define vi vector<int>
#define ii pair<int,int>
#define vii vector<ii>
#define vvi vector<vi>

bool verify(string s, string t, int st){
    int n = s.length();
    for (int i = 0; i < n; i++){
        if (s[i] != t[(st+i)%n]) return false;
    }
    return true;
}

void solve(){
    string s, t;
    cin >> s >> t;
    bool ans = false;
    for (int i = 0; i < s.length(); i++){
        if (t[i] == s[0]) ans |= verify(s,t,i);
    }

    cout << (ans ? "Yes" : "No") << endl;
}

signed main(){
    cin.tie(0); cout.tie(0);
    ios_base::sync_with_stdio(0);
    solve();
    return 0;
}