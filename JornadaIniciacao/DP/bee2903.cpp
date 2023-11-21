#include <bits/stdc++.h>
using namespace std;

int gcd(int a, int b){
    if (b == 0) return a;
    return gcd(b, a%b);
}

int lcm(int a, int b){
    return (a*b)/gcd(a,b);
}

int main (){
    int a, b;
    char dot;
    cin >> a >> dot >> b;

    a = a*100 + b;

    cout << lcm(a, 36000) / a << endl;

    return 0;
}