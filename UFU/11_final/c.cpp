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

	int n;
	while(1){
		cin >> n;
		if (n == -1) break;
		int v, t, last = 0;
		int ans = 0;
		while(n--){
			cin >> v >> t;
			ans += v*(t-last);
			last = t;
		}
		cout << ans << " milhas" << endl;
	}

	return 0;
}

