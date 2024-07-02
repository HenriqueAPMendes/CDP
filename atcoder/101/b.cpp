#include <bits/stdc++.h>
using namespace std;

#define int long long int
#define endl '\n'
#define vi vector<int>
#define ii pair<int,int>
#define vii vector<ii>
#define vvi vector<vi>

void solve(){
    int n; cin >> n;
    int sum = 0;
    int startn = n;
    while(n != 0){
        sum += n%10;
        n/=10;
    }

    cout << (startn%sum ? "No" : "Yes" ) << endl;
}

signed main(){
    cin.tie(0); cout.tie(0);
    ios_base::sync_with_stdio(0);
    solve();
    return 0;
}