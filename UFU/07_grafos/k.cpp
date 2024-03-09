#include <bits/stdc++.h>
using namespace std;

#define int long long int
#define endl '\n'
#define vi vector<int>
#define ii pair<int,int>

signed main(){
    cin.tie(0); cout.tie(0);
    ios_base::sync_with_stdio(0);

    int a, b;
    cin >> a >> b;
    cout << ((a >= 2000 || b >= 2019) ? "Sim" : "Nao") << endl;

    return 0;
}