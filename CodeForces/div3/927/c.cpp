#include <bits/stdc++.h>
using namespace std;

#define int long long int
#define ii pair<int,int>
#define endl '\n'
#define vi vector<int>


void solve(){
    int n, m;
    cin >> n >> m;
    vi a(n);
    for (int i = 0; i < n; i++) cin >> a[i], a[i] %= m;
    string s; cin >> s;
    
    int prod = 1;
    for (int i = 0; i < n; i++) prod *= a[i];

    int left = 0, right = n-1;
    for (int i = 0; i < s.length(); i++){
        cout << prod%m << ' ';
        if (s[i] == 'L')
            if (a[left] != 0) prod /= a[left++];
            else left++;
        else 
            if (a[right] != 0) prod /= a[right--];
            else right--;
    }
    cout << endl;
}

signed main(){
    cin.tie(0); cout.tie(0);
    ios_base::sync_with_stdio(0);

    int t; cin >> t;
    while(t--) solve();

    return 0;
}