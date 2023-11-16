#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    int N, P;
    string g;

    cin >> N >> P;
    vector<string> m (P);

    stack<pair<string,int>> ans;
    
    for (int i = 0; i < P; i++)
        cin >> m[i];
    
    cin >> g;


    int flag = -1;

    for (int i = 0; i < N; i++){
        //cout << "targetin: " << g[i] << endl;

        if (flag != -1){
            if (m[flag][i] == g[i]){
                string s = ans.top().first;
                s += g[i];
    
                ans.pop();
                ans.push({s,flag+1});
                continue;
            }
        }
        flag = -1;   
        for (int j = 0; j < P; j++){
            if (m[j][i] == g[i]){
                ans.push({g.substr(i,1), j+1});
                //cout << "found at j = " << j << " and i = " << i << endl;
                flag = j; break;
            }
        }

        if (flag == -1) ans.push({g.substr(i, 1), -1});
    }


    stack<pair<string,int>> inv;

    while(!ans.empty()){
        inv.push(ans.top());
        ans.pop();
    }

    pair<string,int> p;

    while(!inv.empty()){
        p = inv.top();
        cout << p.first << " " << p.second << '\n';
        inv.pop();
    }

    return 0;
}