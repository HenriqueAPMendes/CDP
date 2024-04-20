#include <bits/stdc++.h>
using namespace std;

#define MAX 2123435
#define ll long long
#define ii pair<int,int>
#define vi vector<int>
#define vii vector<ii>
#define endl '\n'

vi a(MAX), b(MAX);

void solve(){
    int n, k;
    cin >> n >> k;
    cin >> a[0];
    for (int i = 1; i < n; i++) { cin >> a[i]; a[i]+=a[i-1]; }
    cin >> b[0];
    for (int i = 1; i < n; i++) { cin >> b[i]; b[i]=max(b[i], b[i-1]); }

    int maxExp = 0;

    for (int i = 1; i <= k; i++){
        int exp = a[i-1];
        exp += (k-i)*b[i-1];
        maxExp = max(exp, maxExp);
        if (i == n) break;
    }

    cout << maxExp << endl;
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