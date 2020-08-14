#include <bits/stdc++.h>
using namespace std;

struct point{
    int x, y;
    point(int x, int y):x(x), y(y){}
    point operator - (point oth){
        return(point(x-oth.x, y - oth.y));
    }
};

bool onSegment(point p, point q, point r){
    return (q.x <= max(p.x, r.x) && q.x >= min(p.x, r.x) && q.y <= max(p.y, r.y) && q.y >= min(p.y, r.y));
}

int orientation(point p, point q, point r){
    int val = (q.y - p.y) * (r.x - q.x) - (q.x - p.x) * (r.y - q.y);
    // 0 => collinear, 1 => clock/counter, 2 => counter/clock
    if (val == 0) return 0;
    return (val > 0)? 1: 2;
}

// line segments are p1 to q1 and p2 to q2
bool intersect(point p1, point q1, point p2, point q2){
    int o1 = orientation(p1, q1, p2);
    int o2 = orientation(p1, q1, q2);
    int o3 = orientation(p2, q2, p1);
    int o4 = orientation(p2, q2, q1);
    if(o1 != o2 && o3 != o4)
        return true;
    if (o1 == 0 && onSegment(p1, p2, q1)) return true;

    // p1, q1 and q2 are colinear and q2 lies on segment p1q1
    if (o2 == 0 && onSegment(p1, q2, q1)) return true;

    // p2, q2 and p1 are colinear and p1 lies on segment p2q2
    if (o3 == 0 && onSegment(p2, p1, q2)) return true;

    // p2, q2 and q1 are colinear and q1 lies on segment p2q2
    if (o4 == 0 && onSegment(p2, q1, q2)) return true;

    return false;
}
