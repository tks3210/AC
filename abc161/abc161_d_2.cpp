#include <bits/stdc++.h>
using namespace std;
#define MOD 1000000007
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
#define rep1(i, n) for(int i = 1; i <= (int)(n); i++)
#define show(x) {for(auto i: x){cout << i << " ";} cout<<endl;}
#define showm(m) {for(auto i: m){cout << m.x << " ";} cout<<endl;}
typedef long long ll;
typedef pair<int, int> P;
ll gcd(int x, int y){ return y?gcd(y, x%y):x;}
ll lcm(ll x, ll y){ return (x*y)/gcd(x,y);}


void fds(vector<ll> &s, int keta, string tmp){

    if (tmp.size() == keta){
        s.push_back(stoll(tmp));
        return;
    }
    if (tmp == ""){
        for (int i = 1; i <= 9; i++)
        {
            fds(s, keta, to_string(i));
        } 
        return;       
    }
    int num = tmp[tmp.size()-1] - '0';

    if (num!=0) fds(s, keta, tmp+to_string(num-1));
    fds(s, keta, tmp+to_string(num));
    if (num!=9) fds(s, keta, tmp+to_string(num+1));
    return;
}




int main(){
    int k; cin >> k;

    vector<ll> s;
    rep(i, 10){
        fds(s, i+1, "");
    }

    sort(s.begin(), s.end());
    
    cout << s[k-1] << endl;    
}