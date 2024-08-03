#include <bits/stdc++.h>
using namespace std;

#define endl '\n'

void solve() {
    int n, m;
    cin >> n >> m;
    map<string,string> ipToName;
    while(n--){
        string name, ip;
        cin >> name >> ip;
        ipToName[ip] = name;
    }
    while(m--){
        string command, ip;
        cin >> command >> ip;
        ip = ip.substr(0, ip.length()-1);
        cout << command << ' ' << ip << "; #" << ipToName[ip] << endl;
    }
}

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    solve();
    return 0;
}