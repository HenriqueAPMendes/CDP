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

	int t; cin >> t;
	while(t--){
		int a, b;
		cin >> a >> b;
		int ans = ((a+b)*(b-a+1)) >> 1;
		cout << ans << endl;
	}

	return 0;
}

