#include <bits/stdc++.h>
using namespace std;

int main(){
    cin.tie(0); cout.tie(0);
    ios_base::sync_with_stdio(0);

    string s;
    queue<string> names;
    while(cin >> s){
        //“da”, “de”, “do”, “dos” ou “e”
        if (s!= "da" and s != "de" and s != "do" and s != "dos" and s != "e") names.push(s);
    }

    cout << names.front() << ' ';
    names.pop();
    while(!names.empty()){
        string name = names.front(); names.pop();
        if(names.empty()) cout << name << endl;
        else cout << name.substr(0,1) + ". ";
    }

    return 0;
}