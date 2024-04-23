#include <bits/stdc++.h>
using namespace std;

#define MAX 212345      
#define ll long long

vector<ll> w(MAX);

int main(){
    cin.tie(0); cout.tie(0);
    ios_base::sync_with_stdio(0);

    int n;
    ll x;
    cin >> n >> x;

    for (int i = 0; i < n; i++) cin >> w[i];

    sort(w.begin(), w.begin()+n);

    int l = 0, r = n-1;
    int ans = 0;
    while(l < r){
        ans++;
        if (w[l]+w[r] <= x) l++;
        r--;
    }
    if (l == r) ans++;

    cout << ans << endl;

    return 0;
}