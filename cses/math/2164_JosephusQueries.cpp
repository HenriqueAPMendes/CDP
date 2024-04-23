#include <bits/stdc++.h>
using namespace std;

int jose(int n, int k, bool impar) {
	if (n == 0) return 1;
	if (impar) {
		if (n&1) {
			if (k <= n/2 + 1) return 2 * k - 1;
			return 2 * jose(n/2, k - n/2 - 1, false);
		}
		else {
			if (k <= n/2) return 2 * k - 1;
			return 2 * jose(n/2, k - n/2, true);
		}
	}
	else {
		if (k <= n/2) return 2 * k;
		if (n&1) return 2 * jose(n/2+1, k - n/2, true) - 1;
		
		else return 2 * jose(n/2, k - n/2, false) - 1;
		
	}
}
 
int main () {
	int q, n, k;
	cin >> q;
	while (q--) {
		cin >> n >> k;
		cout << jose(n, k, false) << '\n';
	}
    return 0;   
}