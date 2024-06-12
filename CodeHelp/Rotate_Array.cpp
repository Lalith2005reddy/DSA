#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        vector<int> temp(nums.size());
        int i=0;
        while(i != nums.size()){
            temp[(i+k)%nums.size()]= nums[i];
            i++;
        }
        nums = temp;

    }
};