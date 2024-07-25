class Solution {
public:
    vector<vector<int>> flipAndInvertImage(vector<vector<int>>& image) {
        for(int i = 0; i < image.size(); i++){
            vector<int> a = image[i];
            for(int j = 0; j < a.size()/2; j++){
                  swap(a[j],a[a.size()-1-j]);
            }
            image[i] = a;
        }

        for(int i = 0; i<image.size(); i++){
            vector<int> a = image[i];
            for(int j = 0; j < a.size(); j++){
                if(a[j] == 1){
                    a[j] = 0;
                }else{
                    a[j] = 1;
                }
            }
            image[i] = a;
        }
        return image;
    }
};