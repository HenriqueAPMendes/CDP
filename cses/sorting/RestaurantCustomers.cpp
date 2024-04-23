#include <bits/stdc++.h>
using namespace std;

#define ARRIVE 1
#define LEAVE 2

int main(){
    cin.tie(0); cout.tie(0);
    ios_base::sync_with_stdio(0);

    int n, a, b;
    cin >> n;

    multiset<pair<int,int>> events;

    for (int i = 0; i < n; i++){
        cin >> a >> b;
        events.insert({a,ARRIVE});
        events.insert({b,LEAVE});
    }

    int ans = 0, current = 0;

    for (auto &e : events){
        if (e.second == ARRIVE) current++;
        else if (e.second == LEAVE) current--;
        ans = max(ans, current);
    }

    cout << ans << endl;
    return 0;
}