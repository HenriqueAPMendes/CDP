#include <bits/stdc++.h>
using namespace std;

#define MAX 212345

vector<int> h(MAX), t(MAX);

int main(){
    cin.tie(0); cout.tie(0);
    ios_base::sync_with_stdio(0);

    int n, m;
    cin >> n >> m;

    for (int i = 0; i < n; i++) cin >> h[i];
    for (int i = 0; i < m; i++) cin >> t[i];

    sort(h.begin(), h.begin()+n);

    for (int i = 0; i < n; i++) cout << h[i] << ' ';
    cout << endl;

    for (int i = 0; i < m; i++){
        cout << *upper_bound(h.begin(), h.begin()+n, t[i]) << endl;

    }

    return 0;
}