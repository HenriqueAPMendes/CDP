#include<bits/stdc++.h>
using namespace std;

#define int unsigned long long int
#define endl '\n'
#define vi vector<int>
#define ii pair<int,int>

#define eps 1e-6

signed main(){
    cin.tie(0); cout.tie(0);
    ios_base::sync_with_stdio(0);

    int n; cin >> n;
    while(n--){
        double x, a, b;
        cin >> x >> a >> b;

        if (x - eps > a && x + eps < b) cout << "True\n";
        else cout << "False\n";

    }

    return 0;
}