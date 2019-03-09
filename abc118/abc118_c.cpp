#include <bits/stdc++.h>

using namespace std;
 
typedef long long ll;
 

ll gcd(int x, int y){ return y?gcd(y, x%y):x;}

int main(){
    int n;

    cin >> n;
    vector<int> a;
    for(int i = 0; i < n; i++)
    {
        int tmp;
        cin >> tmp;
        a.push_back(tmp);
    }

    ll ans = gcd(a[0],a[1]);
    for(int i = 2; i < n ; i++)
    {
        ans = gcd(ans, a[i]);

    }
        
    cout << ans << endl;

}