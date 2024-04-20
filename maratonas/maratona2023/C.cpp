#include <bits/stdc++.h>
using namespace std;

#define int long long int
#define pb push_back
#define MAXN 100005

vector<int> adj[MAXN];
int v[MAXN];
int ans[MAXN];
vector<int> q; // pilha de marcos ja postados na arvore da dfs

void dfs(int s, int p){
    auto it = lower_bound(q.begin(), q.end(), v[s]);
    int prv;
    bool fl = 0;
    if (it == q.end()){ // nenhum marco com pelo menos v[s] likes ja foi postado
        q.pb(v[s]); // posta esse
        fl = 1; // ???
    }
    else{ // existe marco visitado com >= likes
        prv = *it; // salva ultimo valor visitado
        *it = v[s]; // troca post por esse apara minimizar "skip" de likes
    }

    ans[s] = q.size(); // quantidade de posts

    for (auto &i : adj[s]) // recursao padrao dfs
        if (i != p) dfs(i, s);
    
    if (fl) 
        q.pop_back();
    else {
        cout << s << endl;
        *it = prv;
    }
    
}
signed main(){
    int n;
    cin >> n;
    for (int i = 1; i < n; i++){
        int x;
        cin >> x;
        x--;
        adj[x].pb(i);
        adj[i].pb(x);
    }
    for (int i = 0; i < n; i++) cin >> v[i];
    
    dfs(0, -1);
    for (int i = 1; i < n; i++) cout << ans[i] << ' ';
    cout << endl;
}