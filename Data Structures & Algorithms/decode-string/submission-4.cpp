class Solution {
public:
    string decodeString(string s) {
        stack<int>st;
        stack<string> resultstack;
        string currentstring = "";
        int k=0;
        for(char c: s){
            if(isdigit(c)){
                k = k*10 + (c-'0');
            }
        
        else if (c=='['){
            st.push(k);
            resultstack.push(currentstring);
            currentstring ="";
            k=0;
        }
        else if (c==']'){
            string temp = currentstring;
            currentstring=resultstack.top();
            resultstack.pop();
            int count = st.top();
            st.pop();
            while (count>0){
                currentstring+=temp;
                count--;
            }
        }
        else{
            currentstring +=c;

        }
        }
    

        
    
    return currentstring;
}
};