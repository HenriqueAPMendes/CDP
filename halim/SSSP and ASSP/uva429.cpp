#include <bits/stdc++.h>
using namespace std;

vector<string> dic;

bool differByOne(string s1, string s2){
    if (s1.length() != s2.length()) return false;
    int diff = 0;
    for (int i = 0; i < s1.length(); i++)
        if (s1[i] != s2[i]) diff++;
    
    return (diff == 1);
}

int BFS(string s1, string s2){

map<string,int> d;
    d[s1] = 0;
    queue<string> q; q.push(s1);
    while(!q.empty()){
        string u = q.front(); q.pop();
        for (auto &v : dic){
            if (!d.count(v) && differByOne(u,v)){
                d[v] = d[u]+1;
                q.push(v);
            }
        }
    }

    return d[s2];
}

void solve(){
    string s;
    cin >> s;
    while(s != "*"){
        dic.push_back(s);
        cin >> s;
    }

    cin.ignore();

    string s1, s2;
    string line;
    while(getline(cin,line) && line != ""){
        stringstream ss(line);
        ss >> s1 >> s2;
        cout << s1 << ' ' << s2 << ' ' << BFS(s1,s2) << endl;

    }
    dic.clear();
}

int main(){
    cin.tie(0); cout.tie(0);
    ios_base::sync_with_stdio(0);

    int t;
    cin >> t;
    while(t--) {
        solve();
        if (t) cout << endl;
    }

    return 0;
}
