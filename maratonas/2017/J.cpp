#include <bits/stdc++.h>
using namespace std;

int main(){
	cin.tie(0);
	ios_base::sync_with_stdio(0);

	string N;
	cin >> N;

	// soma modular para descobrir divisibilidade por 3
	int sum = 0;
	for (int i = 0; i < N.length(); i++){
		sum += (N[i] - '0');
		sum %= 3;
	}

	cout << sum << endl;

}

