class Solution {
public:
    bool checkEquilateralTriangle(vector<int>& nums){
        if(nums[0] == nums[1] && nums[0] == nums[2])
            return true;
        else
            return false;
    }
    bool checkIsoscelesTriangle(vector<int>& nums){
        if((nums[0] == nums[1]) || (nums[0] == nums[2])  || (nums[1] == nums[2]))
            return true;
        else
            return false;
    }
    bool isTriangle(vector<int>& nums){
        if((nums[0] < nums[1]+nums[2]) && (nums[1] < nums[0]+nums[2]) && (nums[2] < nums[0]+nums[1]))
            return true;
        else
            return false;
    }
    string triangleType(vector<int>& nums) {
        if(!isTriangle(nums))
            return "none";
        else if(checkEquilateralTriangle(nums))
            return "equilateral";
        else if(checkIsoscelesTriangle(nums))
            return "isosceles";
        else
            return "scalene";
    }
};