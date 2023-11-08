#include <bits/stdc++.h>
using namespace std;

int main (){
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    int n;
    cin >> n;
    long long ans = 0;

    vector<int> v(n);
    for (int i = 0; i < n; i++)
        cin >> v[i];
    
    int current = v[0];

    for (int i = 1; i < n; i++){
        int operations = max(0, current - v[i]);
        if (operations <= 0) current = v[i];
        ans += operations;

    }

    cout << ans << endl;

    return 0;
}