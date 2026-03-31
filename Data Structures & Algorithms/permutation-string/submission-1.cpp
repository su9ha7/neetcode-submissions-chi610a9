class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int n1 = s1.length();
        int n2 = s2.length();
        if(n1>n2) return false ;
        vector<int>s1_counts(128,0);
        vector<int>window_counts(128,0);
        for( int i=0;i<n1;i++) {
            s1_counts[s1[i]]++;
            window_counts[s2[i]]++;
           
        }
        if (s1_counts == window_counts) return true;
        for( int i=n1;i<n2;i++) {
            window_counts[s2[i]]++;
            window_counts[s2[i-n1]]--;
            if (s1_counts == window_counts) return true;
        
    }
    return false;
    }
};
