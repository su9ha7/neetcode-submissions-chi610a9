class Solution {
public:
    string reorganizeString(string s) {
        unordered_map<char,int>counts;
        for(char c : s){
            counts[c]++;
        }
        priority_queue<pair<int,char>>maxHeap;
        for(auto pair : counts){
            if(pair.second>(s.size()+1)/2){
                return "";
            }
            maxHeap.push({pair.second,pair.first});
        }
        string result ="";
        while(maxHeap.size()>=2){
            auto[count1,char1] = maxHeap.top();
            maxHeap.pop();
            auto[count2,char2] = maxHeap.top();
            maxHeap.pop();
            result+= char1;
            result+= char2;
            if(--count1>0){
                maxHeap.push({count1,char1});
            }
            if(--count2>0){
                maxHeap.push({count2, char2});
            }
        }
        if(!maxHeap.empty()){
            auto[count1,char1] = maxHeap.top();
            result +=char1;
        }
        return result;
        
    }
};