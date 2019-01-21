#include <iostream>
#include <vector>
using namespace std;

#define ARRMAX 100001
int cnt[ARRMAX][2] = {0};
int maxcnt[2] = {0}; 
int maxcntnum[2] = {0};
int max2ndcnt[2] = {0};
int max2ndcntnum[2] = {0};

vector<int> even,odd;

void lanking(){
    for (int i = 0; i < ARRMAX; i++){
        
        for(int j = 0; j < 2; j++)
        {
            //printf("cnt%d %d %d num:%d %d\n",cnt[i][j],maxcnt[0],maxcnt[1],maxcntnum[0],maxcntnum[1]);
            if (cnt[i][j] > maxcnt[j]){
                max2ndcnt[j] = maxcnt[j];
                max2ndcntnum[j] = i;
                maxcnt[j] = cnt[i][j];
                maxcntnum[j] = i;
            } else if (cnt[i][j] > max2ndcnt[j]){
                max2ndcnt[j] = cnt[i][j];
                max2ndcntnum[j] = i;
            }
        }       
    }
    //printf("%d %d num:%d %d",maxcnt[0],maxcnt[1],maxcntnum[0],maxcntnum[1]);
    return;
}


int main(){
    int N;
    cin >> N;
    for (int i = 0; i < N; i++){
        int tmp;
        cin >> tmp;
        cnt[tmp][i%2]++;
    
    }

    lanking();
    int ans;
    if (maxcntnum[0] != maxcntnum[1]){
        ans = N - (maxcnt[0] + maxcnt[1]);
    } else {
        if (maxcnt[0] + max2ndcnt[1] < maxcnt[1] + max2ndcnt[0]){
            ans = N - (maxcnt[1] + max2ndcnt[0]);
        } else {
            ans = N - (maxcnt[0] + max2ndcnt[1]);
        }
    }

    cout << ans << endl;
}
