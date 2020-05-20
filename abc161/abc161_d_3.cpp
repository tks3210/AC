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

/*
数列生成　K番目

隣接する桁の数字の差が1以内である数をlunlun numberと呼ぶ（2343,87とか）
lunlun numberの生成には、
fdsで全数字を生成するか、
全数字を木の頂点と考え、queueで幅優先探索っぽく次の数字を追加することで実現できる。
後者だと、追加順が数字の昇順になってて美しい

*/


int main(){
    int k; cin >> k;

    queue<ll> a;
    for (int i = 1; i < 10; i++)
    {
        a.push(i);
    }
    
    ll num = 0;
    while(k!=0){
        num = a.front(); a.pop();
        int num1 = num%10;
        if (num1!=0) a.push(num*10 + num1-1);
        a.push(num*10 + num1);
        if (num1!=9) a.push(num*10 + num1+1);
        k--;
    }

    cout << num << endl;

}