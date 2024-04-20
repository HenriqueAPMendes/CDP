#include <bits/stdc++.h>
using namespace std;

#define int long long int
#define endl '\n'
#define vi vector<int>
#define ii pair<int,int>
#define vii vector<ii>

void solve(){
	int p;
	cin >> p;
	vi v, a;
	string s;
	while(p--){
		cin >> s;
		int x = stoi(s.substr(0, s.length()-1));
		if (s[s.length()-1] == 'V') v.push_back(x);
		else a.push_back(x);
	}
	sort (a.rbegin(), a.rend());
	sort (v.rbegin(), v.rend());
	int diff = 2*min(a.size(), v.size());
	int sum = 0;
	for(int i = 0; i < a.size() && i < v.size(); i++)
		sum += a[i] + v[i];
	cout << sum - diff << endl;
}

signed main(){
	cin.tie(0); cout.tie(0);
	ios_base::sync_with_stdio(0);

	int t; cin >> t;
	while(t--) solve();

	return 0;
}

