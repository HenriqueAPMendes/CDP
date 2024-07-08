#include <bits/stdc++.h>
using namespace std;

#define int long long int
#define endl '\n'
#define vi vector<int>
#define ii pair<int,int>

void solve(){
    int n; cin >> n;
    vector<vi> a(n, vi(n));
    for (int i = 0; i < n; i++)    
        for (int j = 0; j < n; j++) {
            char c; cin >> c;
            a[i][j] = c-'0';
        }

    
    // checa 1,2,3
    // xx
    // x
    int m1 = 0;
    bool ok1 = true;
    for (m1 = 1; m1 <= n/2; m1++){
        for (int i = 0; i < 2*m1-1; i++){
            int c1 = i < m1 ? a[i][m1-1] : a[m1-1][2*m1-2-i];
            int c2 = i < m1 ? a[m1-1][n-1-i] : a[2*m1-2-i][n-m1];
            int c3 = i < m1 ? a[n-m1][i] : a[n-2*m1+1+i][m1-1];
            // int c4 = i < m1 ? a[n-1-i][n-m1] : a[n-m1][n-2*m1+1+i];
            if (!(c1 == c2 && c2 == c3)) {m1--; ok1 = false; break;}
        }
        if (!ok1) break;
    }
    if (ok1) m1--; // saiu do loop pq n == n/2 + 1


    // checa 1,2,4
    // xx
    //  x
    int m2 = 0;
    bool ok2 = true;
    for (m2 = 1; m2 <= n/2; m2++){
        for (int i = 0; i < 2*m2-1; i++){
            int c1 = i < m2 ? a[i][m2-1] : a[m2-1][2*m2-2-i];
            int c2 = i < m2 ? a[m2-1][n-1-i] : a[2*m2-2-i][n-m2];
            // int c3 = i < m2 ? a[n-m2][i] : a[n-2*m2+1+i][m2-1];
            int c4 = i < m2 ? a[n-1-i][n-m2] : a[n-m2][n-2*m2+1+i];
            if (!(c1 == c2 && c2 == c4)) {m2--; ok2 = false; break;}
        }
        if (!ok2) break;
    }
    if (ok2) m2--; // saiu do loop pq n == n/2 + 1


    // checa 1,3,4
    // x
    // xx
    int m3 = 0;
    bool ok3 = true;
    for (m3 = 1; m3 <= n/2; m3++){
        for (int i = 0; i < 2*m3-1; i++){
            int c1 = i < m3 ? a[i][m3-1] : a[m3-1][2*m3-2-i];
            // int c2 = i < m3 ? a[m3-1][n-1-i] : a[2*m3-2-i][n-m3];
            int c3 = i < m3 ? a[n-m3][i] : a[n-2*m3+1+i][m3-1];
            int c4 = i < m3 ? a[n-1-i][n-m3] : a[n-m3][n-2*m3+1+i];
            if (!(c1 == c4 && c4 == c3)) {m3--; ok3 = false; break;}
        }
        if (!ok3) break;
    }
    if (ok3) m3--; // saiu do loop pq n == n/2 + 1


    // checa 2,3,4
    //  x
    // xx
   int m4 = 0;
    bool ok4 = true;
    for (m4 = 1; m4 <= n/2; m4++){
        for (int i = 0; i < 2*m4-1; i++){
            // int c1 = i < m4 ? a[i][m4-1] : a[m4-1][2*m4-2-i];
            int c2 = i < m4 ? a[m4-1][n-1-i] : a[2*m4-2-i][n-m4];
            int c3 = i < m4 ? a[n-m4][i] : a[n-2*m4+1+i][m4-1];
            int c4 = i < m4 ? a[n-1-i][n-m4] : a[n-m4][n-2*m4+1+i];
            if (!(c4 == c2 && c2 == c3)) {m4--; ok4 = false; break;}
        }
        if (!ok4) break;
    }
    if (ok4) m4--; // saiu do loop pq n == n/2 + 1

    int m = max(m1, max(m2, max(m3, m4)));
    cout << m << endl;
}

signed main(){
    cin.tie(0); cout.tie(0);
    ios_base::sync_with_stdio(0);
    solve();
    return 0;
}