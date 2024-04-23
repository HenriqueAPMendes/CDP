#include <bits/stdc++.h>
using namespace std;

int main (){
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    string s;
    cin >> s;

    int ans = 1;
    int current = 1;
    for (int i = 1; i < (int)s.length(); i++){
        if (s[i] == s[i-1]) current++;
        else current = 1;
        ans = max(ans, current);
    }

    cout << ans << endl;

    return 0;
}