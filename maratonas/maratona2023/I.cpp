#include <bits/stdc++.h>
using namespace std;

#define MAX 112345
#define ll long long

vector<ll> even(MAX), odd(MAX), a(MAX);

int main(){
    cin.tie(0); cout.tie(0);
    ios_base::sync_with_stdio(0);

    int n;
    cin >> n;
    for (int i = 0; i < n; i++) cin >> a[i];

    if (a[0] == 1) {odd[0] = 1; even[0] = 0;}
    else {odd[0] = 0; even[0] = 1;}

    for (int i = 1; i < n; i++){
        if (a[i] == 0){
            even[i] = even[i-1]+1;
            odd[i] = odd[i-1];
        }
        else{
            even[i] = odd[i-1];
            odd[i] = even[i-1] + 1;
        }
    }

    ll ans = 0;

    for (int i = 0; i < n; i++)
        ans += odd[i];

    cout << ans << endl;    

    return 0;
}