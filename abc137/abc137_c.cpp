#include <bits/stdc++.h>
using namespace std;
#define MOD 1000000007
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
#define rep1(i, n) for(int i = 1; i <= (int)(n); i++)
#define show(x) for(auto i: x){cout << i << " ";}
#define showm(m) for(auto i: m){cout << m.x << " ";}
typedef long long ll;
typedef pair<int, int> P;


int main()
{
    int N;
    cin >> N;
    vector<string> s;
    rep(i, N){ string tmp; cin >> tmp; sort(tmp.begin(), tmp.end());s.push_back(tmp);}

//    show(s);
    sort(s.begin(), s.end());
//    show(s);


    ll ans = 0;
    ll tmp_cnt = 0;
    rep(i, N-1){
        if (s[i] == s[i+1]){
            tmp_cnt++;
        } else {
            ans += tmp_cnt * (tmp_cnt + 1) /2;
            tmp_cnt = 0;
        }
//        cout << tmp_cnt << endl;
    }
    ans += tmp_cnt * (tmp_cnt + 1) /2;

    cout << ans << endl;

}

