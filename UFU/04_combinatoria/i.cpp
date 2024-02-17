#include <bits/stdc++.h>
using namespace std;

#define int long long int
#define vi vector<int>
#define ii pair<int,int>
#define endl '\n'

int expbin(int a, int b){
    if (b == 0) return 1;
    if (b&1) return a*expbin(a,b-1);
    int x = expbin(a,b/2);
    return x*x;
}

signed main(){
    cin.tie(0); cout.tie(0);
    ios_base::sync_with_stdio(0);


    int n, v;
    cin >> n >> v;
    cout << expbin(v, n) << endl;

    return 0;
}