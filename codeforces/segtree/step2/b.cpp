#include <bits/stdc++.h>
using namespace std;

#define int long long int
// #define endl '\n'
#define vi vector<int>

struct node {
    int sum;
};

vi a;

struct segtree {
    int size;
    vector<node> nodes;

    node NEUTRAL_ELEMENT = {0};

    node merge(node a, node b){
        return {a.sum + b.sum};
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

    void set(int i, int x, int l, int r){
        if (r-l == 1){
            nodes[x] = single(abs(nodes[x].sum-1));
            return;
        }
        int m = (l+r)/2;
        if (i < m) set(i, 2*x+1, l, m);
        else set(i, 2*x+2, m, r);
        nodes[x] = merge(nodes[2*x+1], nodes[2*x+2]);
    }

    void set(int i) {
        set(i, 0, 0, size);
    }

    node query(int l, int r, int x, int ls, int rs){
        if (r <= ls || l >= rs) return NEUTRAL_ELEMENT;
        if (l <= ls && rs <= r) return nodes[x];
        int m = (ls+rs) / 2;
        node n1 = query(l, r, 2*x+1, ls, m);
        node n2 = query(l, r, 2*x+2, m, rs);
        return merge(n1, n2);
    }

    node query(int l, int r) {
        return query(l, r, 0, 0, size);
    }

    void init(int n) {
        size = 1;
        while(size < n) size *= 2;
        nodes.assign(2*size-1, NEUTRAL_ELEMENT);
        build(0, 0, size);
    }
};

segtree st;

bool query(int m, int k){
    int sum = st.query(0,m).sum;
    return (sum >= k+1);
}

void solve() {
    int n, m;
    cin >> n >> m;
    a.resize(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    st.init(n);
    
    while(m--) {
        int op; cin >> op;
        if (op == 1){
            int i; cin >> i; 
            st.set(i);
        } else {
            int k; cin >> k;
            // bbin
            int l = 0;
            int r = n;
            // cout << "searching for sum: " << k+1 << endl;
            while(r-l >= 1){
                int m = (l+r)/2;
                // cout << l << ' ' << r << ' ';
                if (query(m, k)){
                    r = m;
                } else {
                    l = m+1;
                }
            }
            cout << l-1 << endl;
        }    
    }
}

signed main(){
    cin.tie(0); cout.tie(0);
    ios_base::sync_with_stdio(0);
    solve();
    return 0;
}