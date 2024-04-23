#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main (){
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    ll n, x;
    cin >> n;

    ll totalsum = n*(n+1)/2;
    ll sum = 0;
    for (ll i = 0; i < n-1; i++){
        cin >> x;
        sum += x;
    }
    cout << totalsum - sum << endl;

    return 0;
}