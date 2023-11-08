#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main (){
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    ll n, sum;
    cin >> n;
    stack<int> firsthalf, secondhalf;

    sum = n*(n+1)/2;

    if (sum % 2){
        cout << "NO" << endl;
        return 0;
    }

    cout << "YES" << endl;
    ll halfsum = sum/2;
    sum = 0;

    for (int i = n; i > 0; i--){
        if (sum + i <= halfsum){
            firsthalf.push(i);
            sum += i;
        }
        else
            secondhalf.push(i);
    }

    cout << firsthalf.size() << endl;
    while (!firsthalf.empty()){
        cout << firsthalf.top() << " ";
        firsthalf.pop();
    }
    cout << endl;

    cout << secondhalf.size() << endl;
    while (!secondhalf.empty()){
        cout << secondhalf.top() << " ";
        secondhalf.pop();
    }
    cout << endl;
    return 0;
}