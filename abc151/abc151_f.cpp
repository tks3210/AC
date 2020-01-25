#include <bits/stdc++.h>
using namespace std;
#define MOD 1000000007
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
#define show(x) for(auto i: x){cout << i << " ";}
typedef long long ll;

vector<pair<int, int>> a;
#define REP 100
double fxy(double t1, double t2){

    double len = 0;
    for(auto p: a){
        double x = (double)t1 - p.first;
        double y = (double)t2 - p.second;
        double tmp = (x * x) + (y * y);
        tmp = sqrt(tmp);
        len = max(len, tmp);
    }
    return len;
}

double g(double x){
    double u = 1000.0;
    double d = 0.0;
    rep(i, REP){
        double uud = (u*2 + d) / 3;
        double udd = (u + d*2) / 3;
        if (fxy(x, uud) < fxy(x, udd)){
            d = udd;
        } else {
            u = uud;
        }
        //cout << u << " " << d << endl;
    }
    return fxy(x, u);
}

int main()
{
    int n;
    cin >> n;
    rep(i, n){ 
        int t1, t2; 
        cin >> t1 >> t2; 
        a.push_back(make_pair(t1, t2));
    }

    double l = 0.0;
    double r = 1000.0;
    rep(i, REP){
        double llr = (l*2 + r)/3;
        double lrr = (l + r*2)/3;
        if (g(llr) < g(lrr)){
            r = lrr;
        } else {
            l = llr;
        }
        //cout << l << " " << r << endl;
    }
    double ans = g(r);
    printf("%4.10lf", ans);
}

