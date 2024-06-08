#include <bits/stdc++.h>
using namespace std;

#define int long long int
#define endl '\n'

int cycle[] = {6, 2, 4, 8};
int cycle2[] = {2, 4, 8, 6};

void solve(){
	int n, m, k;
	cin >> n >> m >> k;
	if (n < k) {
		cout << cycle[n%4] << endl;
		return;
	}
	else if (n == k) { cout << 1 << endl; return; }
	// sequencia da forma 1 2486 2486 2486 2486 ...
	// achar o n-k esimo valor da sequencia
	int sequence_size = m;
	int pos = n%sequence_size; // sequencia comeca em 0
	
	cout << "pos: " << pos << endl;
	if (pos == 0) cout << 1 << endl;
	else {
		cout << cycle2[(pos-1)%4] << endl;
	}
}

signed main(){
	cin.tie(0); cout.tie(0);
	ios_base::sync_with_stdio(0);

	int t; cin >> t;
	while(t--) solve();

	return 0;
}
