
#include <bits/stdc++.h>
using namespace std;
 
typedef long long ll;


int main(){
    int n;
    string a,b,c;
    cin >> n;
    cin >> a;
    cin >> b;
    cin >> c;

    int ans = 0;
    for(int i = 0; i < n; i++)
    {
        int tmp = 0;
        if (a[i] == b[i] && b[i] == c[i]){
            tmp = 0;
        }else if(a[i] != b[i] && b[i] != c[i] && c[i] != a[i]){
            tmp = 2;
        }else{
            tmp = 1;
        }
        ans += tmp;
    }
    
    cout << ans << endl;

}