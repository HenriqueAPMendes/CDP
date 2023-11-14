#include <bits/stdc++.h>
using namespace std;

#define left(p) ((p)<<1)
#define right(p) (left(p)+1)

#define MAX 212345
#define INF 2123456789


vector<int> v(MAX,0), st(4*MAX,0);

int build(int p, int l, int r){
    int m = (l+r)/2;
    if (l == r) return st[p] = v[l];
    return st[p] = min(build(left(p), l, m), build(right(p), m+1, r));
}

int query(int p, int l, int r, int i, int j){
    if (j < l || i > r) return INF;
    int m = (l+r)/2;
    if (i <= l && j >= r) return st[p];
    return min(query(left(p), l, m, i, j), query(right(p), m+1, r, i, j));

}

int main(){
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    int n, q, l, r;
    cin >> n >> q;
    for (int i = 0; i < n; i++) cin >> v[i];
    build(1, 0, n-1);
    while(q--){
        cin >> l >> r;
        l--;r--;
        cout << query(1, 0, n-1, l, r) << '\n'; 
    }

    return 0;
}
