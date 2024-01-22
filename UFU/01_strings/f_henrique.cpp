#include <bits/stdc++.h>
using namespace std;

#define endl '\n'

int main(){
    cin.tie(0); cout.tie(0);
    ios_base::sync_with_stdio(0);

    string s; cin >> s;

    bool contains_8 = (s.length() >= 8);
    bool contains_lower_case = false;
    bool contains_upper_case = false;
    bool contains_number = false;
    for (int i = 0; i < (int)s.length(); i++){
        if (s[i] >= 'a' && s[i] <= 'z') contains_lower_case = true;
        if (s[i] >= 'A' && s[i] <= 'Z') contains_upper_case = true;
        if (s[i] >= '0' && s[i] <= '9') contains_number = true;
    }

    if (contains_8 && contains_lower_case && contains_upper_case && contains_number) cout << "senha valida" << endl;
    else{
        if (!contains_8) cout << "minimo de 8 caracteres" << endl;
        if (!contains_upper_case) cout << "letra maiuscula" << endl;
        if (!contains_lower_case) cout << "letra minuscula" << endl;
        if (!contains_number) cout << "numero" << endl;
    }

    return 0;
}