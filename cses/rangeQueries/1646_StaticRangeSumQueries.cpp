#include <bits/stdc++.h>
using namespace std;

#define MAX 212345

long long n, q, l, r, i;
vector<long long> v(MAX, 0), p(MAX, 0);

int main (){
    cin >> n >> q;
    for (i = 0; i < n; i++) cin >> v[i];
    p[0] = v[0];
    for (i = 1; i < n; i++) p[i] = p[i-1] + v[i];

    while(q--){
        cin >> l >> r;
        l--;r--;
        if (l == 0) cout << p[r] << '\n';
        else cout << p[r] - p[l-1] << '\n';
    }

    return 0;
}