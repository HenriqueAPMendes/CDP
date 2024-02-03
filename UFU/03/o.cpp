#include<bits/stdc++.h>
using namespace std;

#define int long long int
#define endl '\n'
#define vi vector<int>
#define ii pair<int,int>

int gcd(int a, int b){
    if (b == 0) return a;
    return gcd(b, a%b);
}

signed main(){
    cin.tie(0); cout.tie(0);
    ios_base::sync_with_stdio(0);

    int n; cin >> n;
    while(n--){
        int a, b; 
        cin >> a >> b;
        cout << gcd(a, b) << endl;
    }

    return 0;
}