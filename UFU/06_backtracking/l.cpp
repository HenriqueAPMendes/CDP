#include <bits/stdc++.h>
using namespace std;

#define int long long int
#define vi vector<int>
#define endl '\n'

signed main(){
    cin.tie(0); cout.tie(0);
    ios_base::sync_with_stdio(0);

    map<int,int> idades;
    int x;
    while(cin >> x)
        idades[x]++;

    for (auto &[a,b] : idades) cout << a << ' ' << b << endl;

    return 0;
}