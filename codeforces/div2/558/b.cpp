#include <bits/stdc++.h>
using namespace std;

#define int long long int
#define endl '\n'
#define vi vector<int>
#define ii pair<int,int>
#define MAX 112345

signed main(){
	cin.tie(0); cout.tie(0);
	ios_base::sync_with_stdio(0);

	int n, ans, max_freq = 0;

	cin >> n;
	vi f(MAX), cnt(n+1);

	for (int i = 1; i <= n; i++){
		int color; cin >> color;

		cnt[f[color]]--;
		f[color]++;
		cnt[f[color]]++;

		max_freq = max(max_freq, f[color]);
		if ((cnt[i] == 1) || // apenas uma cor aparece, tem frequencia i
			(cnt[1] == i) || // todas as cores aparecem 1 vez sao 1
			(cnt[1] == 1 && cnt[max_freq]*max_freq == i-1) || // todos sao max_freq, com exceção de uma cor que aparece 1 vez
			(cnt[max_freq-1] * (max_freq-1) == i-max_freq && cnt[max_freq] == 1)) // todos sao max_freq-1, menos um que é max_freq
			ans = i;
	}

	cout << ans << endl;

	return 0;
}
