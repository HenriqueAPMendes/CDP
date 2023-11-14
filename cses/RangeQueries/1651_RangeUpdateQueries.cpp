#include <bits/stdc++.h>
using namespace std;


#define left(p) (2*p+1)
#define right(p) (2*p+2)

#define ll long long

#define MAX 212345
int n;
vector<ll> st(4*MAX, 0), lz(4*MAX, 0), v(MAX, 0);

void build(int p, int l, int r){

    if(l==r) { st[p] = v[l]; return; }
    int m = (l+r)>>1;

    build(left(p), l, m);
    build(right(p), m+1, r);

    st[p] = st[left(p)] + st[right(p)];
}

void unlazy(int p, int tl, int tr){
    if(lz[p] == 0) return;
    st[p] = lz[p];
    if(tl != tr){
        lz[left(p)] = lz[p];
        lz[right(p)] = lz[p];
    }
    
    lz[p] = 0;
}


void update(int p, int tl, int tr, int l, int r, int v){
    unlazy(p, tl, tr);
    
    if(tl > r || tr < l) return;

    if(tl >= l && tr <= r){
        lz[p] = v;
        unlazy(p, tl, tr);
        return;
    }

    int m = (tl+tr)>>1;
    update(left(p), tl, m, l, r ,v);
    update(right(p), m+1, tr, l, r, v);
    
    st[p] = (st[left(p)] + st[right(p)]);
}


int query(int p, int l, int r, int i){
    unlazy(p, l, r);
    
    int m = (l+r)>>1;
    if (m == i && l == r) return st[p];
    if (m < i) return query(left(p), l, m, i);
    else return query(right(p), m+1, r, i);
}

int main(){
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    int n, q, l, r, op, x;
    cin >> n >> q;
    for (int i = 0; i < n; i++) cin >> v[i];
    build(0, 0, n-1);

    while(q--){
        cin >> op;
        if (op == 1){
            cin >> l >> r >> x;
            update(0, 0, n-1, l, r, x);
        }
        else{
            cin >> x;
            cout << query(0, 0, n-1, x);
        }        
    }

    return 0;
}
