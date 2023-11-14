#include <bits/stdc++.h>
using namespace std;
#define ll long long

ll left(ll p) { return p << 1; }
ll right(ll p) { return left(p) + 1; }

#define MAX 212345
#define INF 1123456789

vector<ll> v(MAX,0), st(4*MAX,0);

ll build(ll p, ll l, ll r){
    if (l == r) return st[p] = v[l];
    ll m = (l+r)/2;
    return st[p] = min(build(left(p), l, m),build(right(p), m+1, r));
}

ll update(ll p, ll l, ll r, ll i, ll val){
    if (l == r && l == i) return st[p] = val;
    if (i < l || i > r) return st[p];
    ll m = (l+r)/2;
    return st[p] = min(update(left(p), l, m, i, val), update(right(p), m+1, r, i, val));
}

ll query(ll p, ll l, ll r, ll i, ll j){
    if (j < l || i > r) return INF;
    if (i <= l && j >= r) return st[p];
    ll m = (l+r)/2;
    return min(query(left(p), l, m, i, j), query(right(p), m+1, r, i, j));
}

int main(){
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    ll n, q, op, a, b;
    cin >> n >> q;
    for (ll i = 0; i < n; i++) cin >> v[i];
    build(1, 0, n-1); 

    while(q--){
        cin >> op >> a >> b;
        a--;
        if (op == 1) update(1, 0, n-1, a, b);
        else cout << query(1, 0, n-1, a, b-1) << '\n';
    }

    return 0;
}