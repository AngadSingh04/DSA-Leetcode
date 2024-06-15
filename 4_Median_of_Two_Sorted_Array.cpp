class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        double a;
        for(int i = 0; i < nums2.size(); i++){
            nums1.push_back(nums2[i]);
        }
        sort(nums1.begin(), nums1.end());
        if(nums1.size()%2==0){
            a = (nums1[nums1.size()/2] + nums1[((nums1.size()-1)/2)])/2.0;
        }else{
            a = nums1[(nums1.size()/2)];
        }

        return a;
    }
};