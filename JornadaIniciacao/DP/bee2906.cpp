#include <bits/stdc++.h>
using namespace std;

int main (){
    cin.tie(0); cout.tie(0);
    ios_base::sync_with_stdio(0);

    int n;
    string s, localpart, provider;

    set<pair<string,string>> users;

    cin >> n;
    while(n--){
        cin >> s;
        int dot = s.find('.');
        int at = s.find('@');
        while(dot != -1 && dot <= at){
            s = s.replace(dot, 1, "");
            dot = s.find('.');
            at = s.find('@');
        }

        int plus = s.find('+');
        at = s.find('@');
        localpart =  (plus != -1) ? s.substr(0, plus): s.substr(0, at);
        provider = s.substr(at+1, s.length()-at);
        
        users.insert({localpart, provider});

    }
    cout << users.size() << endl;

    return 0;
}