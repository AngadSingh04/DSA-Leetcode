class Solution {
    public:
        string removeOccurrences(string s, string part) {
            // s.find(part) --> first occurence bata deta he uss part ki jahan se shuru ho rha he 
            //s.erase(s.find(part), part.length()) --> to erase from first occurence of that index to the length of that part
    
            while(s.length()!=0 && s.find(part) < s.length()){
                s.erase(s.find(part), part.length());
            }
            return s;
        }
    };