#include<bits/stdc++.h>
using namespace std;

class point{
public:    
    int x;
    int y;
    point(int a, int b){
        x = a;
        y = b;
    }
};

class line{
public:
    double slope,intercept;
    bool infinite_slope;

    line(point p , point q){
        if(p.x!=q.x){
            slope  = (p.y - q.y)/(p.x - p.y);
            intercept = p.y - slope*p.x;
        }
        else{
            infinite_slope = true;
            intercept = p.x;
        }
    }
};

map<double,vector<line>> get_slopes_of_lines(vector<point> p){
    map<double, vector<line>>mp;
    for(int i=0; i<p.size(); i++){
        for(int j=i+1; j<p.size(); j++){
            line l(p[i],p[j]);
            double key = l.slope;
            mp[key].push_back(l);
        }
    }
    return mp;
}

line find_best_line(vector<point>p){
    map<double, vector<line>>slope_of_lines = get_slopes_of_lines(p);
    int count = 0;
    line l();
    for(auto slope: slope_of_lines){
        if(slope.second.size()>count){
            count = slope.second.size();
            l = slope.second[0];
        }
    }
    return l;
}

int main(){
 vector<point>p(3);
 for(int i=0; i<3; i++){
     cin>>p[i].x>>p[i].y;
 }
    line l = find_best_line(p);
    cout<<l.slope<<" "<<l.intercept<<"\n";

 return 0;    
}