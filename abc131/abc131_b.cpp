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
    int n, l;
    cin >> n >> l;
    int sum = l*n + n*(n-1)/2;
    int d = n + l - 1;
    if (l <= 0 && d >= 0){
        cout << sum << endl;
    } else if (d < 0) {
        cout << sum - d<< endl;
    } else {
        cout << sum - l<< endl;
    }
}

