class Solution {
    public:
        int countSymmetricIntegers(int low, int high) {
            int count = 0;
            for(int i = low; i <= high; i++){
                int firstS = 0;
                int secondS = 0;
                string a = to_string(i);
                if(a.length()%2 != 0){
                    continue;
                }
                int l = a.length();
                int hl = l/2;
                int k = i;
                while(l>hl){
                    int rem = k%10;
                    firstS += rem;
                    k = k/10;
                    l--;
                }
                while(l>0){
                    int rem = k%10;
                    secondS += rem;
                    k = k/10;
                    l--;
                }
                if(firstS == secondS){
                    count++;
                }
            }
            return count;
    
        }
    };