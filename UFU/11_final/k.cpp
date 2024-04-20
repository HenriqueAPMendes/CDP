#include <bits/stdc++.h>
using namespace std;

#define int long long int
#define endl '\n'
#define vi vector<int>
#define ii pair<int,int>
#define vii vector<ii>

signed main(){
	cin.tie(0); cout.tie(0);
	ios_base::sync_with_stdio(0);

	int n, m;
	cin >> n >> m;
	int even = 0, odd = 0;
	for(int i = 0; i < n*m; i++){
		int x; cin >> x;
		if (x & 1) odd++;
			else even++;
	}
	cout << even << endl << odd << endl;

	return 0;
}

