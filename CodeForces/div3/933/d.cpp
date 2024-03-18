#include <bits/stdc++.h>
using namespace std;

#define int long long int
#define endl '\n'
#define vi vector<int>

int clockwise (int start, int dist, int n){
    int ans = start + dist;
    if (ans > n) ans %= n;
    // cout << "clockwise: ";
    // cout << start << ' ' << dist << ' ' << n << ' ' << ans << endl;
    return ans;
}

int counterclockwise (int start, int dist, int n){
    int ans = start - dist;
    if (ans < 1) ans = n + ans;
    // cout << "counterclockwise: ";
    // cout << start << ' ' << dist << ' ' << n << ' ' << ans << endl;
    return ans;
}

void solve(){
    int n, m, x;
    cin >> n >> m >> x;
    vector<set<int>> possibilities(m+1); // possible players after i throws
    possibilities[0].insert(x);
    for (int i = 0; i < m; i++){
        int dist;
        char direction;
        cin >> dist >> direction;
        if (direction == '0')
            for (auto player : possibilities[i]) 
                possibilities[i+1].insert(clockwise(player, dist, n));
        else if (direction == '1')
            for (auto player : possibilities[i]) 
                possibilities[i+1].insert(counterclockwise(player, dist, n));
        else 
            for (auto player : possibilities[i]) {
                possibilities[i+1].insert(clockwise(player, dist, n));
                possibilities[i+1].insert(counterclockwise(player, dist, n));
            }
    }

    cout << possibilities[m].size() << endl;
    for (auto player : possibilities[m]) cout << player << ' ';
    cout << endl;
}

signed main(){
    cin.tie(0); cout.tie(0);
    ios_base::sync_with_stdio(0);

    int t; 
    cin >> t;
    while(t--) solve();

    return 0;
}