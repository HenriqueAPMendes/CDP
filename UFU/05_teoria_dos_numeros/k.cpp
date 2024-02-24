#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define int long long int
#define vi vector<int>

int totiente(int n){
    int ans = n;
    for (int i = 2; i*i <= n; i++){
        if (n%i == 0){
            while (n%i == 0)
                n /= i;
            ans -= ans/i;
            
        }
    }
    if (n > 1)
        ans -= ans/n;
    return ans;
}

signed main(){
    cin.tie(0); cout.tie(0);
    ios_base::sync_with_stdio(0);

    int n; cin >> n;
    cout << totiente(n) << endl;

    return 0;
}