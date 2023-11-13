#include <bits/stdc++.h>
using namespace std;

vector<int> v(3);

int main (){
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    int t, a, b, c, med;
    cin >> t;
    for (int i = 0; i < t; i++){
        cin >> a >> b >> c;
        v[0]=a; v[1]=b; v[2]=c;

        sort(v.begin(), v.end());

        cout << "Case " << i+1 << ": " << v[1] << '\n';
    }
}