#include <bits/stdc++.h>
using namespace std;

#define vi vector<int>

int main(){
	cin.tie(0); cout.tie(0);
	ios_base::sync_with_stdio(0);

	int n; cin >> n;
	vi v(n), presum(n);
	int initialSum = 0;
	for (int i = 0; i < n; i++){ 
		cin >> v[i];
		initialSum += v[i];
		if (v[i]) v[i] = -1;
		else v[i] = 1;
	}

	// calc max subarray sum on v
	int ans;
	vi maxSum(n);
	ans = maxSum[0] = v[0];
	for (int i = 1; i < n; i++){
		maxSum[i] = max(maxSum[i-1]+v[i], v[i]);
		ans = max(maxSum[i], ans);
	}

	cout << initialSum + ans << endl;
	
	return 0;
}
