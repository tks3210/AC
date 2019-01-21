#include <iostream>
#include <vector>
using namespace std;


#define max_3base 29527
int main(){

    int N;
    cin >> N;

    int cnt = 0;
    for(int i = 1; i <= max_3base; i++)
    {
        int flag[3] = {0};
        int num = i;
        vector<int> buf;
        int ans;
        while((num - 1) / 3 != 0){
            buf.push_back((num - 1) % 3);
            flag[(num - 1) % 3] = 1;
            num -= 1;
            num /= 3;
        } 
        buf.push_back((num - 1) % 3);
        flag[(num - 1) % 3] = 1;

        if (flag[0]*flag[1]*flag[2] == 0) continue;

        int tmp = 0;
        int amp = 1;
        for(int i = 0; i < buf.size(); i++)
        {
            tmp += (3 + (buf[i] * 2)) * amp;
            amp *= 10;
        }


        if (N < tmp) break;
        
        //cout << tmp << endl;
        cnt++;

    }

    cout << cnt << endl;


}