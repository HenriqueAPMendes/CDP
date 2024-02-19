#include <bits/stdc++.h>
using namespace std;

#define int long long int 
#define endl '\n'
#define vi vector<int>
#define ii pair<int,int>

void solve(){
    int n; cin >> n;
    // cout << n << endl;
    vector<vi> v(n, vi(n));

    for (int i = 0; i < n; i++){
        string s; cin >> s;
        for (int j = 0; j < n; j++) v[i][j] = stoi(s.substr(j,1));
    }       
    
    
    // look for square
    ii first = {0,0};
    bool found = false;
    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            if (v[i][j] == 1 && !found) {
                // cout << i << ' ' << j << endl;
                first = {i,j};
                found = true;
            }
        }
    }
    // first is the first from the top left
    int height = 0, width = 0, diagonal = 0;
    for (int i = first.first; i < n; i++) if (v[i][first.second]) height++;
    for (int i = first.second; i < n; i++) if (v[first.first][i]) width++;
    int i = first.first, j = first.second;
    while(i < n && j < n){
        if (v[i++][j++] == 1) diagonal++;
    }
    // cout << first.first << ' ' << first.second << endl;
    if (height == width && width == diagonal) cout << "SQUARE" << endl;
    else cout << "TRIANGLE\n";
    // cout << height << ' ' << width << ' ' << diagonal << endl;
}

signed main(){
    cin.tie(0); cout.tie(0);
    ios_base::sync_with_stdio(0);

    int t; cin >> t;
    while(t--) solve();

    return 0;
}
