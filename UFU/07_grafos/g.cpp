#include <bits/stdc++.h>
using namespace std;

#define int long long int
#define endl '\n'
#define vi vector<int>
#define ii pair<int,int>

int gcd(int a, int b){
    if (b == 0) return a;
    return gcd(b, a%b);
}

int lcm(int a, int b){
    return (a*b)/gcd(a,b);
}

signed main(){
    cin.tie(0); cout.tie(0);
    ios_base::sync_with_stdio(0);

    int t; cin >> t; t-=2;
    int a, b; cin >> a >> b;
    int ans = lcm(a,b);
    
    while(t--){
        cin >> a;
        ans = lcm(ans,a);
    }

    cout << ans << endl;

    return 0;
}