#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
 
 
int main(){
    int N;
    unsigned long long X;
    unsigned long long sum[200010];
    cin >> N >> X;
    for (int i = 1; i <= N; i++){
        //仮想配列かどうかはスピードに影響を与えない。
        unsigned long long tmp;
        cin >> tmp;
        //後々の計算量削減のため、この時点で和を取っておく。
        sum[i] = sum[i-1] + tmp;
    }
    unsigned long long min_energy = 0;
    for (int k=1; k <= N / 2 + 1; k++){
        unsigned long long energy = 0;
        //weightをint型にしたらオーバーフローした。なぜ？
        int weight = 5;
        for (int i=0; i <= N/k; i++){
            if (i == 0){
                weight = 5;
            } else {
                weight = 5 + 2*(i - 1);
            }
            int M = N - k*i;
            int m = (M - k) >= 0 ? M - k : 0L;
            energy += (sum[M] - sum[m]) * weight;
            //printf("%d,%d,%llu\n",k,weight,sum[M]-sum[m]);
        }
        energy += (N + k)*X;
        if (k == 1) min_energy = energy;
        if (min_energy >= energy){
            min_energy = energy;
        }
    }
    printf("%llu",min_energy);
}