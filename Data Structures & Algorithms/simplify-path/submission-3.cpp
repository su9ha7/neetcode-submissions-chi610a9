class Solution {
public:
    string simplifyPath(string path) {
        stack<string>st;
        stringstream ss(path);
        string temp;
        while(getline(ss,temp,'/')){
            if(temp==""|| temp =="."){
                continue;
            }
            if (temp==".."){
                if(!st.empty()) st.pop();
            }
            else{
                st.push(temp);
            }
        }
            string result ="";
            while(!st.empty()){
                result ="/" + st.top() + result;
                st.pop();
            }
        return result.empty() ? "/" :result;
    }
        
    };
