class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        
        vector<int> vc(26,0);
        priority_queue<int> pq;

        for(int i = 0; i < tasks.size();i++){
            vc[tasks[i] - 'A']++;
        }

        for(int i = 0; i < vc.size(); i++){
            if(vc[i] > 0){
                pq.push(vc[i]);
            }
        }

        int count = 0;

        while(!pq.empty()){
            vector<int> temp;

            for(int i = 1; i <= n+1; i++){547
                if(!pq.empty()){
                    int freq = pq.top();
                    pq.pop();
                    freq--;
                    temp.push_back(freq);
                }
            }

            for(int i = 0; i < temp.size(); i++){
                if(temp[i] > 0){
                    pq.push(temp[i]);
                }
            }

            if(!pq.empty()){
                count += n+1;
            }else{
                count += temp.size();
            }
        }

        return count;
    }
};