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

	int a, b, c;
	while(1){
		cin >> a >> b >> c;
		if (a == 0) break;
		int ans = (int)sqrt(a*b*(100.0/c));
		cout << ans << endl;
	}

	return 0;
}

