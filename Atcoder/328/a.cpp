#include <bits/stdc++.h>
using namespace std;

int main (){
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    int n, x, ans=0, a;
    cin >> n >> x;
    while(n--){
        cin >> a;
        if (a <= x) ans+= a;
    }

    cout << ans << '\n';
    return 0;
}