#include <bits/stdc++.h>
using namespace std;

#define MAX 2123435
#define INF 212345678
#define ll long long
#define ii pair<int,int>
#define vi vector<int>
#define vii vector<ii>
#define endl '\n'

vii a(MAX), b(MAX), c(MAX);

void solve(){
    int n; cin >> n;
    int x;
    for (int i = 0; i < n; i++) {cin >> x; a[i] = {x,i};}
    for (int i = 0; i < n; i++) {cin >> x; b[i] = {x,i};}
    for (int i = 0; i < n; i++) {cin >> x; c[i] = {x,i};}

    sort(a.begin(), a.begin()+n, greater());
    sort(b.begin(), b.begin()+n, greater());
    sort(c.begin(), c.begin()+n, greater());

    int ans = 0;

    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            for (int k = 0; k < 3; k++)
                if (a[i].second != b[j].second and a[i].second != c[k].second and b[j].second != c[k].second)
                    ans = max(ans, a[i].first+b[j].first+c[k].first);
            
    cout << ans << endl;
            
}

int main(){
    cin.tie(0); cout.tie(0);
    ios_base::sync_with_stdio(0);

    int t; cin >> t;
    while(t--) solve();

    return 0;
}