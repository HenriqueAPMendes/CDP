#include <bits/stdc++.h>
using namespace std;

#define int long long int
#define endl '\n'
#define ii pair<int,int>
#define vi vector<int>
#define vii vector<ii>
#define vvi vector<vi>
#define ZAP 998244353

int n;
vi s;

int calc(int i, int j, int l){
    if (l == 2) return 1;
    int ans = 0;
    for (int k = j+1; k < n; k++)
        if (s[k] - s[j] == s[j] - s[i])
            ans += calc(j,k,l-1), ans %= ZAP;
    return ans;
}

void solve(){
    cin >> n;
    s = vi(n);
    for (int i = 0; i < n; i++) cin >> s[i];
    vi ans(n+1);
    ans[1] = n;
    ans[2] = n*(n-1)/2;
    for (int i = 0; i < n; i++)
        for (int j = i+1; j < n; j++)
            for (int k = 3; k < n+1; k++)
                ans[k] += calc(i,j,k), ans[k] %= ZAP;
    for (int i = 1; i <= n; i++) cout << ans[i] << ' '; cout << endl;

}

signed main(){
    cin.tie(0); cout.tie(0);
    ios_base::sync_with_stdio(0);
    solve();
    return 0;
}