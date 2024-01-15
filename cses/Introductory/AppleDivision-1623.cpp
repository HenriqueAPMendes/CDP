#include <bits/stdc++.h>
using namespace std;

#define ll long long

int n;
ll ans = 1e15;
vector<ll> v(20);

void backtrack(int i, ll lsum, ll rsum){
    if (i == n) { ans = min(ans,abs(lsum-rsum)); return; }
    backtrack(i+1, lsum+v[i], rsum);
    backtrack(i+1, lsum, rsum+v[i]);
}


int main(){
    cin.tie(0); cout.tie(0);
    ios_base::sync_with_stdio(0);

    cin >> n;
    for (int i = 0; i < n; i++) cin >> v[i];

    backtrack(0,0,0);

    cout << ans << endl;

    return 0;
}