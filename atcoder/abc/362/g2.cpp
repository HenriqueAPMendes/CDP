
#include<bits/stdc++.h>
using namespace std;

#define int long long int
#define endl '\n'
#define ii pair<int,int>
#define vi vector<int>
#define vii vector<ii>
#define vvi vector<vi>

#define K 26
#define MAX 512345

char to_i(char c){
    return c-'a';
}

struct node {
  int nxt[K], term = 0, p, pc, link = -1, go[K], exi = -1, occ = 0;
  vi idx;
  node(int _p = 0, int _pc = 0) : p(_p), pc(_pc) {
    memset(nxt, -1, sizeof(nxt));
    memset(go, -1, sizeof(go));
  }
};

vector<node> autom;
vi occ(MAX);

void add_string(string s, int idx) {
  int i, u = 0;
  for (i = 0; i < s.length(); i++) {
    int c = to_i(s[i]);
    if (autom[u].nxt[c] == -1) {
      autom[u].nxt[c] = autom.size();
      autom.emplace_back(u, c);
    }
    u = autom[u].nxt[c];
  }
  autom[u].term = 1; autom[u].idx.push_back(idx);
}

int go(int u, int c);

int link(int u) {
  if (autom[u].link != -1) return autom[u].link;
  return autom[u].link = (u == 0 || autom[u].p == 0) ? 0 :
    go(link(autom[u].p), autom[u].pc);
}

int go(int u, int c) {
  if (autom[u].go[c] != -1) return autom[u].go[c];
  if (autom[u].nxt[c] != -1) return autom[u].go[c] = autom[u].nxt[c];
  return autom[u].go[c] = u == 0 ? 0 : go(link(u), c);
}

int exi(int u) { // assumes u != 0
  int v = link(u);
  if (autom[u].exi != -1) return autom[u].exi;
  return autom[u].exi = (v == 0 || autom[v].term) ? v : exi(v);
}

void process(string t) {
  int i, u = 0;
  for (i = 0; i < t.length(); i++) {
    int c = to_i(t[i]);
    u = go(u, c);
    for (int v = u; v; v = exi(v))
      autom[v].occ++;
  }
  for (u = 0; u < (int)autom.size(); u++)
    for (auto &idx : autom[u].idx)
      occ[idx] += autom[u].occ;
}

void solve(){
  int i;
  string t;
  int q;
  autom.emplace_back();
  cin >> t >> q;
  for (i = 0; i < q; i++) {
    string s;
    cin >> s;
    add_string(s, i);
  }
  process(t);
  for (int i = 0; i < q; i++)
    cout << occ[i] << endl;

}

signed main(){
    cin.tie(0); cout.tie(0);
    ios_base::sync_with_stdio(0);
    solve();
    return 0;
}
