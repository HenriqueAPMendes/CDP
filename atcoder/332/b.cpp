#include <bits/stdc++.h>
using namespace std;

int main () {
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    int k, g, m;
    int glass = 0, mug = 0;
    cin >> k >> g >> m;

    while (k--){
        if (glass == g) glass = 0;
        else if (mug == 0) mug = m;
        else {
            if (mug >= g-glass) {mug -= g-glass; glass = g;}
            else {glass += mug; mug = 0;}
        }
    }

    cout << glass << " " << mug << '\n';

    return 0;
}