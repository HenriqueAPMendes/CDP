#include<bits/stdc++.h>
using namespace std;

int main(){
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    int N;

    cin >> N;

    int v0 = 0, v1 = 1, v2;

    if (N == 0) return 0;
    else if (N == 1) cout << 0 << endl;
    else if (N == 2) cout << 0 << " " << 1 << endl;
    else {
        cout << 0 << " " <<  1;
        N -= 2;
        while (N){
            v2 = v1 + v0;
            cout << " " << v2;
            v0 = v1;
            v1 = v2;
            N--;
        }
        cout << endl;
    }

    return 0;
}