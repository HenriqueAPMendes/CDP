#include <bits/stdc++.h>
using namespace std;

const int MAX = 212345;

map<string, string> g;
map<string, bool> visited;
map<string, bool> married;

bool found = false;

bool dfs(string node){
    if (married[g[node]]) return false;
    if (visited[node]) return found = married[node] = true;

    visited[node] = true;

    bool x = dfs(g[node]);
    if (married[node]) return false; 
    return married[node] = x;   
}

int countCicles(){
    int ans = 0;
    for (auto i : g){
        if (married[i.first]) continue;

        map<string,bool>::iterator it = visited.begin();
        while(it != visited.end()){
            it->second = false;
            it++;
        }

        // for (auto j : visited) cout << j.first << ' ';
        // for (auto j : visited) cout << j.second << ' ';
        // cout << endl << endl;

        found = false;
        dfs(i.first);
        if (found) ans++;
        // for (auto j : g)
        //     cout << j.first << ' ' << married[j.first] << endl;
        // cout << endl;
    }
        
    return ans;
}

int main(){
    cin.tie(0); cout.tie(0);
    ios_base::sync_with_stdio(0);

    string a, b;

    while(cin >> a >> b){
        g[a] = b;
        visited[a] = false;
        visited[b] = false;
        married[a] = false;
        married[b] = false;
    }
    
    cout << countCicles() << '\n';

    return 0;
}