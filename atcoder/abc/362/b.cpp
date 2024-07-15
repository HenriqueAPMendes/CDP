#include <bits/stdc++.h>
using namespace std;

#define int long long int
#define endl '\n'
#define ii pair<int,int>
#define vi vector<int>
#define vii vector<ii>
#define vvi vector<vi>

int dot(ii a, ii b){
    return a.first*b.first + a.second*b.second;
}

void solve(){
    int xa, ya, xb, yb, xc, yc;
    cin >> xa >> ya >> xb >> yb >> xc >> yc;
    ii ab = {xb-xa, yb-ya};
    ii bc = {xc-xb, yc-yb};
    ii ac = {xc-xa, yc-ya};

    if (dot(ab, ac) == 0 || dot(ab, bc) == 0 || dot(bc, ac) == 0)
        cout << "Yes" << endl;
    else
        cout << "No" << endl;
}

signed main(){
    cin.tie(0); cout.tie(0);
    ios_base::sync_with_stdio(0);
    solve();
    return 0;
}