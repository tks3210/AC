#include <iostream>
#include <vector>
#include <stdlib.h>
#include <algorithm>
#define min(x, y) (x > y ? y : x)
using namespace std;

struct City
{
    int kennum, citynum, year, sortnum;
};

bool cmp_kencity(const City &a, const City &b){
    if (a.kennum != b.kennum){
        return a.kennum < b.kennum;
    }
    return a.year < b.year;
}

bool cmp_num(const City &a, const City &b){
    return a.citynum < b.citynum;
}

int main()
{

    int N, M;
    cin >> N >> M;
    vector<City> citydata(M);

    for (int i = 0; i < M; i++)
    {
        int tmpP, tmpY;
        citydata[i].citynum = i;
        cin >> citydata[i].kennum >> citydata[i].year;
    }

    sort(citydata.begin(), citydata.end(), cmp_kencity);

    int kenstart = 0;
    int number = 0;
    for(int i = 0; i < M; i++)
    {   
        if (citydata[i].kennum > kenstart){
            kenstart = citydata[i].kennum;
            number = 1;
        }
        citydata[i].sortnum = number;
        number++;
    }
    sort(citydata.begin(), citydata.end(), cmp_num);
    
    for(auto i :citydata)
    {
        printf("%06d%06d\n", i.kennum, i.sortnum);
    }
    
}