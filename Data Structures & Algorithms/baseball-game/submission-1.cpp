class Solution {
public:
    int calPoints(vector<string>& operations) {
        stack<int>s;
        for( string op : operations){
            if(op=="+"){
                int topVal = s.top();
                s.pop();
                int newVal = topVal + s.top();
                s.push(topVal);
                s.push(newVal);
            }
            else if ( op =="D"){
                s.push(s.top()*2);
            }
            else if ( op =="C"){
                s.pop();
            }
            else{
                s.push(stoi(op));
            }
        }
        int total =0;
        while(!s.empty()){
            total+=s.top();
            s.pop();
        }
        return  total;
        
    }
};