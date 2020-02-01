#include <bits/stdc++.h>
using namespace std;
#define MOD 1000000007
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
#define show(x) for(auto i: x){cout << i << " ";}
#define showm(m) for(auto i: m){cout << m.x << " ";}
typedef long long ll;
typedef pair<int, int> P;

typedef struct{
    int time;
    bool ishuman;
    int point;
} info_0s; 

//区間に入る⇒人⇒区間に抜けるの順番でソートされるようにしたい
auto compare = [](const info_0s& a, const info_0s& b){ 
    if (a.time == b.time){
        return a.point < b.point;
    } else {
        return a.time > b.time;
    }
};
priority_queue<info_0s, vector<info_0s>, decltype(compare)> info(compare);

int main()
{
    int n, q;
    cin >> n >> q;
    rep(i, n){ 
        int tmp_s, tmp_t, tmp_x; 
        cin >> tmp_s >> tmp_t >> tmp_x; 
        info.push({tmp_s - tmp_x, false, tmp_x});
        info.push({tmp_t - tmp_x-1, false, -tmp_x});
    }
    rep(i, q){
        int tmp_d;
        cin >> tmp_d;
        info.push({tmp_d, true, 0});
    }

    set<int> bigger;
    while(!info.empty()){
        info_0s info_p = info.top();
        info.pop();
        //cout << info_p.time << ":"<< info_p.ishuman << ":"<< info_p.point <<bigger.size() <<endl;
        if (info_p.ishuman){
            if (bigger.size() != 0){
                cout << *bigger.begin() << endl;
            } else {
                cout << "-1" << endl;
            }
        } else {
            if (info_p.point > 0){
                bigger.insert(info_p.point);
            } else {
                bigger.erase(-info_p.point);
            }
        }


    }
}

