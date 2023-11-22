#include <bits/stdc++.h>
using namespace std;

#define MAX 1123



int n, m, l, x, k;
bitset<MAX> state;
vector<bitset<MAX>> connections(MAX);


#define left(p) ((p) << 1 )
#define right(p) (left(p)+1)
int a[MAX], st[4*MAX];

int _build(int p, int l, int r){
    int m = (l+r)/2;
    if (l == r) return st[p] = state[l];
    return st[p] = _build(left(p), l, m) + _build(right(p), m+1, r);
}
int _buildXor(int p, int l, int r, int i){
    int m = (l+r)/2;
    if (l == r) return st[p] = connections[i][l];
    return st[p] = _build(left(p), l, m) + _build(right(p), m+1, r);
}

int _update(int p, int l, int r, int i, int val){
    if (i < l || i > r) return st[p]; //nao altera
    if (i == l && l == r) return st[p] = val; //folha
    int m = (l+r)/2;
    return st[p] = _update(left(p), l, m, i, val) + _update(right(p), m+1, r, i, val);
}
int _query(int p, int l, int r, int i, int j){
    if (j < l || i > r) return 0; //neutro aditivo
    if (i <= l && j >= r) return st[p]; //intervalo totalmente contido
    int m = (l+r)/2;
    return _query(left(p), l, m, i, j) + _query(right(p), m+1, r, i, j);
}

int _updateXor(int p, int l, int r, int i, int val){
    if (i < l || i > r) return st[p]; //nao altera
    if (i == l && l == r) return st[p] = val; //folha
    int m = (l+r)/2;
    return st[p] = _update(left(p), l, m, i, val) ^ _update(right(p), m+1, r, i, val);
}
int _queryXor(int p, int l, int r, int i, int j){
    if (j < l || i > r) return 0; //neutro aditivo
    if (i <= l && j >= r) return st[p]; //intervalo totalmente contido
    int m = (l+r)/2;
    return _query(left(p), l, m, i, j) ^ _query(right(p), m+1, r, i, j);
}


int calcXor(){
    int ans = 0;
    for (int i = 0; i < m; i++){
        _buildXor(1, 0, n-1, i);
        ans = _queryXor(1, 0, n-1, 0, n-1);
        if (ans == 0) return 1;
    }
    return 0;
}

int main (){
    cin.tie(0); cout.tie(0);
    ios_base::sync_with_stdio(0);

    cin >> n >> m;
    cin >> l;
    for (int i = 0; i < l; i++) {
        cin >> x;
        state[x-1] = 1;
    }

    for (int i = 0; i < n; i++){
        cin >> k;
        for (int j = 0; j < k; j++){
            cin >> x;
            connections[x-1][i] = 1;
        }    
    }
    if (calcXor()){
        cout << -1 << endl;
        return 0;
    }

    int ans = 0;
    while(1){
        for (int i = 0; i < n; i++){
            ans++;
            for (int j = 0; j < n; j++){
                if (connections[i][j]){
                     state[j] = state[j] ^ 1;
                    _update(1, 0, n-1, j, state[j]);
                    
                }
                x = _query(1, 0, n-1, 0, n-1);
                cout << x << endl;
                if (x == 0){
                    cout << ans << endl;
                    return 0;
                }  
            }
        }
    }

    return 0;
}