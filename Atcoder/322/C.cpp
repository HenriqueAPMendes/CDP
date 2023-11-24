#include <bits/stdc++.h>
using namespace std;

const int MAX = 212345;

vector<int> v(MAX, 0);
vector<int> c(MAX, 0);

int main (){
    cin.tie(0); cout.tie(0);
    ios_base::sync_with_stdio(0);

    int n, m, x;
    cin >> n >> m;
    for (int i = 0; i < m; i++){
        cin >> x;
        v[x-1] = 1;
    }

    for (int i = n-1; i >= 0; i--){
        if (v[i]) c[i] = 0;
        else c[i] = c[i+1]+1;
    }

    for (int i = 0; i < n; i++)
        cout << c[i] << '\n';

    return 0;
}