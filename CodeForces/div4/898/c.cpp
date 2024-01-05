#include <bits/stdc++.h>
using namespace std;

int main(){
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    int t, sum = 0;
    cin >> t;
    char c;

    while(t--){
        sum = 0;
        for (int i = 0; i < 10; i++){
            for (int j = 0; j < 10; j++){
                cin >> c;
                if (c == 'X'){
                    if (i == 0 or i == 9 or j == 0 or j == 9)
                        sum += 1;
                    else if (i == 1 or i == 8 or j == 1 or j == 8)
                        sum += 2;
                    else if (i == 2 or i == 7 or j == 2 or j == 7)
                        sum += 3;
                    else if (i == 3 or i == 6 or j == 3 or j == 6)
                        sum += 4;
                    else if (i == 4 or i == 5 or j == 4 or j == 5)
                        sum += 5;
                }
            }
        }
        cout << sum << endl;
    }

    return 0;
}