#include <bits/stdc++.h>
using namespace std;

int main(){
    cin.tie(0); cout.tie(0);
    ios_base::sync_with_stdio(0);

    map<char,int> letters;
    letters['A'] = 0;
    letters['B'] = 0;
    letters['C'] = 0;

    int t;
    string s1, s2, s3;
    cin >> t;
    while(t--){

        letters['A'] = 0;
        letters['B'] = 0;
        letters['C'] = 0;
        cin >> s1;
        cin >> s2;
        cin >> s3;

        letters[s1[0]] += 1;
        letters[s1[1]] += 1;
        letters[s1[2]] += 1;
        letters[s2[0]] += 1;
        letters[s2[1]] += 1;
        letters[s2[2]] += 1;
        letters[s3[0]] += 1;
        letters[s3[1]] += 1;
        letters[s3[2]] += 1;

        if (letters['A'] == 2) cout << "A\n";
        if (letters['B'] == 2) cout << "B\n";
        if (letters['C'] == 2) cout << "C\n";
    }

    return 0;
}