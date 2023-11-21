#include <bits/stdc++.h>
using namespace std;

int main (){
    double degree;
    cin >> degree;

    degree = min(degree, 360 - degree);
    cout << int(360.00/degree) << endl;

    return 0;
}