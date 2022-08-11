#include<bits/stdc++.h>
using namespace std;
 string solve(int arr[], int n) {
        sort(arr,arr+n);
        string str1 = "",str2 = "";
        for(int i = 0;i<n-1;i+=2)
        {
            str1.push_back(arr[i]+'0');
            str2.push_back(arr[i+1]+'0');
        }
        if(i<n)
        {
            str1.push_back(arr[i]+'0');
        }
        
        return to_string(stoi(str1)+stoi(str2));

    }