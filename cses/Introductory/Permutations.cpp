#include <bits/stdc++.h>
using namespace std;

int main (){
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    int n;
    cin >> n;

    if (n < 4 && n > 1) {
        cout << "NO SOLUTION\n";
        return 0;
    }
    for (int i = n-1; i > 0; i -= 2)
        cout << i << " ";
    
    for (int i = n; i > 0; i -= 2)
        cout << i << " ";
    
    cout << endl;
    return 0;
}