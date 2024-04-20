#include <bits/stdc++.h>
#include <sstream>
using namespace std;

int main(){
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    int t;
    cin >> t;

    int n, m, x;
    string str;

    vector<vector<int>> b;

    for (int i = 0; i < t; i++){
        cin >> n >> m;

        b.resize(n);

        for (int j = 0; j < n; j++){
            b[i].resize(m);
            getline(cin, str);
            stringstream ss(str);
            while(ss >> x)
                b[i].push_back(x);
        }

        for (int i = 0; i < n; i++){
            for (int j = 0; j < m; j++){
                cout << b[i][j] << " ";
            }
            cout << endl;
        }
    }

    return 0;
}