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


/*
* だめなパターンは双方が0の状態で選択を迫られること
* 少ない方の数を増やすことに勤めればいいんじゃね？
    * 1 0 0 のときに、AC ABの形が反例
* 操作の過程で0が増えないようにする
* 

* 反対から試せないか？

* 初期パターンで0 x 0以外の場合ではOK

* 気を付けるのは、0 0 2のときだった。。。。

*/


int main()
{
    ll n, a[3];
    cin >> n >> a[0] >> a[1] >> a[2];
    vector<string> s(n);
    rep(i, n){ 
        cin >> s[i];
    }
    vector<P> cmd_ch(n);
    rep(i, n){
        if (s[i] == "AB") cmd_ch[i] = {0, 1};
        else if (s[i] == "BC") cmd_ch[i] = {1, 2};
        else cmd_ch[i] = {2, 0};
    }
    int cnt=0;
    rep(i, 3){
        if (a[i] != 0) cnt++;
    }

    bool isyes = true;
    vector<char> ans(n);

    vector<int> mark(n);
    P oldc;
    int tmp_mark = -1;
    rep(i, n){
        int id = n-1-i;
        auto c = cmd_ch[id];
        if (i == 0) {mark[id] = tmp_mark; oldc = c; continue;}
        if (oldc != c){
            rep(i, 3){
                if ((oldc.first == i || oldc.second == i) && (c.first == i || c.second == i)){
                    tmp_mark = i;
                }
            }
        }
        oldc = c;
        mark[id] = tmp_mark;
    }
    //show(mark);

    if (cnt==0){
        cout << "No" << endl;
        return 0;
    } else if (cnt >= 2){
        rep(i, n){
            auto c = cmd_ch[i];
            if (a[c.first] <= a[c.second]){
                a[c.first]++;
                a[c.second]--;
                ans[i] = 'A' + c.first;
            } else {
                a[c.first]--;
                a[c.second]++;
                ans[i] = 'A' + c.second;
            }
        }
    } else {
        if (a[cmd_ch[0].first] == 0 && a[cmd_ch[0].second] == 0) isyes = false;
        rep(i, n){
            if (!isyes) break;
            auto c = cmd_ch[i];
            if (a[c.first] == 1 && a[c.second] == 1 && mark[i] != -1){
                if (c.first == tmp_mark){
                    a[c.first]++;
                    a[c.second]--;
                    ans[i] = 'A' + c.first;
                } else {
                    a[c.first]--;
                    a[c.second]++;
                    ans[i] = 'A' + c.second;
                }
            } else if (a[c.first] <= a[c.second]){
                a[c.first]++;
                a[c.second]--;
                ans[i] = 'A' + c.first;
            } else {
                a[c.first]--;
                a[c.second]++;
                ans[i] = 'A' + c.second;
            }
            if (a[c.first] < 0 || a[c.second] < 0) isyes = false;
        }
    }


    if (!isyes){
        cout << "No" << endl;
        return 0;
    } else {
        cout << "Yes" << endl;
    }

    rep(i, n) cout << ans[i] << endl;
//    cout << a[0] << a[1] << a[2] << endl;

}

