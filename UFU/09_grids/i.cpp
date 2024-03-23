#include <bits/stdc++.h>
using namespace std;

#define int long long int
#define endl '\n'
#define vi vector<int>
#define ii pair<int,int>
#define vii vector<ii>
#define INF 1123456789012345

signed main(){
    cin.tie(0); cout.tie(0);
    ios_base::sync_with_stdio(0);

    int ax, ay;
    int bx, by;
    int cx, cy;
    int dx, dy;
    int rx, ry;
    while(cin >> ax >> ay >> bx >> by >> cx >> cy >> dx >> dy >> rx >> ry){
        if (rx >= ax && rx <= bx && ry >= by && ry <= cy) cout << 1 << endl;
        else cout << 0 << endl;
    }

    return 0;
}