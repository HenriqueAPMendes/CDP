#include <bits/stdc++.h>
using namespace std;

int main(){
    cin.tie(0); cout.tie(0);
    ios_base::sync_with_stdio(0);

    string s1, s2;
    cin >> s1;
    cin >> s2;

    if (s1.length() != s2.length()) cout << "nao\n";
    else{
        int n = s1.length();
        map<char,int> map1, map2;
        for (int i = 0; i < n; i++) { map1[s1[i]]++; map2[s2[i]]++; }

        map<char,int>::iterator it1 = map1.begin(), it2 = map2.begin();

        bool isAnagram = true;

        while(it1 != map1.end()){
            if (it1->first != it2->first) { isAnagram=false; break; }
            if (it1->second != it2->second) { isAnagram=false; break; }
            it1++;
            it2++;
        }

        cout << (isAnagram ? "sim\n" : "nao\n");
    }

    return 0;
}