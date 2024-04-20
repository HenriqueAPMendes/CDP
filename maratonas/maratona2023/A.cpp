#include <bits/stdc++.h>
using namespace std;

int main (){
    cin.tie(0); cout.tie(0);
    ios_base::sync_with_stdio(0);

    int n, h, x, ans = 0;
    cin >> n >> h;
    for (int i = 0; i < n; i++){
        cin >> x;
        if (x <= h) ans++;
    }

    cout << ans << endl;

    return 0;
}