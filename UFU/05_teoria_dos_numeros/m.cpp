#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define int long long int
#define vi vector<int>

signed main(){
    cin.tie(0); cout.tie(0);
    ios_base::sync_with_stdio(0);

    int n; cin >> n;
    vi prime(1123456, 1);

    // gera os primos até n
    int ans = 1;
    for (int i = 3; i <= n; i++){
        if (prime[i]) ans++;
        for (int j = 2*i; j <= n; j+=i){
            prime[j]=0;
        }
    }
    cout << ans-1 << endl;

    return 0;
}