#include <bits/stdc++.h>
using namespace std;

#define int long long int
#define vi vector<int>
#define ii pair<int,int>
#define endl '\n'

string to_string128(__int128_t t){
    string ans;
    while (t > 0){
        ans += ('0'+t%10);
        t /= 10;
    }
    reverse(ans.begin(), ans.end());
    return ans;
}

__int128_t fact(int n){
    __int128_t ans = 1;
    for (int i = 1; i <= n; i++) ans *= i;
    return ans;
}

__int128_t comb(int n, int k){
    return (fact(n)/(fact(k)*fact(n-k)));
}

signed main(){
    cin.tie(0); cout.tie(0);
    ios_base::sync_with_stdio(0);

    int n, k;
    while(cin >> n >> k){
        if (n == k and n == 0) break;

        __int128_t ans = 1;
        int remaining = n;
        cout << n << ' ' << k << ' ' << n/k << ' ';
        for (int i = 0; i < n/k; i++){
            ans *= comb(n,k);
            n-=k;
        }
        cout << to_string128(ans) << endl;

    }

    return 0;
}