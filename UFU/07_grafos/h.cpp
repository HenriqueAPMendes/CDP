#include <bits/stdc++.h>
using namespace std;

#define int long long
#define endl '\n'
#define vi vector<int>
#define ii pair<int,int>

void solve(int x, int y){
    int one = 1;
    int ans = 0;
    for (int i = 0; i < 64; i++){
        int x1 = x & (one << i);
        int y1 = y & (one << i);
        if (x1 != y1) ans++;
    }
    
    cout << ans << endl;
}

signed main(){
    cin.tie(0); cout.tie(0);
    ios_base::sync_with_stdio(0);

    int x, y;
    cin >> x >> y;
    while(1){
        if (x == 0 && y == 0) break;
        solve(x,y);
        cin >> x >> y;
    }

    return 0;
}