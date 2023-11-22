#include <bits/stdc++.h>
using namespace std;

int main (){
    cin.tie(0); cout.tie(0);
    ios_base::sync_with_stdio(0);

    int n, x, ans = 0;
    cin >> n;
    while(n--){
        cin >> x;
        if (x != 1) ans++;
    }

    cout << ans << '\n';

    return 0;
}