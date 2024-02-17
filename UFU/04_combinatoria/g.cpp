#include <bits/stdc++.h>
using namespace std;

#define int long long int
#define vi vector<int>
#define ii pair<int,int>
#define endl '\n'

vector<string> items;
vector<string> picked;

void printPicked(){
    for (int i = 0; i < picked.size()-1; i++) cout << picked[i] << ',';
    cout << picked[picked.size()-1] << endl;
}

void backtrack(int index, int n){
    picked.push_back(items[index]);
    if (picked.size() == n) {printPicked(); picked.pop_back(); return;}
    for (int i = index+1; i < items.size(); i++) backtrack(i, n);

    picked.pop_back();
}

void printAll(int n){ // print n items lexicographically
    for (int start = 0; start < items.size(); start++){
        picked.clear();
        backtrack(start, n);
    }
}

void combine(){
    for (int i = 1; i <= items.size(); i++){ // quantidade na permutacao
        printAll(i);
    }
}

signed main(){
    cin.tie(0); cout.tie(0);
    ios_base::sync_with_stdio(0);

    string s; cin >> s;
    
    string buff = "";
    for (int i = 0; i < s.length(); i++){
        if (s[i] == ','){
            items.push_back(buff); buff = "";
        }
        else buff += s[i];
    }
    items.push_back(buff);
    
    combine();

    return 0;
}