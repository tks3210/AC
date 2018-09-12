#include <iostream>
using namespace std;

int gcd(int x, int y){ return y?gcd(y, x%y):x;}

int main(){
    int N, X;
    int toshi[100000];
    cin >> N >> X;
    for (int i = 0; i < N; i++){
        cin >> toshi[i];
        toshi[i] -= X;
        if (toshi[i] <= 0){
            toshi[i] = -toshi[i];
        }
    }
    int ans;
    if (N != 1){
        ans = gcd(toshi[0], toshi[1]);
        for (int i = 2; i < N; i++){
            ans = gcd(ans, toshi[i]);
        }
    } else {
        ans=toshi[0];
    }
    cout << ans << endl;
}