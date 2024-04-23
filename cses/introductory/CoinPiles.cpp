#include <bits/stdc++.h>
using namespace std;

int main() {
    int t, a, b;
    bool valid;
    cin >> t;
    for (int i = 0; i < t; i++) {
        valid = true;
        cin >> a >> b;
        int mod1 = a%3;
        int mod2 = b%3;
        if (a > 2*b or b > 2*a) valid = false;
        if ((mod1 == 0 and mod2 != 0) or (mod2 == 0 and mod1 != 0)) valid = false;
        if ((mod1 == 1 and mod2 != 2) or (mod2 == 1 and mod1 != 2)) valid = false;
        if ((mod1 == 2 and mod2 != 1) or (mod2 == 2 and mod1 != 1)) valid = false;
        if (valid) cout << "YES" << endl;
        else cout << "NO" << endl;
    }
    return 0;
}