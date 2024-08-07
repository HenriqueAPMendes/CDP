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
        nodes.assign(2*size-1, NEUTRAL_ELEMENT);
    }

    void set(int i, int x, int ls, int rs){
        if (rs-ls == 1){
            nodes[x].sum++;
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

void solve() {
    int n; cin >> n;
    st.init(n+1);
    for (int i = 0; i < n; i++){
        int x; cin >> x;
        st.set(x);
        cout << st.query(x+1, n+1).sum << (i == n-1 ? '\n' : ' ');
    }   
}

signed main(){
    cin.tie(0); cout.tie(0);
    ios_base::sync_with_stdio(0);
    solve();
    return 0;
}