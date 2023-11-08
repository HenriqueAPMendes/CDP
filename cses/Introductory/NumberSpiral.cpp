#include <bits/stdc++.h>
using namespace std;

int main (){
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    long long t, row, col;
    long long ans = 0;
    cin >> t;
    while(t--){
        cin >> row >> col;
        if (col % 2 && row <= col)
            ans = col*col - row+1;
        
        else if (col % 2 == 0 && row <= col)
            ans = (col-1)*(col-1)+ row;
        
        else if (row % 2 == 0 && col <= row)
            ans = row*row - col + 1;

        else
            ans = (row-1)*(row-1) + col;


        cout << ans << endl;
                
    }

    return 0;
}