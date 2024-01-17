#include <bits/stdc++.h>
using namespace std;

#define endl '\n'

map<string, pair<int,int>> database;

string findMaker(int p){
    string ans = "";
    for (auto &d : database){
        if (d.second.first <= p and d.second.second >= p){ // found a maker
            if (ans.length()) return "UNDETERMINED";
            else ans = d.first;
        }
    }
    if (ans == "") return "UNDETERMINED";
    return ans;
}

void solve(){
    int d, l, h, q, p; 
    string m;
    cin >> d;
    database.clear();
    for (int i = 0; i < d; i++){
        cin >> m >> l >> h;
        database[m] = {l,h};
    }
    cin >> q;
    while(q--){
        cin >> p;
        cout << findMaker(p) << endl;;
    }
}

int main(){
    cin.tie(0); cout.tie(0);
    ios_base::sync_with_stdio(0);

    int t;
    cin >> t;
    while(t--){
        solve();
        if (t) cout << endl;
    }    

    return 0;
}