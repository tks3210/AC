#include <string>
#include <iostream>
#include <algorithm>
using namespace std;

int h[10] = {0};


int pow_2(int n)
{
    int ans = 1;
    for (int i = 0; i < n; i++)
    {
        ans *= 2;
    }
    return ans;
}

int select_book(int N, int H, int bitbook)
{
    if (bitbook == 0){
        return 1;
    }
    int sum = 0;
    int ans = 0;
    for (int i = 0; i < N; i++)
    {
        
        int isbook = (bitbook >> i) % 2;
        if (isbook == 1)
        {
            //printf("i:%d bit:%d\n",i,bitbook);
            bitbook -= pow_2(i);
            sum += h[i];
            if (sum > H)
            {
                break;
            }
            ans += select_book(N, H, bitbook);            
        }
    }
    return ans;
}


int main()
{
    int N, H;
    cin >> N >> H;

    for (int i = 0; i < N; i++)
    {
        int tmp;
        cin >> tmp;
        h[i] = tmp;
    }
    int bitbook = pow_2(N) - 1;

    int num = select_book(N, H, bitbook);
    cout << num << endl;
}