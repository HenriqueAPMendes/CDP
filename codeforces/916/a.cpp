#include <bits/stdc++.h>
using namespace std;

#define MAX 2123435
#define ll long long
#define ii pair<int,int>
#define vi vector<int>
#define vii vector<ii>
#define endl '\n'

void solve(){
    map<char,int> thought;
    int n; cin >> n;
    string s; cin >> s;

    for (int i = 0; i < n; i++)
        thought[s[i]]++;

    int ans = 0;

    for (auto & c : thought) 
        if (c.second > c.first-'A') ans++;
    
    cout << ans << endl;
}

int main(){
    cin.tie(0); cout.tie(0);
    ios_base::sync_with_stdio(0);

    int t;
    cin >> t;
    while(t--)
        solve();

    return 0;
}