#include <bits/stdc++.h>
using namespace std;
#define MOD 1000000007
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
#define show(x) for(auto i: x){cout << i << " ";}
#define showm(m) for(auto i: m){cout << m.x << " ";}
typedef long long ll;
typedef pair<int, int> P;


int main()
{
    int qn;
    cin >> qn;
    vector<int> A;
    ll B = 0;
    ll mid = 0;
    priority_queue<int, vector<int>, less<int>> que_gre;//大きいものから取り出したい
    priority_queue<int, vector<int>, greater<int>> que_less;//小さいものから取り出したい
    rep(i, qn){
        int q, a, b;
        cin >> q;
        if (q == 1) cin >> a >> b;
        if (i == 0){
            que_gre.push(a);
            que_less.push(a);
            B += b;
            continue;
        }

        if (q == 1){
            que_gre.push(a);
            que_less.push(a);
            int g_top = que_gre.top();
            int l_top = que_less.top();
            if ( g_top > l_top){
                mid += g_top - l_top;
                que_gre.pop();
                que_less.pop();
                que_gre.push(l_top);
                que_less.push(g_top);
            }
            B += b;
        } else {
            cout << que_gre.top() <<" "<< mid + B << endl;
        }
    }
}

