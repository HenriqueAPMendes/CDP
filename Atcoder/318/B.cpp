#include <bits/stdc++.h>
using namespace std;

int main(){

    int m[101][101];
    
    for (int i = 0; i < 101; i++)
        for (int j = 0; j < 101; j++)
            m[i][j] = 0;

    int a,b,c,d,N;
    cin >> N;
    for (int i = 0; i < N; i++){
        cin >> a >> b >> c >> d;
        for (int j = a; j < b; j++)
            for (int k = c; k < d; k++)
                m[j][k] = 1;
    }                

    int s = 0;
    for (int i = 0; i < 101; i++)
        for (int j = 0; j < 101; j++)
            s += m[i][j];

    cout << s << endl;


    return 0;
}