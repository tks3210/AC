#include <iostream>
#include <vector>
using namespace std;

int main(){
    int N;
    cin >> N;
    int ans = ((N - 1) / 111 + 1)*111; 
    cout << ans;
}