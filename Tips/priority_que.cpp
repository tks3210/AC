#include <bits/stdc++.h>
using namespace std;
#define MOD 1000000007
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
typedef long long ll;

typedef struct{
    int mem1;
    int mem2;
} test;



int main(){

    auto compare = [](const test& a, const test& b){ 
        if (a.mem1 != b.mem1){
            return a.mem1 > b.mem1;
        } else {
            return a.mem2 > b.mem2;
        }
    };
    priority_queue<test, vector<test>, decltype(compare)> p(compare);

    p.push({1,2});
    p.push({7,2});
    p.push({3,2});
    p.push({4,2});
    p.push({6,2});
    p.push({3,2});
    p.push({1,5});

    while(!p.empty()){
        printf("%d %d\n", p.top().mem1, p.top().mem2);
        p.pop();
    }

}