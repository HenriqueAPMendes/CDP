#include <bits/stdc++.h>
using namespace std;

const int MAX = 212345;
#define ll long long

int main (){
    cin.tie(0); cout.tie(0);
    ios_base::sync_with_stdio(0);

    string s;
    cin >> s;
    
    int n = s.length();

    set<string> dic;

    for (int i = 0; i < n; i++){
        s = s.substr(1,n-1)+s[0];
        dic.insert(s);
    }

    set<string>::iterator first = dic.begin();
    set<string>::iterator last = dic.end(); last--;
    
    cout << *first << endl;
    cout << *last << endl;

    return 0;
}
