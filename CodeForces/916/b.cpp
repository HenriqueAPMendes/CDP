#include <bits/stdc++.h>
using namespace std;

#define MAX 2123435
#define ll long long
#define ii pair<int,int>
#define vi vector<int>
#define vii vector<ii>
#define endl '\n'

void solve(){
    int n, k; cin >> n >> k;
    for (int i = n-k; i <= n; i++) cout << i << ' ';
    for (int i = n-k-1; i > 0; i--) cout << i << ' ';
    cout << endl;
}

int main(){
    cin.tie(0); cout.tie(0);
    ios_base::sync_with_stdio(0);

    int t;
    cin >> t;
    while(t--)
        solve();

    return 0;
}