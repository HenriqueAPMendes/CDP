#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define int long long int
#define vi vector<int>
#define ii pair<int,int>
#define iii pair<int,ii>
#define vii vector<ii>

#define INF 1e17
 
vector<iii> v;
vi dist, p;
 

void solve(){
    int n, m;
	cin >> n >> m;
    p = vi(n+1);
    dist = vi(n+1, INF);
	for (int i = 0; i < m; i++) {
        int a, b, c;
		cin >> a >> b >> c;
		v.push_back({c, {a, b}});
	}
	int x = -1;
    dist[1] = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
            auto [w,uv] = v[j];
            auto [u,v] = uv;
			if (dist[u] + w < dist[v]) {
				dist[v] = dist[u] + w;
				p[v] = u;
				if (i == n-1) x = v;
			}
		}
	}
	if (x == -1) cout << "NO" << endl;
	else {
		cout << "YES" << endl;
		for (int i = 0; i < n; i++) x = p[x];
		stack<int> s;
		s.push(x);
		for (int i = p[x]; i != x; i = p[i]) {
			s.push(i);
		}
		s.push(x);
		while (!s.empty()) {
			cout << s.top() << ' ';
			s.pop();
		}
		cout << endl;
	}
}

signed main(){
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    solve();
    return 0;
}
