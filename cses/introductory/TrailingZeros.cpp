#include <bits/stdc++.h>
using namespace std;

int main(){
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    int n, ans = 0, div = 5;
    cin >> n;

    // accumulate potencies of 5
    while(div <= n){
        ans += n/div;
        div *= 5;
    }

    cout << ans << endl;
}
