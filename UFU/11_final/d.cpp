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
	while(cin >> n, n){
		vii sus(n);
		for (int i = 0; i < n; i++){
			cin >> sus[i].first;
			sus[i].second = i+1;
		}
		sort (sus.rbegin(), sus.rend());
		cout << sus[1].second << endl;
	}

	return 0;
}

