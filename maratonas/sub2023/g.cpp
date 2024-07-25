#include <bits/stdc++.h>
using namespace std;

#define int long long int 
#define ii pair<int,int>
#define endl '\n'
#define vi vector<int>

#define CLOCKWISE -1
#define COUNTERCLOCKWISE 1
#define INCLUDE_COLLINEAR 1

struct pt {
    int x, y, index;
    bool operator == (pt const& t) const {
        return x == t.x && y == t.y;
    }
};

struct vec {
    int x, y, z;
};

#define vp vector<pt>

vec cross(vec v1, vec v2){
    int x = v1.y*v2.z - v1.z*v2.y;
    int y = v1.z*v2.x - v1.x*v2.z;
    int z = v1.x*v2.y - v1.y*v2.x;
    return {x,y,z};
}

int dist2(pt p1, pt p2) {
    int dx = p1.x - p2.x;
    int dy = p1.y - p2.y;
    return dx*dx + dy*dy;
}

int orientation(pt a, pt b, pt c) {
    vec v1 = {b.x-a.x, b.y-a.y, 0};
    vec v2 = {c.x-b.x, c.y-b.y, 0};
    vec v = cross(v1, v2);
    if (v.z < 0) return CLOCKWISE;
    if (v.z > 0) return COUNTERCLOCKWISE;
    return 0;
}

bool clock_wise(pt a, pt b, pt c) {
    int o = orientation(a, b, c);
    return o < 0 || (INCLUDE_COLLINEAR && o == 0);
}
bool collinear(pt a, pt b, pt c) { return orientation(a, b, c) == 0; }

vp convex_hull(vector<pt>& a) {
    int n = a.size();
    pt first = *min_element(a.begin(), a.end(), [](pt a, pt b) {
        return ii(a.y, a.x) < ii(b.y, b.x);
    });

    sort(a.begin(), a.end(), [first](pt a, pt b) {
        int o = orientation(first, a, b);
        if (o == 0)
            return dist2(first, a) < dist2(first, b);
        return o == CLOCKWISE;
    });
    
    if (INCLUDE_COLLINEAR) {
        int i = n-1;
        while (i >= 0 && collinear(first, a[i], a.back())) i--;
        reverse(a.begin()+i+1, a.end());
    }

    vector<pt> ans;
    for (auto p : a) {
        while (ans.size() > 1 && !clock_wise(ans[ans.size()-2], ans.back(), p))
            ans.pop_back();
        ans.push_back(p);
    }

    if (!INCLUDE_COLLINEAR && ans.size() == 2 && ans[0] == ans[1])
        ans.pop_back();

    return ans;
}

signed main(){
    cin.tie(0); cout.tie(0);
    ios_base::sync_with_stdio(0);

    int n; cin >> n;
    vp points(n);
    for (int i = 0; i < n; i++) { cin >> points[i].x >> points[i].y; points[i].index = i+1; }

    vp cv = convex_hull(points);
    vi ans(cv.size());
    for (int i = 0; i < cv.size(); i++) ans[i] = cv[i].index;
    sort(ans.begin(), ans.end());
    for (auto i : ans) cout << i << ' ';
    cout << endl;
    
    return 0;
}
