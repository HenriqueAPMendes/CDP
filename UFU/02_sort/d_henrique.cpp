#include <bits/stdc++.h>
using namespace std;

#define int long long int
#define vi vector<int>
#define endl '\n'

signed main(){
    cin.tie(0); cout.tie(0);
    ios_base::sync_with_stdio(0);

    int n; cin >> n;
    unordered_map<string,int> votos; 
    int cnt = 0;

    while(n--){
        string s; cin >> s;
        votos[s]++;
    }

    vector<pair<int,string>> votes;
    
    for (auto &[s,v] : votos) votes.push_back({v,s});

    sort(votes.begin(), votes.end(), [](pair<int,string> p1, pair<int,string> p2){
        if (p1.first > p2.first) return true;
        if (p1.first < p2.first) return false;
        return false; // make sure
    });

    for (auto &[v,s] : votes) cout << s << endl;

    return 0;
}