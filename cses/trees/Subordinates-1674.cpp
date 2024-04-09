#include <bits/stdc++.h>
using namespace std;

#define int long long int
#define endl '\n'
#define vi vector<int>
#define ii pair<int,int>

vector<vi> subordinates;
vi qtd;

int calc(int pai){
	int x = 0;
	for (auto filho : subordinates[pai]) x += calc(filho);
	qtd[pai] = x+1;
	return x+1;
}


signed main(){
	cin.tie(0); cout.tie(0);
	ios_base::sync_with_stdio(0);

	int n; cin >> n;
	qtd = vi(n+1);
	subordinates = vector<vi>(n+1);
	for (int i = 0; i < n-1; i++){
		int boss; cin >> boss;
		subordinates[boss].push_back(i+2);
	}

	calc(1);
	
	for (int i = 1; i < n+1; i++) cout << qtd[i]-1<< ' ';
	cout << endl;

	return 0;
}

