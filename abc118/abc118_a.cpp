#include <bits/stdc++.h>

using namespace std;
 
typedef long long ll;
 

int main(){
    int n, m;

    cin >> n >> m;
    int ans = (m % n == 0) ? m + n : m - n;
    cout << ans << endl;
}