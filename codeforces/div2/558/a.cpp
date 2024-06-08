#include <bits/stdc++.h>
using namespace std;

#define int long long int
#define endl '\n'
#define vi vector<int>
#define ii pair<int,int>

signed main(){
	cin.tie(0); cout.tie(0);
	ios_base::sync_with_stdio(0);

	int n, m;
	cin >> n >> m;
	if (m == 0) cout << 1 << endl;
	else if (m <= n/2) cout << m << endl;
	else cout << n-m << endl;

	return 0;
}
