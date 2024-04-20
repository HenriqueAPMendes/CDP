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
	while(1){
		cin >> n >> m;
		if (n == 0) break;
		
		map<int,int> freq;
		while(n--){
			int x; cin >>x;
			freq[x]++;
		}
		int ans = 0;
		for (auto &[f,s] : freq)
			if (s > 1) ans = 1;
		cout << ans << endl;
	}

	return 0;
}

