#include <bits/stdc++.h>
using namespace std;

#define vi vector<int>

int main(){
	cin.tie(0); cout.tie(0);
	ios_base::sync_with_stdio(0);

	int n; cin >> n;
	vi v(n), presum(n);

	for (int i = 0; i < n; i++) cin >> v[i];
	int initialSum = 0;
	
	presum[0] = v[0];
	for (int i = 1; i < n; i++)
		presum[i] = presum[i-1] + v[i];

	int maxD = -123456789, minD = 112345678;
	for (int i = 0; i < n; i++){
		initialSum += v[i];
		int delta = i + 1 - 2*presum[i];
		maxD = max(maxD, delta);
		minD = min(minD, delta);
	}
	if (maxD < 0) cout << initialSum-1 << endl; 
	else cout << initialSum + maxD - minD << endl;
	
	return 0;
}
