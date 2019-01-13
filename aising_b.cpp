#include <iostream>
#include <vector>
#include <stdlib.h>
#include <algorithm>
using namespace std;

int main(){
    int n;
    int a, b;
    cin >> n >> a >> b;
    vector<int> p;
    
    for(int i = 0; i < n; i++)
    {
        int tmp;
        cin >> tmp;
        p.push_back(tmp);
    }
    sort(p.begin(), p.end());
    int cnt[3]={0};

    for(auto i: p){
        if (i <= a){
            cnt[0]++;
        }else if(i <= b){
            cnt[1]++;
        }else{
            cnt[2]++;
        }
    }
    int ans;
    ans = min(cnt[0], cnt[1]);
    ans = min(ans, cnt[2]);
    cout << ans << endl;
}