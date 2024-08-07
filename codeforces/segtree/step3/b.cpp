#include <bits/stdc++.h>
using namespace std;

#define int long long int
// #define endl '\n'
#define vi vector<int>

struct node {
    int sum;
};

struct segtree {
    int size;
    vector<node> nodes;

    node NEUTRAL_ELEMENT = {0};

    node merge(node a, node b){
        return {a.sum+b.sum};
    }

    void init(int n){
        size = 1;
        while(size < n) size*=2;
        nodes.assign(2*size-1, {1}); set(0);
        for (int i = n; i <= size; i++) set(i);
    }

    void set(int i, int x, int ls, int rs){
        if (rs-ls == 1){
            nodes[x].sum = 0;
            return ;
        }
        int ms = (ls+rs)/2;
        if (i < ms) set(i,2*x+1,ls,ms);
        else set(i, 2*x+2,ms,rs);
        nodes[x] = merge(nodes[2*x+1], nodes[2*x+2]);
    }

    void set(int i){
        set(i,0,0,size);
    }

    node query(int l, int r, int x, int ls, int rs){
        if (rs <= l || ls >= r) return NEUTRAL_ELEMENT;
        if (l <= ls && rs <= r) return nodes[x];
        int ms = (ls+rs)/2;
        node left = query(l,r,2*x+1, ls, ms);
        node right = query(l,r,2*x+2, ms, rs);
        return merge(left,right);
    }

    node query(int l, int r){
        return query(l, r, 0, 0, size);
    }

};

segtree st;
int n; 

// retorna elemento que tem exatamente a[i] numeros maiores que ele, busca binaria + query de soma 
// O(logn*logn)
int solve(int ai){
    int l = 0, r = n+1;
    while(r-l > 1) {
        int m = (l+r)/2;
        int sum = st.query(m+1, n+1).sum;
        cout << m+1 << ' ' << n << ' ' << sum << endl;
        if (sum == ai) return m;
        if (sum < ai){
            r = m;
        } else {
            l = m+1;
        }
    }
    // cout << l << endl;
    return l;
}

void solve() {
    cin >> n;
    vi a(n), ans(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    st.init(n+1);
    for (int i = 0; i < st.size; i++) cout << st.query(i,i+1).sum << ' '; cout << endl;
    for (int i = n-1; i >= 0; i--){
        ans[i] = solve(a[i]);
        cout << ans[i] << endl;
        st.set(ans[i]);
        for (int i = 0; i < st.size; i++) cout << st.query(i,i+1).sum << ' '; cout << endl;
    }   

    for (auto x : ans) cout << x << ' '; cout << endl;
}

signed main(){
    cin.tie(0); cout.tie(0);
    ios_base::sync_with_stdio(0);
    solve();
    return 0;
}