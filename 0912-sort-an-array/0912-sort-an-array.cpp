class Solution {
public:
    void mergeSort(vector<int>&a,int left,int mid,int right){
        int low = left;
        int high = mid+1;
        vector<int>temp;
        while(low<=mid && high<=right){
            if(a[low]<=a[high]){
                temp.push_back(a[low++]);
            }
            else{
                temp.push_back(a[high++]);
            }
        }
        while(low<=mid){
            temp.push_back(a[low++]);
        }
        while(high<=right){
            temp.push_back(a[high++]);
        }
        for(int i=left;i<=right;i++){
            a[i]=temp[i-left];
        }
    }
    void merge(vector<int>&arr,int left,int right){
        if(left>=right) return;
        int mid = (right+left)/2;
        merge(arr,left,mid);
        merge(arr,mid+1,right);
        mergeSort(arr,left,mid,right);
    }
    vector<int> sortArray(vector<int>& nums) {
        int left = 0;
        int right = nums.size()-1;
        merge(nums,left,right);
        return nums;
    }
};