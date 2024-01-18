#include <bits/stdc++.h>
using namespace std;

#define MAX 212345
#define endl '\n'

vector<int> v(MAX), tree(4*MAX);

void build(int node, int start, int end){
    if (start == end) tree[node] = v[start];
    else{
        int mid = (start+end)>>1;

        build(2*node, start, mid);
        build(2*node+1, mid+1, end);

        tree[node] = max(tree[2*node], tree[2*node+1]);
    }
}

int query(int node, int start, int end, int x){
    if (start == end && tree[node] >= x){
        tree[node] -= x; // update
        return start+1; // indexed from 1
    }
    else if (start == end) return 0; // no hotel has at least x rooms
    else{
        int mid = (start+end)>>1;
        if (tree[2*node] >= x){ // left hotels first
            int ans = query(2*node, start, mid, x);
            tree[node] = max(tree[2*node],tree[2*node+1]); // because of update
            return ans;
        }
        else if (tree[2*node+1] >= x){
            int ans = query(2*node+1, mid+1, end, x);
            tree[node] = max(tree[2*node],tree[2*node+1]); // because of update
            return ans;
        }
        else return 0;     
    }
}

int main(){
    cin.tie(0); cout.tie(0);
    ios_base::sync_with_stdio(0);

    int n, m;
    cin >> n >> m;
    for (int i = 0; i < n; i++) cin >> v[i];

    build(1, 0, n-1);

    while(m--){
        int x;
        cin >> x;
        cout << query(1, 0, n-1, x) << ' ';
    }
    cout << endl;

    return 0;
}