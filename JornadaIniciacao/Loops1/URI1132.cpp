#include<bits/stdc++.h>
using namespace std;

int main(){
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    int X, Y, sum = 0;
    cin >> X;
    cin >> Y;

    if (X == Y){
        if (X % 13) cout << X << endl;
        return 0;
    }
    else if (X > Y){
        while(Y <= X){
            if (Y % 13) sum += Y;
            Y++;
        }
    }
    else {
        while(X <= Y){
            if (X % 13) sum += X;
            X++;
        }
    }

    cout << sum << endl;

    return 0;
}