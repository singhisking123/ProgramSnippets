#include <bits/stdc++.h>
using namespace std;
// struct Node
// {
//     int data;
//     Node *left, *right;
//     Node(int value)
//     {
//         data = value;
//         left = right = NULL;
//     }
// };
int totalFruit(vector<int> &fruits)
{
    int res = 0;
    int n = fruits.size();
    unordered_map<int, int> map;
    int i = 0;
    bool flag = true;
    while (i < n && map.size() <= 2)
    {
        map[fruits[i]]++;
        if (map.size() > 2)
        {
            flag = false;
        }
        i++;
    }
    int low = 0;
    if (flag == true)
        res = max(res, i - low);
    else
        res = max(res, i - low - 1);
    for (; i < fruits.size();)
    {
        while (map.size() > 2)
        {
            map[fruits[low]]--;
            if (map[fruits[low]] == 0)
            {
                map.erase(map[fruits[low]]);
            }
            low++;
        }
        bool flag = true;
        while (i < n && map.size() <= 2)
        {
            map[fruits[i]]++;
            if (map.size() > 2)
            {
                flag = false;
            }
            i++;
        }
        if (flag == true)
            res = max(res, i - low);
        else
            res = max(res, i - low - 1);
    }
    return res;
}
int main()
{
    vector<int>fruits = {1,2,3,2,2};

    return totalFruit(fruits);
}