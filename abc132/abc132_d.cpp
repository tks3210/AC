#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

ll calcComb(int a, int b);
ll mod = 1000000007;
ll modpow(ll a, int p);

int main(){
    int N, K;
    cin >> N >> K;

    ll ans;
    for (int i = 1; i <= K ; i++)
    {
        ans = calcComb(N-K+1, i);
        ans %= mod;
        ans *= calcComb(K-1, i-1);
        ans %= mod;
        if (N - K + 1 < i) ans = 0;
        cout << ans << endl;
    }
}

//aCb
ll calcComb(int a, int b){
    if (b > a-b) return calcComb(a,a-b);
    ll ansMul =1;
    ll ansDiv =1;
    for(int i = 0; i < b; i++)
    {
        /* code */
        ansMul *= (a-i);
        ansDiv *= (i+1);
        ansMul %= mod;
        ansDiv %= mod;
    }
    //ansDivの逆元を使う。
    ll ans = ansMul * modpow(ansDiv, mod -2) % mod;
    return ans;
}


//aのp乗を求めるアルゴリズム
//p=62>31>30>15>14>7>6>3>2>1>0
//計算量はO(logp)になる。
ll modpow(ll a, int p){
    if (p == 0) return 1;
    if (p%2 == 0){
        //p even
        int halfP = p/2;
        ll half = modpow(a, halfP);
        //a^(p/2)をhalfとしてhalf*halfを計算
        return half * half % mod;
    }
    else {
        return a * modpow(a, p-1) % mod; 
    }
}