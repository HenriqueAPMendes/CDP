#include<bits/stdc++.h>
using namespace std;

#define int long long int
#define endl '\n'
#define vi vector<int>
#define ii pair<int,int>

signed main(){
    cin.tie(0); cout.tie(0);
    ios_base::sync_with_stdio(0);

    int a, b; cin >> a >> b;

    vi prime(b+1, 1);
    prime[1] = 0;
    prime[2] = 1;

    for (int i = 2; i <= b; i++){
        // cout << i << ' ' << prime[i] << endl;
        if (prime[i]){
            if (i >= a) cout << i << ' ';
            for (int j = i; j <= b; j += i)
                prime[j] = 0;
        }
    }
    cout << endl;       
    // for (int i = 1; i <= b; i++) cout << prime[i] << ' ';
    // cout << endl;

    // for (int i = a; i <= b; i++)
    //     if (prime[i]) cout << i << ' ';
    // cout << endl;

    return 0;
}