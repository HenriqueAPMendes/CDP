#include <bits/stdc++.h>
using namespace std;

#define int long long int
#define vi vector<int>
#define endl '\n'

signed main(){
    // cin.tie(0); cout.tie(0);
    // ios_base::sync_with_stdio(0);

    setlocale(LC_ALL, "pt_BR.UTF-8");

    int n; wcin >> n;
    vector<wstring> v(n);
    for (int i = 0; i < n; i++) wcin >> v[i];

    sort(v.begin(), v.end());

    for (int i = 0; i < n; i++) wcout << v[i] << endl;

    return 0;
}