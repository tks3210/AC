#include <bits/stdc++.h>
using namespace std;
#define MOD 1000000007
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
#define show(x) for(auto i: x){cout << i << " ";}
#define showm(m) for(auto i: m){cout << m.x << " ";}
typedef long long ll;
typedef pair<int, int> P;


int masu[2010][2010] = {0};

int main()
{
    int h, w;
    cin >> h >> w;

    vector<int> yoko[h+1];
    vector<int> tate[w+1];
    rep(i, h) yoko[i+1].push_back(0);
    rep(j, w) tate[j+1].push_back(0);
    rep(i, h)rep(j, w){
        char tmp; cin >> tmp;
        if(tmp == '#') {
            masu[i+1][j+1] = 1;
            yoko[i+1].push_back(j+1);
            tate[j+1].push_back(i+1);
        } 
    }
    rep(i, h) yoko[i+1].push_back(w+1);
    rep(j, w) tate[j+1].push_back(h+1);

    // rep(i, h) {show(yoko[i+1]);cout << endl;}
    // cout << endl;
    // rep(j, w) {show(yoko[j+1]);cout << endl;}


    int max_ans = 0;
    rep(i, h)rep(j,w){
        int ans = 0;
        if (masu[i+1][j+1] == 1) continue;
        auto x_itr = lower_bound(yoko[i+1].begin(), yoko[i+1].end(), j+1);
        auto y_itr = lower_bound(tate[j+1].begin(), tate[j+1].end(), i+1);
//        cout << *x_itr <<" " << *y_itr << endl;
//        cout << *(x_itr-1) <<" " << *(y_itr-1) << endl;

        ans += *(x_itr) - *(x_itr-1) -1;
        ans += *(y_itr) - *(y_itr-1) -1;
        ans -= 1;
//        cout << i << j << ":" << ans << endl;
        max_ans = max(max_ans, ans);
    }
    cout << max_ans << endl;
}

