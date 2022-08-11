#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> leftSmaller(int n, int a[]) {
        stack<int> st;
        vector<int> res(n, -1);
        for (int i = n - 1; i >= 0; --i) {
            while (!st.empty() && a[i] < a[st.top()]) {
                res[st.top()] = a[i];
                st.pop();
            }
            st.push(i);
        }
        return res;
    }
};

int main()
{
}