#include <bits/stdc++.h>
using namespace std;

int main(){  
    setlocale(LC_ALL, "portuguese-brazilian");
    string s; getline(cin,s);
    int t; cin >> t;
    t %= 26;

    for (int i = 0; i < (int)s.length(); i++){
        
        if (s[i] == ' ') continue;
        if (s[i] >= 'A' and s[i] <= 'Z' and s[i]+t > 'Z') s[i] = 'A'+26-t;
        else if (s[i] >= 'a' and s[i] <= 'z' and s[i]+t > 'z') s[i] = 'a'+26-t;
        else s[i] =  s[i]+t;
    }
    cout << s << endl;

    return 0;
}