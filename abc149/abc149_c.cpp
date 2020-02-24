#include <bits/stdc++.h>
using namespace std;
#define MOD 1000000007
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
#define show(x) for(auto i: x){cout << i << " ";}
typedef long long ll;

bool isprime(int n){
    for(int i = 2; i*i < n; i++){
        if (n % i == 0){
            return false;
        }
    }
    return true;
}


int main()
{
    int x;
    cin >> x;
    while(1){
        if(isprime(x)){
            cout << x << endl;
            return 0;
        }
        x++;
    }
}

