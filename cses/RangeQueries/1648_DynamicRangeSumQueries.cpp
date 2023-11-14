#include <bits/stdc++.h>
using namespace std;
#define int long long

int left(int p) { return p << 1; }
int right(int p) { return left(p) + 1; }

#define MAX 212345

vector<int> v(MAX,0), st(4*MAX,0);

int build(int p, int l, int r){
    if (l == r) return st[p] = v[l];
    int m = (l+r)/2;
    return st[p] = build(left(p), l, m) + build(right(p), m+1, r);
}

int update(int p, int l, int r, int i, int val){
    if (l == r && l == i) return st[p] = val;
    if (i < l || i > r) return st[p];
    int m = (l+r)/2;
    return st[p] = update(left(p), l, m, i, val) + update(right(p), m+1, r, i, val);
}

int query(int p, int l, int r, int i, int j){
    if (j < l || i > r) return 0;
    if (i <= l && j >= r) return st[p];
    int m = (l+r)/2;
    return query(left(p), l, m, i, j) + query(right(p), m+1, r, i, j);
}

signed main(){
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    int n, q, op, a, b;
    cin >> n >> q;
    for (int i = 0; i < n; i++) cin >> v[i];
    build(1, 0, n-1);
    while(q--){
        cin >> op >> a >> b;
        a--;
        if (op == 1) update(1, 0, n-1, a, b);
        else cout << query(1, 0, n-1, a, b-1) << '\n';
    }

    return 0;
}