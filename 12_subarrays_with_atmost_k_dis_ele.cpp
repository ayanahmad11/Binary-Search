/*
link : https://www.geeksforgeeks.org/problems/subarrays-with-at-most-k-distinct-integers/1

*You are given an array arr[] of positive integers and an integer k,
* find the number of subarrays in arr[] where the count of distinct integers
* is at most k.

Note: A subarray is a contiguous part of an array.

Examples:

Input: arr[] = [1, 2, 2, 3], k = 2
Output: 9
Explanation: Subarrays with at most 2 distinct elements are:
 [1], [2], [2], [3], [1, 2], [2, 2], [2, 3], [1, 2, 2] and [2, 2, 3].

*/
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool check(int st, int mid, int k, vector<int>& arr) {
        unordered_map<int, int> freq;
        for (int i = st; i <= mid; i++) {
            freq[arr[i]]++;
            if (freq.size() > k) return false;
        }
        return true;
    }

    int atMostK(vector<int> &arr, int k) {
        int n = arr.size();
        int res = 0;
        for (int st = 0; st < n; st++) {
            int lo = st, hi = n - 1;
            int ans = st - 1;
            while (lo <= hi) {
                int mid = (lo + hi) / 2;
                if (check(st, mid, k, arr)) {
                    ans = mid;
                    lo = mid + 1;
                } else {
                    hi = mid - 1;
                }
            }
            res += (ans - st + 1);
        }
        return res;
    }
};