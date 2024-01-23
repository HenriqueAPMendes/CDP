#include <bits/stdc++.h>
using namespace std;

int main(){
    cin.tie(0); cout.tie(0);
    ios_base::sync_with_stdio(0);

    string s;
    getline(cin, s);

    int at = s.find('@');
    string user = s.substr(0,at);
    string domain = s.substr(at+1, s.length()-at-1);
    
    bool valid = true;

    for (int i = 0; i < (int)user.length(); i++){
        if ((s[i] >= 'A' and s[i] <= 'Z') or 
            (s[i] >= 'a' and s[i] <= 'z') or 
            (s[i] >= '0' and s[i] <= '9') or
            s[i] == '.' or s[i] == '_') continue;
        valid = false;
    }
    
    for (int i = 0; i < (int)domain.length(); i++){
        if ((domain[i] >= 'a' and domain[i] <= 'z') or domain[i] == '.') continue;
        cout << domain[i] << endl;
        valid = false;
    }
    if (domain[domain.length()-1] == '.') valid = false;

    cout << (valid ? 1 : 0) << endl;

    return 0;
}