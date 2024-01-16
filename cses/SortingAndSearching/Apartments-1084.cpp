#include <bits/stdc++.h>
using namespace std;

#define MAX 212345

vector<int> apartment(MAX), sz(MAX);

int main(){
    cin.tie(0); cout.tie(0);
    ios_base::sync_with_stdio(0);

    int n, m, k;
    cin >> n >> m >> k;

    for (int i = 0; i < n; i++) cin >> sz[i];
    for (int i = 0; i < m; i++) cin >> apartment[i];

    sort(apartment.begin(), apartment.begin()+m);
    sort(sz.begin(), sz.begin()+n);

    // for (int i = 0; i < n; i++) cout << sz[i] << ' ';
    // cout << endl;
    // for (int i = 0; i < m; i++) cout << apartment[i] << ' ';
    // cout << endl;

    int ap, si, ans;
    ans = ap = si = 0;

    while(ap < m and si < n){
        if (apartment[ap] >= sz[si]-k and apartment[ap] <= sz[si]+k){
            ans++;
            ap++;
            si++;
        }
        else if (apartment[ap] > sz[si]+k) si++;
        else if (apartment[ap] < sz[si]-k) ap++;
    } 

    cout << ans << endl;

    return 0;
}