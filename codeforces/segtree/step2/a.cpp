#include <bits/stdc++.h>
using namespace std;

#define int long long int
#define endl '\n'
#define vi vector<int>

struct node {
    int seg, pre, suf, sum;
};

vi a;

struct segtree {
    int size;
    vector<node> nodes;

    node NEUTRAL_ELEMENT = {0,0,0,0};

    node merge(node a, node b){
        node ans;
        ans.seg = max(a.suf+b.pre, max(a.seg, b.seg));
        ans.pre = max(a.pre, a.sum+b.pre);
        ans.suf = max(b.suf, a.suf+b.sum);
        ans.sum = a.sum + b.sum;
        return ans;
    }

    node single(int v){
        node ans;
        ans.seg = v;
        ans.pre = v;
        ans.suf = v;
        ans.sum = v;
        return ans;
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

    void set(int i, int v, int x, int l, int r){
        if (r-l == 1){
            nodes[x] = single(v);
            return;
        }
        int m = (l+r)/2;
        if (i < m) set(i, v, 2*x+1, l, m);
        else set(i, v, 2*x+2, m, r);
        nodes[x] = merge(nodes[2*x+1], nodes[2*x+2]);
    }

    void set(int i, int v) {
        set(i, v, 0, 0, size);
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

void solve() {
    int n, m;
    cin >> n >> m;
    a.resize(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    st.init(n);
    cout << max(st.query(0, n).seg, 0ll) << endl;
    while(m--) {
        int i, v; cin >> i >> v;
        st.set(i,v);
        cout << max(st.query(0,n).seg,0ll) << endl;
    }
}

signed main(){
    cin.tie(0); cout.tie(0);
    ios_base::sync_with_stdio(0);
    solve();
    return 0;
}