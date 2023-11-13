#include <bits/stdc++.h>
using namespace std;

int main(){
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    int k, x, y, dx, dy;

    do{
        cin >> k;
        cin >> dx >> dy;
        for (int i = 0; i < k; i++){
            cin >> x >> y;
            if (x == dx || y == dy) cout << "divisa\n";
            else if (x < dx && y < dy) cout << "SO\n";
            else if (x < dx && y > dy) cout << "NO\n";
            else if (x > dx && y < dy) cout << "SE\n";
            else if (x > dx && y > dy) cout << "NE\n";
        }
    }while(k != 0);
}