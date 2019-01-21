#include <iostream>

using namespace std;

int main(){
    int a,b,c; 
    cin >> a >> b >> c;

    int ans = 0;
    if (a <= b){
        if (b <= c){
            ans = c*10 + (a + b);
        }else{
            ans = b*10 + (a + c);
        }
    }else{
        if (a <= c){
            ans = c*10 + (a + b);
        }else{
            ans = a*10 + (b + c);
        }
    } 
    cout << ans << endl;
}