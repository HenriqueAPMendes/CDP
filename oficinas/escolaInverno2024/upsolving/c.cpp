#include <bits/stdc++.h>
using namespace std;

#define int long long int
#define vi vector<int>
#define endl '\n'

#define MAX 1123456

vi used(MAX), divide(MAX);

void solve() {
	int n, x;
	cin >> n >> x;
	vi a(n);
	vi divisors;
	for (int d = 1; d * d <= x; d++) {
		if (x % d == 0) {
			divide[d] = 1;
			divisors.push_back(d);
			if (d * d < x) {
			    divisors.push_back(x / d);
				divide[x / d] = 1;
			}
		}
	}
	for (int i = 0; i < n; i++) cin >> a[i];

	int ans = 1;
	used[1] = 1;
	vi cur = { 1 };
	for (int i = 0; i < n; i++) {
		if (!divide[a[i]])
			continue;
		vi ncur;
		bool ok = true;
		for (int d : cur)
			if (d * a[i] <= x && divide[d * a[i]] && !used[d * a[i]]) {
				ncur.push_back(d * a[i]);
				used[d * a[i]] = 1;
				if (d * a[i] == x)
					ok = false;
			}
		for (int d : ncur)
			cur.push_back(d);
		if (!ok) {
			ans++;
			for (int d : cur)
				used[d] = 0;
            cur.clear();
			used[1] = 1;
			used[a[i]] = 1;
			cur = { 1, a[i] };
		}
	}
	for (int d : divisors) {
	    divide[d] = 0;
	    used[d] = 0;
	}
	cout << ans << endl;
}

signed main() {
    cin.tie(0); cout.tie(0);
    ios_base::sync_with_stdio(0);
    int t; cin >> t;
    while (t--) solve();
	return 0;
}