//2009-24:Unique lines
#include <iostream>
#include <vector>

#define ld long double

using namespace std;

struct Point{
    int x, y;
};

int main(){
    int cases;
    vector<Point> p, line;
    vector<ld> slope;
    cin >> cases;
    while(cases --){
        p.clear();
        line.clear();
        slope.clear();
        int n;
        cin >> n;
        while(n --){
            int x, y;
            Point current;
            cin >> current.x >> current.y;
            p.push_back(current);
        }
        for(int i = 0; i < p.size(); i ++){
            for(int j = i + 1; j < p.size(); j ++){
                ld s;
                bool exist = false;
                if(p[i].x == p[j].x){
                    s = (ld)2147483647;
                }
                else{
                    s = ((ld)p[i].y - (ld)p[j].y) / ((ld)p[i].x - (ld)p[j].x);
                }
                for(int k = 0; k < line.size(); k ++){
                    ld t;
                    if(line[k].x == p[j].x){
                        t = (ld)2147483647;
                    }
                    else{
                        t = ((ld)p[j].y - (ld)line[k].y) / ((ld)p[j].x - (ld)line[k].x);
                    }
                    if(s == t && s == slope[k]){
                        exist = true;
                        break;
                    }
                }
                if(!exist){
                    line.push_back(p[j]);
                    slope.push_back(s);
                }
            }
        }
        cout << slope.size() << endl;
    }

    return 0;
}