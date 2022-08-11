#include<bits/stdc++.h>
using namespace std;

// Given a set of non-negative integers, and a value sum, determine 
// if there is a subset of the given set with sum equal to given sum. 

// this problem is quite similar to 0/1knapsack
//either we include the number either we exclude it;
bool isSubsetSum(int arr[], int n, int sum)
{
   
    // Base Cases
    if (sum == 0)
        return true;
    if (n == 0)
        return false;
 
    // If last element is greater than sum,
    // then ignore it
    if (arr[n - 1] > sum)
        return isSubsetSum(arr, n - 1, sum);
 
    /* else, check if sum can be obtained by any
of the following:
      (a) including the last element
      (b) excluding the last element   */
    return isSubsetSum(arr, n - 1, sum)
           || isSubsetSum(arr, n - 1, sum - arr[n - 1]);
}

// dp aproach
 bool issubsetsum(vector<int>&arr,int sum )
{
    int n = arr.size();
    bool dp[n+1][sum+1];
    for(int i = 0;i<=n;i++)
    {
        for(int j = 0;j<=sum;j++)
        {
            if(j==0)
                dp[i][j] = true;
            else if(i==0)
                dp[i][j] = false;
            else if(arr[i-1]>j)
            dp[i][j]  = dp[i-1][j];
            else{
               
                dp[i][j] = dp[i-1][j] || dp[i-1][j-arr[i-1]];
            }
            
        }
    }
    return dp[n][sum];
}

 