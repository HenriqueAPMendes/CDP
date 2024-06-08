#include <bits/stdc++.h>
using namespace std;

#define int long long int
#define endl '\n'
#define vi vector<int>

vi indexes, tree, lazy;

void build(int node, int start, int end){
    if (start == end) tree[node] = indexes[start];
    else {
        int mid = (start+end)>>1;
        build(2*node, start, mid);
        build(2*node+1, mid+1, end);

        tree[node] = tree[2*node] + tree[2*node+1];
    }
}

void update(int node, int start, int end, int l, int r, int val){
    cout << node << ' ' << start << ' ' << end << ' ' << l << ' ' << r << endl;
    if (lazy[node]) {
        tree[node] += (end-start+1)*lazy[node];
        if (start != end) {
            lazy[2*node] += lazy[node];
            lazy[2*node+1] += lazy[node];
        }
        lazy[node]=0;
    }

    if (start > end || start > r || end < l) return;
    
    if (start >= l && end <= r){
        tree[node] += (end-start+1) * val;
        if (start != end){
            lazy[2*node] += val;
            lazy[2*node+1] += val;
        }
        return ;
    }

    int mid = (start+end)>>1;
    update(2*node, start, mid, l, r, val);
    update(2*node+1, mid+1, end, l, r, val);
    tree[node] = tree[2*node] + tree[2*node+1];
}

int query(int node, int start, int end, int l, int r) {
    cout << node << ' ' << start << ' ' << end << ' ' << l << ' ' << r << endl;
    if (start>end || start>r || end<l) return 0;
    if (lazy[node]) {
        tree[node] += (end-start+1)*lazy[node];
        if (start != end) {
            lazy[2*node] += lazy[node];
            lazy[2*node+1] += lazy[node];
        }
        lazy[node];
    }
    if (start >= l && end <= r) return tree[node];

    int mid = (start+end)>>1;
    int p1 = query(2*node, start, mid, l, r);
    int p2 = query(2*node+1, mid+1, end, l, r);
    return p1+p2;
}

void solve(){
    int n; cin >> n;
    vi v(n);
    for (int i = 0; i < n; i++) cin >> v[i];
    indexes = vi(n);
    tree = lazy = vi(4*n);
    for (int i = 0; i < n; i++) indexes[i] = i;
    build(1, 0, n-1);

    for (int j = 0; j < n; j++){
        cout << "====== " << j << " =======" << endl;
        int x; cin >> x; x--;
        int i = query(1, 0, n-1, x, x);
        cout << i << endl;
//        cout << v[i] << ' ';
        update(1, 0, n-1, i, n-1, -1);
    }
    cout << endl;
}

signed main(){
    cin.tie(0); cout.tie(0);
    ios_base::sync_with_stdio(0);

    solve();

    return 0;
}
