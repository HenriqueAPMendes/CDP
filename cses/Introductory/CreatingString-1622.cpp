#include<bits/stdc++.h>
using namespace std;

#define endl '\n'

int fact[9] = {1,1,2,6,24,120,720,7*720,8*7*720};
map<char,int> cnt;
int n;
string ans;

void backtrack(int pos){
    if (pos == n) {cout << ans << endl; return;}
    
    for (auto &[c,qtd] : cnt){
        if (qtd>0){
            ans[pos]=c;
            qtd--;
            backtrack(pos+1);
            qtd++;
        }
    }
    
}

void solve(string s){
    backtrack(0);
}

int main(){
    cin.tie(0); cout.tie(0);
    ios_base::sync_with_stdio(0);

    string s;
    cin >> s;
    ans = s;

    n = s.length();

    for (int i = 0; i < n; i++)
        cnt[s[i]]++;

    int qtd = fact[n];
    
    for (auto &c : cnt) qtd /= fact[c.second];

    cout << qtd << endl;

    solve(s);

    return 0;
}