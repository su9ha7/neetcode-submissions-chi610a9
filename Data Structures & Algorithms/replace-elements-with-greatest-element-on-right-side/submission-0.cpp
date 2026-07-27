class Solution {
public:
    vector<int> replaceElements(vector<int>& arr) {
        int n = arr.size();
        for(int i=0;i<n;i++){
            int maxi =-1;
        
        for( int j=i+1;j<n;j++){
            if(arr[j]>maxi){
                maxi=arr[j];
            }
        }
        arr[i]=maxi;
        
    }
    return arr;
    }
};