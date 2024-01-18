#include <bits/stdc++.h>
using namespace std;

#define MAX 2123435
#define ll long long
#define ii pair<int,int>
#define vi vector<int>
#define vii vector<ii>
#define endl '\n'

vi a(MAX), b(MAX), presum(MAX), tree(4*MAX);

void build(int node, int start, int end){
    if (start == end) tree[node] = b[start];
    else{
        int mid = (start+end)>>1;

        build(2*node, start, mid);
        build(2*node+1, mid+1, end);

        tree[node] = max(tree[2*node], tree[2*node+1]);
    }
}

int query(int node, int start, int end, int l, int r){
    if (r < start or end < l) return -1; // max neutral
    if (l<=start and end<=r) return tree[node];

    int mid = (start+end)>>1;
    int p1 = query(2*node, start, mid, l, r);
    int p2 = query(2*node+1, mid+1, end, l, r);
    return max(p1, p2);
}


void solve(){
    int n, k;
    cin >> n >> k;
    for (int i = 0; i < n; i++) cin >> a[i];
    for (int i = 0; i < n; i++) cin >> b[i];

    presum[0]=a[0];
    for (int i = 1; i < n; i++) presum[i] = presum[i-1]+a[i];

    build(1, 0, n-1);

    int maxExp = 0;

    for (int i = 1; i <= k; i++){
        int exp = presum[i-1];
        exp += (k-i)*query(1,0,n-1,0,i-1);
        maxExp = max(exp, maxExp);
        if (i == n) break;
    }

    cout << maxExp << endl;
}

int main(){
    cin.tie(0); cout.tie(0);
    ios_base::sync_with_stdio(0);

    int t;
    cin >> t;
    while(t--)
        solve();

    return 0;
}