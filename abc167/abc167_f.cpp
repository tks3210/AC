#include <bits/stdc++.h>
using namespace std;
#define MOD 1000000007
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
#define rep1(i, n) for(int i = 1; i <= (int)(n); i++)
#define showmap(is, js, x) {rep(i, is){rep(j, js){cout << x[i][j] << " ";}cout << endl;}}
#define show(x) {for(auto i: x){cout << i << " ";} cout<<endl;}
#define showm(m) {for(auto i: m){cout << m.x << " ";} cout<<endl;}
typedef long long ll;
typedef pair<int, int> P;
typedef pair<ll, ll> llP;
ll gcd(int x, int y){ return y?gcd(y, x%y):x;}
ll lcm(ll x, ll y){ return (x*y)/gcd(x,y);}


//例えば、a < bとしたとき昇順ソートとなる
bool cmp(const P &a, const P &b){
    if (a.first == b.first){
        return a.second > b.second;
    } else {
        return a.first > b.first;
    }
}

bool cmp_m(const P &a, const P &b){
    if (a.first == b.first){
        return a.second < b.second;
    } else {
        return a.first < b.first;
    }
}

int main()
{
    int n;
    cin >> n; 
    vector<string> s;
    vector<P> sp_p , sp_m;

    rep(i, n){
        string ts; cin >> ts;
        int score = 0;
        int score_min = 0;
        rep(j, ts.size()){
            if (ts[j] == '('){
                score++;
            } else {
                score--;
            }
            score_min = min(score_min, score);
        }
        if (score < 0){
            sp_m.push_back({score_min, score});
        } else {
            sp_p.push_back({score_min, score});
        }
    }
    //score + score_min >= 0のうちscore最大を選び続ける
    sort(sp_p.begin(), sp_p.end(), cmp);
    sort(sp_m.begin(), sp_m.end(), cmp_m);


    int score_ = 0;
    bool isok = true;
    rep(i, sp_p.size()){
        if (score_+sp_p[i].first < 0){
            isok = false;
            break;
        }
        score_ += sp_p[i].second;
    }
    rep(i, sp_m.size()){
        if (score_+sp_m[i].first < 0){
            isok = false;
            break;
        }
        score_ += sp_m[i].second;
    }

    if (score_ != 0) isok=false;

    if(isok) cout << "Yes" << endl;
    else cout << "No" << endl;

}

