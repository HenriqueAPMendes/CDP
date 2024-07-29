#include <bits/stdc++.h>
using namespace std;

#define ii pair<int,int>
#define vii vector<ii>
#define INF 1123456789

void solve() {
    int n, a, b; 
    cin >> n;
    vii v(n);
    for (int i = 0; i < n; i++) {
        cin >> a >> b;
        v[i] = {a,b};
    }
    sort(v.rbegin(), v.rend());
    int ans = 0, first = INF;
    for (auto [a,b] : v){
        if (b <= first) {
            ans++; 
            first = a;
        }
    }
    cout << ans << endl;
}

int main(){
    cin.tie(0); cout.tie(0);
    ios_base::sync_with_stdio(0);
    solve();
    return 0;
}