
#include <bits/stdc++.h>

using namespace std;
 
typedef long long ll;


int main(){
    int n,a,b;
    cin >> n >> a >> b;

    cout << min(a,b) << " " << max(((a + b) - n), 0) << endl;

}