#include <bits/stdc++.h>
using namespace std;

/*
Simple 4 Line Code ..... */
        int nextGreaterElement(int n)
        {
            auto digits = to_string(n);
            next_permutation(begin(digits), end(digits));
            auto res = stoll(digits);
            return (res > INT_MAX || res <= n) ? -1 : res;
        }

class Solution
{
public:
    void reverse(string &str, int len, int l, int r)
    {

        // Invalid range
        if (l < 0 || r >= len || l > r)
            return;

        // While there are characters to swap
        while (l < r)
        {

            // Swap(str[l], str[r])
            char c = str[l];
            str[l] = str[r];
            str[r] = c;

            l++;
            r--;
        }
        return;
    }
    int nextGreaterElement(int N)
    {
        string s = to_string(N);
        int n = s.size();
        int mini = INT_MAX, idx_min, i;
        for (i = n - 1; i >= 1; --i)
        {
            if (s[i - 1] - '0' < s[i] - '0')
            {
                break;
            }
        }
        if (i == 0)
            return -1;
        int idx = i - 1;
        // find the element which is just larger than a[i-1]th element
        int just = INT_MAX;
        for (int i = idx + 1; i < n; ++i)
        {
            if (s[idx] - '0' < s[i] - '0' && s[i] - '0' < just)
            {
                just = s[i] - '0';
                idx_min = i;
            }
        }
        swap(s[idx], s[idx_min]);
        reverse(s, n, idx + 1, n - 1);
        return stoi(s);
    }
};

int main()
{
}