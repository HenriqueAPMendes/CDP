#include <bits/stdc++.h>
using namespace std;

#define int long long int
#define endl '\n'
#define ii pair<int,int>
#define vi vector<int>
#define vvi vector<vi>
#define ii pair<int,int>
#define vii vector<ii>
#define vvii vector<vii>

void solve(){
    int x;
    for (int i = 0; i < 8; i++){
        cin >> x;
        if (x == 9){
            cout << "F" << endl; return;
        }
    }
    cout << "S" << endl;
}

signed main(){
    cin.tie(0); cout.tie(0);
    ios_base::sync_with_stdio(0);
    solve();
    return 0;
}