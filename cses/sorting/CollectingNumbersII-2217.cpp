#include <bits/stdc++.h>
using namespace std;

#define int long long int
#define endl '\n'
#define vi vector<int>

signed main(){
    cin.tie(0); cout.tie(0);
    ios_base::sync_with_stdio(0);

    int n, m; cin >> n >> m;
    vi index(n+1), v(n);
    for (int i = 0; i < n; i++){
        cin >> v[i];
        index[v[i]] = i;
    }
    int ans = n;
    for (int i = 2; i <= n; i++){
        if (index[i] > index[i-1]) ans--;
    }

    while(m--){
        int a, b;
        cin >> a >> b;
        int na = v[a-1];
        int nb = v[b-1];
        cout << "swapping " << na << ' ' << nb << endl;
        int delta1 = 0;
        if (na > 1 && index[na] > index[na-1]) delta1 = -1;
        int delta2 = 0;
        if (na < n && index[na] < index[na+1]) delta2 = -1;
        int delta3 = 0;
        if (nb > 1 && index[nb] > index[nb-1]) delta3 = -1;
        int delta4 = 0;
        if (nb < n && index[nb] < index[nb+1]) delta4 = -1;

        if (na-nb == 1) delta1/=2, delta4 /= 2;
        else if (nb-na == 1) delta2/=2, delta3 /= 2;

        ans -= (delta1+delta2+delta3+delta4);

        for (auto i : v) cout << i << ' '; cout << endl;
        for (int i = 1; i <= n; i++) cout << index[i] << ' '; cout << endl;
        swap(index[na], index[nb]);
        swap(v[a-1], v[b-1]);
        for (auto i : v) cout << i << ' '; cout << endl;
        for (int i = 1; i <= n; i++) cout << index[i] << ' '; cout << endl;

        na = v[a-1];
        nb = v[b-1];
        delta1 = 0;
        if (na > 1 && index[na] > index[na-1]) delta1 = -1;
        delta2 = 0;
        if (na < n && index[na] < index[na+1]) delta2 = -1;
        delta3 = 0;
        if (nb > 1 && index[nb] > index[nb-1]) delta3 = -1;
        delta4 = 0;
        if (nb < n && index[nb] < index[nb+1]) delta4 = -1;

        if (na-nb == 1) delta1/=2, delta4 /= 2;
        else if (nb-na == 1) delta2/=2, delta3 /= 2;

        ans += delta1+delta2+delta3+delta4;
        cout << ans << endl;
    }

    return 0;
}
