#include <bits/stdc++.h>
using namespace std;

#define ll long long

const int MAX = 212345;

vector<ll> a(MAX), tree(4*MAX), lazy(4*MAX);

void build(int node, int start, int end){
    if (start == end) tree[node] = a[start];
    else{
        int mid = (start+end)>>1;

        build(2*node,start,mid);
        build(2*node+1,mid+1,end);

        tree[node] = tree[2*node] + tree[2*node+1];
    }
}

void updateRange(int node, int start, int end, int l, int r, int val){
    if (lazy[node]){
        tree[node] += (end-start+1) * lazy[node];
        if (start != end){
            lazy[2*node] += lazy[node];
            lazy[2*node+1] += lazy[node];
        }
        lazy[node] = 0;
    }

    if (start>end || start>r || end<l) return;

    if (start>=l && end<=r){
        tree[node] += (end-start+1) * val;
        if (start != end){
            lazy[2*node] += val;
            lazy[2*node+1] += val;
        }
        return;
    }

    int mid = (start+end) >> 1;
    updateRange(2*node, start, mid, l, r, val);
    updateRange(2*node+1, mid+1, end, l, r, val);
    tree[node] = tree[2*node] + tree[2*node+1];
}

ll queryRange(int node, int start, int end, int l, int r){
    if (start>end || start>r || end<l) return 0;

    if (lazy[node]){
        tree[node] += (end-start+1) * lazy[node];
        if (start != end){
            lazy[2*node] += lazy[node];
            lazy[2*node+1] += lazy[node];
        }
        lazy[node] = 0;
    }

    if (start>=l && end<=r) return tree[node];

    int mid = (start+end)>>1;
    ll p1 = queryRange(2*node, start, mid, l, r);
    ll p2 = queryRange(2*node+1, mid+1, end, l, r);
    return (p1+p2);
}

int main (){
    cin.tie(0); cout.tie(0);
    ios_base::sync_with_stdio(0);

    int n, q;
    cin >> n >> q;
    for (int i = 0; i < n; i++) cin >> a[i];

    for (int i = 0; i < n; i++) cout << a[i] << ' ';
    cout << endl;

    build(1,0,n-1);
    
    int a,b,k,u,op;
    while(q--){
        cin >> op;
        if (op == 1){
            cin >> a >> b >> u;
            updateRange(1,0,n-1,a,b,u);
        }
        else{
            cin >> k;
            cout << queryRange(1,0,n-1,k,k) << '\n';
        }
    }

    return 0;
}