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

        if (flag != -1){
            if (m[flag][i] == g[i]){
                string s = ans.top().first;
                s += g[i];
    
                ans.pop();
                ans.push({s,flag});
            }
        }
        flag = -1;   
        for (int j = 0; j < P; j++){
            if (m[j][i] == g[i]){
                ans.push({g.substr(i,1), j+1});
                flag = j; break;
            }
        }

        if (flag == -1) ans.push({g.substr(i, 1), -1});
    }


    stack<pair<string,int>> inv;

    for (int i = 0; i < (int)ans.size(); i++){
        inv.push(ans.top());
        ans.pop();
    }

    pair<string,int> p;

    for (int i = 0; i < (int)inv.size(); i++){
        p = ans.top();
        cout << p.first << " " << p.second << '\n';
        ans.pop();
    }

    return 0;
}