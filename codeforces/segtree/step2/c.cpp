#include <bits/stdc++.h>
using namespace std;
    
#define int long long int
// #define endl '\n'
#define vi vector<int>
    
struct node {
    int max;
};
    
vi a;
    
struct segtree {
    int size;
    vector<node> nodes;
    
    node NEUTRAL_ELEMENT = {0};
    
    node merge(node a, node b){
        return {max(a.max, b.max)};
    }
    
    node single(int v){
        return {v};
    }
    
    void build(int x, int l, int r) {
        if (r-l == 1) {
            if (l < a.size())
                nodes[x] = single(a[l]);
            return;
        }
        int m = (l+r) / 2;
        build(2*x+1, l, m);
        build(2*x+2, m, r);
        nodes[x] = merge(nodes[2*x+1], nodes[2*x+2]);
    }
    
    void set(int i, int v, int x, int ls, int rs){
        if (rs-ls == 1){
            nodes[x] = single(v);
            return;
        }
        int m = (ls+rs)/2;
        if (i < m) set(i, v, 2*x+1, ls, m);
        else set(i, v, 2*x+2, m, rs);
        nodes[x] = merge(nodes[2*x+1], nodes[2*x+2]);
    }
    
    void set(int i, int v) {
        set(i, v, 0, 0, size);
    }
    
    int query(int v, int x, int ls, int rs){
        if (rs-ls == 1) return ls;
        node left = nodes[2*x+1];
        node right = nodes[2*x+2];
        int m = (ls+rs) / 2;
        if (left.max >= v) return query(v, 2*x+1, ls, m);
        else return query(v, 2*x+2, m, rs);
    }
    
    int query(int x) {
        if (nodes[0].max < x) return -1;
        return query(x, 0, 0, size);
    }
    
    void init(int n) {
        size = 1;
        while(size < n) size *= 2;
        nodes.assign(2*size-1, NEUTRAL_ELEMENT);
        build(0, 0, size);
    }
};
    
segtree st;
    
    
void solve() {
    int n, m;
    cin >> n >> m;
    a.resize(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    st.init(n);
    
    while(m--) {
        int op; cin >> op;
        if (op == 1){
            int i, v; cin >> i >> v;
            st.set(i,v);
        } else {
            int x; cin >> x;
            cout << st.query(x) << endl;
        }    
    }
}
    
signed main(){
    cin.tie(0); cout.tie(0);
    ios_base::sync_with_stdio(0);
    solve();
    return 0;
}