/*
 * @Author: crab-in-the-northeast 
 * @Date: 2020-03-31 12:46:34 
 * @Last Modified by: crab-in-the-northeast
 * @Last Modified time: 2020-03-31 14:00:54
 */
#include <iostream>
#include <cstdio>
#include <algorithm>

const int maxn = 115;
const std :: string jobname[] = {
    "JiangYou", "BangZhong", "JingYing", "TangZhu", "ZhangLao",
    "HuFa", "FuBangZhu", "BangZhu"
};

inline int job_str_to_int(std :: string str_job) {
    if(str_job == "BangZhong") return 1;
    if(str_job == "JingYing") return 2;
    if(str_job == "TangZhu") return 3;
    if(str_job == "ZhangLao") return 4;
    if(str_job == "HuFa") return 5;
    if(str_job == "FuBangZhu") return 6;
    return 7;
}

int n;
struct people {
    std :: string name;
    int job, level, score, num;
}a[maxn];

bool cmp(people a, people b) {
    if(a.score != b.score) return a.score > b.score;
    return a.num < b.num;
}

bool cmp2(people a, people b) {
    if(a.job != b.job) return a.job > b.job;
    if(a.level != b.level) return a.level > b.level;
    return a.num < b.num;
}

int main() {
    std :: cin >> n;
    for(int i = 1; i <= n; i++) {
        std :: string str_job;
        std :: cin >> a[i].name >> str_job >> a[i].score >> a[i].level;
        a[i].job = job_str_to_int(str_job);
        a[i].num = i;
    }
    std :: sort(a + 4, a + 1 + n, cmp);
    
    for(int i = 4; i <= n; i++) {
        if(i <= 5) a[i].job = 5;
        else if(i <= 9) a[i].job = 4;
        else if(i <= 16) a[i].job = 3;
        else if(i <= 41) a[i].job = 2;
        else a[i].job = 1;
    }

    std :: sort(a + 4, a + 1 + n, cmp2);
    for(int i = 1; i <= n; i++) 
        std :: cout << a[i].name << ' ' << jobname[a[i].job] << ' ' << a[i].level << std :: endl;  
    return 0;
}