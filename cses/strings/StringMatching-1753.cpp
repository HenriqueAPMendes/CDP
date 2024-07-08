#include <bits/stdc++.h>
using namespace std;

#define int long long int
#define vi vector<int>
#define endl '\n'

vi lps, matches;

void preKMP(string pat){
    int m = pat.length();
    lps = vi(m);
    int i = 1, len = 0;
    while(i < m){
        if (pat[i] == pat[len])
            lps[i++] = ++len;
        else if (len != 0)
            len = lps[len-1];
        else
            lps[i++] = 0;
    }
}

void KMP(string pat, string txt){
    int n, m, i = 0, j = 0;
    n = txt.length();
    m = pat.length();
    preKMP(pat);
    
    while(i < n){
        if (txt[i] == pat[j])
            i++, j++;
        if (j == m)
            matches.push_back(i-j), j = lps[j-1];
        else if (i < n && txt[i] != pat[j]){
            if (j != 0) j = lps[j-1];
            else i++;
        }
    }
}

void solve(){
    string txt, pat;
    cin >> txt >> pat;
    KMP(pat, txt);
    cout << matches.size() << endl;
}

signed main(){
    cin.tie(0); cout.tie(0);
    ios_base::sync_with_stdio(0);
    solve();
    return 0;
}