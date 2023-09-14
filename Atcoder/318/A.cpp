#include <bits/stdc++.h>
using namespace std;

int main(){
    int N, M, P;
    cin >> N >> M >> P;

    int ans = 0;

    while(M <= N){
        M+=P;
        ans++;
    }

    cout << ans << endl;

    return 0;
}