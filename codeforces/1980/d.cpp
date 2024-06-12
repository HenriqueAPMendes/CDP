#include <bits/stdc++.h>
using namespace std;

#define int long long int
#define endl '\n'
#define vi vector<int>

int gcd(int a, int b){
    if (b == 0) return a;
    return gcd(b, a%b);
}

void solve(){
    int n; cin >> n;
    vi a(n), b(n-1);
    for (int i = 0; i < n; i++) cin >> a[i];
    for (int i = 0; i < n-1; i++) b[i] = gcd(a[i], a[i+1]);

    // for (auto x : a) cout << x << ' '; cout << endl;
    // for (auto x : b) cout << x << ' '; cout << endl;

    int n_decreasing = 0, index = -1;
    for (int i = 0; i < n-2; i++)
        if (b[i] > b[i+1]) { index = i; break; }

    if (index == -1) { cout << "YES" << endl; return; }

    // removendo a[i]
    vi a1 (n-1); int k=0;
    for(int i=0; i<n; i++){
        if(i != index){
            a1[k++] = a[i];
        }
    }
    vi b1(n-2);
    for (int i = 0; i < n-2; i++) b1[i] = gcd(a1[i], a1[i+1]);
    n_decreasing = 0;
    for (int i = 0; i < n-3; i++)
        if (b1[i] > b1[i+1]) n_decreasing++;
    if (n_decreasing == 0) { cout << "YES" << endl; return; }

    // removendo a[i+1]
    vi a2 (n-1); k=0;
    for(int i=0; i<a.size(); i++){
        if(i != index+1){
            a2[k++] = a[i];
        }
    }
    vi b2(n-2);
    for (int i = 0; i < n-2; i++) b2[i] = gcd(a2[i], a2[i+1]);
    n_decreasing = 0;
    for (int i = 0; i < n-3; i++)
        if (b2[i] > b2[i+1]) n_decreasing++;
    if (n_decreasing == 0) { cout << "YES" << endl; return; }

    // removendo a[i+2]
    vi a3 (n-1); k=0;
    for(int i=0; i<a.size(); i++){
        if(i != index+2){
            a3[k++] = a[i];
        }
    }
    vi b3(n-2);
    for (int i = 0; i < n-2; i++) b3[i] = gcd(a3[i], a3[i+1]);
    n_decreasing = 0;
    for (int i = 0; i < n-3; i++)
        if (b3[i] > b3[i+1]) n_decreasing++;
    if (n_decreasing == 0) { cout << "YES" << endl; return; }

    // for (auto x : b3) cout << x << ' '; cout << endl;


    cout << "NO" << endl;
}

signed main(){
    cin.tie(0); cout.tie(0);
    ios_base::sync_with_stdio(0);
    int t; cin >> t;
    while(t--) solve();
    return 0;
}