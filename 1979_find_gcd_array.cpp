#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int findGCD(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int a = nums[nums.size()-1];
        int b = nums[0];
        int ans = 0;
        for(int i = b; i > 0; i--){
            if(a%i==0 && b%i==0){
                ans = i;
                break;
            }
        }
        return ans;
    }
};
int main(){
    vector<int> myarr;
    myarr.push_back(2);
    myarr.push_back(3);
    myarr.push_back(7);
    myarr.push_back(10);

    return 0;
}