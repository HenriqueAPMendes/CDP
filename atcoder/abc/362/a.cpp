#include <bits/stdc++.h>
using namespace std;

#define int long long int
#define endl '\n'
#define ii pair<int,int>
#define vi vector<int>
#define vii vector<ii>
#define vvi vector<vi>

void solve(){
    int r, g, b;
    cin >> r >> g >> b;
    string c; cin >> c;
    if (c == "Blue"){
        cout << (r > g ? g : r) << endl;
    } 
    if (c == "Red"){
        cout << (b > g ? g : b) << endl;
    } 
    if (c == "Green"){
        cout << (r > b ? b : r) << endl;
    } 
}

signed main(){
    cin.tie(0); cout.tie(0);
    ios_base::sync_with_stdio(0);
    solve();
    return 0;
}