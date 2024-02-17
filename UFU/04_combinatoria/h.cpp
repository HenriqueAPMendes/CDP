#include <bits/stdc++.h>
using namespace std;

#define int long long int
#define vi vector<int>
#define ii pair<int,int>
#define endl '\n'

int fact(int n){
    int ans = 1;
    for (int i = 1; i <= n; i++) ans *= i;
    return ans;
}

int comb(int n, int k){
    int ans = fact(n)/(fact(n-k));
    return ans;
}


signed main(){
    cin.tie(0); cout.tie(0);
    ios_base::sync_with_stdio(0);

    int x;
    while(cin >> x, x){
        int ans = 1;

        int permutations = fact(x-3);
        ans = permutations * comb(x-2, 3);
        // cout << permutations << ' ' << comb(x-2, 3) << ' ';
        cout << comb(x,3)*fact(x-3)/6 << endl;
        // cout << ans << endl;
    }

    return 0;
}