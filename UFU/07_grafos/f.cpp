#include <bits/stdc++.h>
using namespace std;

#define int long long int
#define endl '\n'
#define vi vector<int>
#define ii pair<int,int>

int fact(int x){
    int ans = 1;
    for (int i = 1; i <= x; i++) ans *= i;
    return ans;
}

signed main(){
    cin.tie(0); cout.tie(0);
    ios_base::sync_with_stdio(0);

    int x, y;
    while(cin >> x >> y){
        cout << (fact(x) + fact(y)) << endl;
    }

    return 0;
}