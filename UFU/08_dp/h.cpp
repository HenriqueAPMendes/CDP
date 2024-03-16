#include <bits/stdc++.h>
using namespace std;

#define int long long int
#define endl '\n'
#define vi vector<int>
#define ii pair<int,int>

signed main(){
    cin.tie(0); cout.tie(0);
    ios_base::sync_with_stdio(0);

    int q, d, p;
    while(cin >> q >> d >> p){
       int t = (q*d*p)/(p-q);
       cout << t << endl;
    }

    return 0;
}