#include <bits/stdc++.h>
using namespace std;

#define int long long int

void solve(long long k){
    if (k > 158888888888888889) { // 17 digitos
        int number = 1000000000000000000 + (k-900000000000000)/17;
        int digit = (k-900000000000000000)%17;
        string s = to_string(number);
        if (digit == 0)   {s = to_string(number-1); cout << s[16] << endl;}
        else cout << s[digit-1] << endl;
    
    } else if (k > 14888888888888889) { // 16 digitos
        int number = 100000000000000000 + (k-900000000000000)/16;
        int digit = (k-90000000000000000)%16;
        string s = to_string(number);
        if (digit == 0)   {s = to_string(number-1); cout << s[15] << endl;}
        else cout << s[digit-1] << endl;
    
    } else if (k > 1388888888888889) { // 15 digitos
        int number = 10000000000000000 + (k-90000000000000)/15;
        int digit = (k-90000000000000)%15;
        string s = to_string(number);
        if (digit == 0)   {s = to_string(number-1); cout << s[14] << endl;}
        else cout << s[digit-1] << endl;
    
    } else if (k > 128888888888889) { // 14 digitos
        int number = 100000000000000 + (k-9000000000000)/14;
        int digit = (k-90000000000000)%14;
        string s = to_string(number);
        if (digit == 0)   {s = to_string(number-1); cout << s[13] << endl;}
        else cout << s[digit-1] << endl;
    
    } else if (k > 11888888888889) { // 13 digitos
        int number = 1000000000000 + (k-900000000000)/13;
        int digit = (k-900000000000)%13;
        string s = to_string(number);
        if (digit == 0)   {s = to_string(number-1); cout << s[12] << endl;}
        else cout << s[digit-1] << endl;
    
    } else if (k > 1088888888889) { // 12 digitos
        int number = 100000000000 + (k-90000000000)/12;
        int digit = (k-90000000000)%12;
        string s = to_string(number);
        if (digit == 0)   {s = to_string(number-1); cout << s[11] << endl;}
        else cout << s[digit-1] << endl;
    
    } else if (k > 98888888889) { // 11 digitos
        int number = 10000000000 + (k-9000000000)/11;
        int digit = (k-9000000000)%11;
        string s = to_string(number);
        if (digit == 0)   {s = to_string(number-1); cout << s[10] << endl;}
        else cout << s[digit-1] << endl;
    
    } else if (k > 8888888889) { // 10 digitos
        int number = 1000000000 + (k-900000000)/10;
        int digit = (k-900000000)%10;
        string s = to_string(number);
        if (digit == 0)   {s = to_string(number-1); cout << s[9] << endl;}
        else cout << s[digit-1] << endl;
    
    } else if (k > 788888889) { // 9 digitos
        int number = 100000000 + (k-90000000)/9;
        int digit = (k-90000000)%9;
        string s = to_string(number);
        if (digit == 0)   {s = to_string(number-1); cout << s[8] << endl;}
        else cout << s[digit-1] << endl;
    
    } else if (k > 68888889) { // 8 digitos
        int number = 10000000 + (k-9000000)/8;
        int digit = (k-9000000)%8;
        string s = to_string(number);
        if (digit == 0)   {s = to_string(number-1); cout << s[7] << endl;}
        else cout << s[digit-1] << endl;
    
    } else if (k > 5888889) { // 7 digitos
        int number = 1000000 + (k-900000)/7;
        int digit = (k-900000)%7;
        string s = to_string(number);
        if (digit == 0)   {s = to_string(number-1); cout << s[6] << endl;}
        else cout << s[digit-1] << endl;
    
    } else if (k > 488889) { // 6 digitos
        int number = 100000 + (k-90000)/6;
        int digit = (k-90000)%6;
        string s = to_string(number);
        if (digit == 0)   {s = to_string(number-1); cout << s[5] << endl;}
        else cout << s[digit-1] << endl;
    
    } else if (k > 38889) { // 5 digitos
        int number = 10000 + (k-9000)/5;
        int digit = (k-9000)%5;
        string s = to_string(number);
        if (digit == 0)   {s = to_string(number-1); cout << s[4] << endl;}
        else cout << s[digit-1] << endl;
    
    } else if (k > 2889) { // 4 digitos
        int number = 1000 + (k-900)/4;
        int digit = (k-900)%4;
        string s = to_string(number);
        if (digit == 0)   {s = to_string(number-1); cout << s[3] << endl;}
        else cout << s[digit-1] << endl;
    
    } else if (k > 189) { // 3 digitos
        int number = 100 + (k-90)/3;
        int digit = (k-90)%3;
        string s = to_string(number);
        if (digit == 0)  {s = to_string(number-1); cout << s[2] << endl;}
        else cout << s[digit-1] << endl;
    
    } else if (k > 9) { // 2 digitos
        int number = 10 + (k-9)/2;
        int digit = (k-9)%2;
        string s = to_string(number);
        if (digit == 0) {s = to_string(number-1); cout << s[1] << endl;}
        else cout << s[digit-1] << endl;
    } else { // 1 digito
        cout << k << endl;
    } 
    
}

signed main(){
    cin.tie(0); cout.tie(0);
    ios_base::sync_with_stdio(0);

    int q;
    cin >> q;
    while(q--){
        long long k;
        cin >> k;
        solve(k);
    }
    

    return 0;
}
