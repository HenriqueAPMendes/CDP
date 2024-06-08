#include <bits/stdc++.h>
using namespace std;

#define int long long int
#define endl '\n'
#define vi vector<int>
#define ii pair<int,int>
#define iii pair<ii, int>
#define INF 11234567890123

int gcd(int a, int b){
	if (b == 0) return 1;
	return gcd(b, a%b);
}

int gcd(int a, int b, int c){
	return gcd(gcd(a,b),c);
}


signed main(){
	cin.tie(0); cout.tie(0);
	ios_base::sync_with_stdio(0);

	int n; cin >> n;
	vector<ii> points(n);
	set<iii> lines;

	for (int i = 0; i < n; i++) cin >> points[i].first >> points[i].second;
	
	for (int i = 0; i < n; i++){
		for (int j = i+1; j < n; j++){
			int x1 = points[i].first;
			int x2 = points[j].first;
			int y1 = points[i].second;
			int y2 = points[j].second;

			int a = y1-y2;
			int b = x2-x1;
			int c = x2*y1 - x1*y2;
			int divisor = gcd(a, b, c);
			a /= divisor;
			b /= divisor;
			c /= divisor;
			lines.insert({{a,b},c});
		}
	}

	int ans = 0;

	for (int i = 0; i < lines.size(); i++){
		for (int j = i+1; j < lines.size(); j++){
			iii l1 = lines[i];
			iii l2 = lines[j];
			int a1 = l1.first.first;
			int a2 = l2.first.first;
			int b1 = l1.first.second;
			int b2 = l2.first.second;
			int c1 = l1.second;
			int c2 = l2.second;
			if (a1==a2 && b1==b2) ans--;
		}
	}

	cout << ans << endl;

	return 0;
}
