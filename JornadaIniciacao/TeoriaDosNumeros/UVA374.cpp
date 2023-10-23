#include <bits/stdc++.h>
using namespace std;

long long binExp(long long a, long long exp, long long M){
	if (exp == 0) return 1;
	if (exp % 2 == 1) return ((a%M) * (binExp(a, exp-1, M))%M)%M;
	long long b = binExp(a, exp/2, M)%M;
	return (b*b)%M;
}


int main(){
	cin.tie(0);
	ios_base::sync_with_stdio(0);

	long long B, P, M; 

	while(cin >> B >> P >> M){
		cout << binExp(B, P, M) << endl;
	}

	return 0;
}

