class Solution {
public:
    int countCharacters(vector<string>& words, string chars) {
        int sum = 0;
        int arr1[26] = {0};
        for(int i = 0; i < chars.size(); i++){
            arr1[chars[i] - 'a']++;
        }
        for(int i = 0; i < words.size(); i++){
            string a = words[i];
            int l = a.size();
            bool istrue = true;
            int arr2[26] = {0};
            for(int i = 0; i < l; i++){
                arr2[a[i] - 'a']++;
                if(arr1[a[i] - 'a'] < arr2[a[i] - 'a']){
                    istrue=false;
                    break;
                }
            }
            if(istrue){
                sum += l;
            }
        }
        return sum;
    }
};