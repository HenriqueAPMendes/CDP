#include <bits/stdc++.h>
using namespace std;

#define MAX 2123435
#define ll long long
#define ii pait<int,int>
#define vi vector<int>
#define vii vector<ii>
#define endl '\n'

int perfect(int n){
    int sum = 0;
    for(int i = 1; i < n; i++){
        if(n%i == 0){
            sum += i;
        }
    }
    return sum == n;
}

int main(){
    cin.tie(0); cout.tie(0);
    ios_base::sync_with_stdio(0);

    int n; cin >> n;
    vector<int> v;
    
    if(perfect(n)){
        cout << "sim" << endl;
    }
    else{
    cout << "nao" << endl;
    }

    for(int i = 1; i <= n; i++){
        if (perfect(i)) {
            v.push_back(i);
        }
    }

    for(int i = 0; i < v.size(); i++){
        cout << v[i] << " ";
    }

    
  return 0;
}