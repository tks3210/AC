#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> x;


int main(){
    int N,X;
    cin >> N >> X;
    for (int i = 0; i < N; i++){
        int tmp;
        cin >> tmp;
        x.push_back(tmp);
    }
    sort(x.begin(),x.end(),greater<int>());
    int br_num = 0;
    int energy = 0;
    energy += 5 * x[0] + 2 * X;
    br_num = 2;
    for (int i=1; i < x.size(); i++){
        //pick or nopick
        //printf("buf%d\n",energy);
        int pick = ( br_num * 2 + 1 ) * x[i] + X;
        int nopick = 5 * x[i] + 2*X;
        if (pick <= nopick){
            //pick
            energy += pick;
            br_num++;
        } else {
            //nopick
            energy += nopick;
            br_num=1;
        }
    }
    printf("%d",energy);
}