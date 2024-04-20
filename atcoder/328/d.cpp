#include <bits/stdc++.h>
using namespace std;

int main (){
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    
    string s, ans;
    cin >> s;
    
    for (int i = 0; i < (int)s.length(); i++){
        ans += s[i];
        while (ans.length() >= 3 && ans.substr(ans.length()-3,3) == "ABC") ans = ans.substr(0, ans.length()-3);
    }
    
    cout << ans << '\n';

    return 0;
}