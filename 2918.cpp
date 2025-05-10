class Solution {
public:
    long long minSum(vector<int>& v1, vector<int>& v2) {
        long long s1=0,s2=0;
        int c1=0,c2=0;
        int n=v1.size(),m=v2.size();
        for(auto i:v1){
            if(i==0)
                c1++;
            s1=s1+i;
        }
        for(auto i:v2){
            if(i==0)
                c2++;
            s2=s2+i;
        }
        s1=s1+c1;
        s2=s2+c2;
        
        if(s2>s1){
            swap(s1,s2);
            swap(c1,c2);
        }
        if(s1!=s2 && c1==0 && c2==0)
            return -1;
        if(s1!=s2 && c2==0)
            return -1;
        return s1;
        
    }
};