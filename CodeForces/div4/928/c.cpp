#include <bits/stdc++.h>
using namespace std;

#define int long long int 
#define endl '\n'
#define vi vector<int>

vi dados(212345);
vi presum(212345);

void calcSum(int i){
    int start = i;
    int ans = 0;
    while(i > 0){
        ans += i%10;
        i /= 10;
    }
    dados[start] = ans;
}

void solve(){
    int n; cin >> n;

    int ans = presum[n];
    cout << ans << endl;

}

signed main(){
    cin.tie(0); cout.tie(0);
    ios_base::sync_with_stdio(0);

    for (int i = 1; i < 200001; i++) calcSum(i);
    presum[0] = dados[0];
    for (int i = 1; i < 200001; i++) presum[i] = presum[i-1]+dados[i];
    // for (int i = 0; i < 200001; i++) cout << dados[i] << ' '; cout << endl;

    int t; cin >> t;
    while(t--) solve();

    return 0;
}