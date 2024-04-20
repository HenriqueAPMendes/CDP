#include <bits/stdc++.h>
using namespace std;

int main (){
    cin.tie(0); cout.tie(0);
    ios_base::sync_with_stdio(0);

    map<string,int> distances;
    distances["AB"] = 1;  
    distances["BC"] = 1;
    distances["CD"] = 1;
    distances["DE"] = 1;
    distances["EA"] = 1;
    distances["AE"] = 1;
    distances["ED"] = 1;
    distances["DC"] = 1;
    distances["CB"] = 1;
    distances["BA"] = 1;

    distances["AC"] = 2;
    distances["AD"] = 2;
    distances["BD"] = 2;
    distances["BE"] = 2;
    distances["CE"] = 2;
    distances["CA"] = 2;
    distances["DA"] = 2;
    distances["DB"] = 2;
    distances["EB"] = 2;
    distances["EC"] = 2;  

    string s, t;
    cin >> s;
    cin >> t;

    if (distances[s] == distances[t]) cout << "Yes\n";
    else cout << "No\n";
    
    return 0;
}