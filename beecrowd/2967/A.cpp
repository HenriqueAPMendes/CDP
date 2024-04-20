#include <bits/stdc++.h>
using namespace std;

// problema maratona 2019 - Forests in danger

typedef long long ll;
typedef pair<ll,ll> pll;

#define MAX 112345
#define INF 1123456789

struct Point{
    ll x, y;
};
struct Line{
    Point p1, p2;
};
struct Event{
    ll x, topy, boty, add;
};

vector<Line> rivers;
vector<Event> events;
Point bottomLeft, topRight;
ll n;

// segment tree

// fim segment tree

int main(){
    cin >> n;
    int i;
    for (i = 0; i < n; i++){
        Point p1, p2;
        cin >> p1.x >> p1.y >> p2.x >> p2.y;

        if (p2.x < p1.x || p2.y < p1.y) swap(p1,p2);
        rivers.push_back(Line {p1, p2});
    }

    double p; cin >> p;
    cin >> bottomLeft.x >> bottomLeft.y >> topRight.x >> topRight.y;

    // busca binária na resposta
    ll leftr = 0, rightr = MAX, bestr = INF;

    while(leftr <= rightr){
        ll r = (leftr + rightr)/2;
        for (i = 0; i < n; i++){
            ll topy = min(topRight.y, rivers[i].p2.y + r),
               boty = max(bottomLeft.y, rivers[i].p1.y - r);

            events.push_back(Event { max(rivers[i].p1.x - r, bottomLeft.x), topy, boty, 1});
            events.push_back(Event { min(rivers[i].p2.x + r, topRight.x), topy, boty, -1});
        }
        sort(events.begin(), events.end(), [](Event e1, Event e2) {
            return e1.x < e2.x;
        });

        build(); // seg tree

        ll area = 0,
            currentLine = 0,
            totalArea = (topRight.y - bottomLeft.y)*(topRight.x - bottomLeft.x),
            prevx = bottomLeft.x;
        
        for (i = 0; i < events.size(); i++){
            area += currentLine * (events[i].x - prevx); // acumula area da sweep line
            prevx = events[i].x;
            update(events[i].boty, events[i].topy - 1, events[i].add); // seg tree
            currentLine = topRight.y - bottomLeft.y - count_zeros(bottomLeft.y, topRight.y - 1); // intervalo inteiro descontando os zeros
        }

        double currentP = ((double)area/totalArea)*100;

        if (currentP - p >= 10e-9){ // epsilon double comparation
            rightr = r-1;
            if (r < bestr) bestr = r;
        }
        else leftr = r + 1;

        events.clear();
    }

    cout << bestr << endl;

    return 0;
}
