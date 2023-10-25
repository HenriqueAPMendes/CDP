#include <bits/stdc++.h>
using namespace std;

int main(){
	cin.tie(0);
	ios_base::sync_with_stdio(0);

	int A1, A2, A3;
	cin >> A1 >> A2 >> A3;

	// teste 3 andar
	// teste 2 andar
	// teste 1 andar
	int cost = min(A1*4 + A2*2, min(A1*2 + A3*2, A2*2 + A3*4));
	cout << cost << endl;

	return 0;
}

