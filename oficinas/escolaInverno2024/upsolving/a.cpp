#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define vi vector<int>
#define MAXN 1123456

vi freq(MAXN), nxt(MAXN);

int sum(int n){
    int ans = 0;
    while (n > 0){
        ans += n % 10;
        n /= 10;
    }
    return ans;
}

signed main(){
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(0);

    int n, k;
    cin >> n >> k;
    vi v(n);
    for (int i = 0; i < n; i++){
        cin >> v[i];
        freq[v[i]]++;
    }

    for (int i = 0; i < MAXN; i++)
        nxt[i] = i - sum(i);

    int ans = 0;
    for (int i = MAXN - 1; i >= 0; i--){
        k -= freq[i];
        freq[nxt[i]] += freq[i];
        freq[i] = 0;
        if (k <= 0){
            ans = sum(i);
            break;
        }
    }
    cout << ans << endl;

    return 0;
}