class Solution {
public:

    int binSearch(vector<int>& arr,int target, int st,int end ){
        if(st <= end){
            int mid = st + (end - st)/2;
            if(arr[mid] == target){
                return mid;
            }
            else if(target < arr[mid]){
                return binSearch(arr,target,st,mid - 1);
            }
            else{
                return binSearch(arr,target,mid+1,end);
            }
        }
        return -1;   
    }
    int search(vector<int>& nums, int tar) {
        int st = 0,end = nums.size()-1;
        return binSearch(nums,tar,st,end);
    }
};