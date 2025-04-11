#include<iostream>
#include<vector>
using namespace std;

bool safe(vector<int> v, int i){
    if(i==0 && v[i+1] && v[i+1] == 1){
        return false;
    }
    else if(i == v.size() -1){
        if(v[i-1] == 1){
            return false;
        }
    }
    else if(v[i-1] == 1 || v[i+1] == 1){
        return false;
    }

    return true;
}

int help(vector<int> &v, int K, int count, int index){
    if(count == K) return 1;
    if(v.size() == index) return 0;

    for(int i = index; i < v.size(); i++){
        if(v[i]==0 && safe(v, i)){
            count++;
            v[i] = 1;
            if(help(v, K, count, index +1)){
                return 1;
            }

            count--;
            v[i] = 0;
        }
        else{
            if(help(v, K, count, index +1)){
                return 1;
            }
        }
    }

    return 0;
}

int solve(vector<int> v, int K){
    return help(v, K, 0, 0);
}

int main(){
    vector<int> v;
    v.push_back(0);
    v.push_back(0);
    v.push_back(1);
    v.push_back(0);
    v.push_back(1);

    cout<<solve(v, 2);
}


// [1, 0, 0 ,0, 0, 0, 1 ,0, 1]