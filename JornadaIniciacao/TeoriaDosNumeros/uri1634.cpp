#include <bits/stdc++.h>
using namespace std;


int main (){
	int n, m;
	cin >> n >> m;
	
	vector<vector<int>> a(n);
	for (int i = 0; i < n; i++)
		a[i] = vector<int>(m);
	
	for (int i = 0; i < n; i++){
		for (int j = 0; j < m; j++){
			cin >> a[i][j];
		}
	}




	cout << "1 / 1" << endl;
	
	return 0;
}

