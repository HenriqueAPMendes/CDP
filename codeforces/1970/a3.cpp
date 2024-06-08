#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define int long long int
#define ii pair<int,int>
#define vii vector<ii>

signed main(){
    cin.tie(0); cout.tie(0);
    ios_base::sync_with_stdio(0);

    string s; 
    cin >> s;
    int n = s.length();
    vii pb(n);
    for (int i = 1; i < n; i++){
        pb[i].first = pb[i-1].first;
        if (s[i-1] == '(') pb[i].first++;
        else pb[i].first--;
        pb[i].second = -i;
    }
    for (auto [x, i] : pb) cout << x; cout << endl;
    cout << s << endl;
    
    
    sort (pb.begin(), pb.end());
    for (auto [x,i] : pb){
        cout << s[-i];
    }
    cout << endl;

    return 0;
}