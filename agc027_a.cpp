#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> a;
int main(){
    int N, x;
    cin >> N >> x;
    for (int i = 0; i < N; i++){
        int tmp;
        cin >> tmp;
        a.push_back(tmp);
    }
    sort(a.begin(),a.end());
    int sum = 0;
    int ans = 0;
    for (int i=0; i < a.size(); i++){
        sum += a[i]; 
        if (x < sum){
            break;
        }
        if (i == a.size()-1){
            if (x != sum){
                break;
            }
        }
        ans++;
    }

    printf("%d",ans);
}