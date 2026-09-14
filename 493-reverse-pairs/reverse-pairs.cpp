class Solution {
public:
    void merge(vector<int>& arr, int i, int j, int mid){
        if(i<j){
            int a=i;
            int b=mid+1;
            int count=0;
            vector<int> sorted;
            
            while(a<=mid && b<=j){
                if(arr[a]<=arr[b]){
                    sorted.push_back(arr[a]);
                    a++;
                }
                else{
                    sorted.push_back(arr[b]);
                    b++;
                }
            }
            while(a<=mid){
                sorted.push_back(arr[a]);
                a++;
            }while(b<=j){
                sorted.push_back(arr[b]);
                b++;
            }
            
            for(int k=0; k<sorted.size(); k++){
                arr[i+k] = sorted[k];
            }
        }
    }
    int countIt(vector<int>& arr, int i, int j, int mid){
        if(i<j){
            int a=i;
            int b=mid+1;
            int count=0;
            
            while(a<=mid && b<=j){
                if(arr[a]<=2*(long)arr[b]){
                    a++;
                }
                else{
                    count+=(mid-a+1);
                    b++;
                }
            }
            return count;
        }
        return 0;
    }
    int mergeSort(vector<int>& arr, int i, int j){
        if(i<j){
            int mid=(i+j)/2;
            int l = mergeSort(arr,i,mid);
            int r = mergeSort(arr,mid+1,j);
            int c = countIt(arr,i,j,mid);
            merge(arr,i,j,mid);
            return l+r+c;
        }
        return 0;
    }
    int reversePairs(vector<int> &arr) {
        // code here
        int count=mergeSort(arr,0,arr.size()-1);
        return count;
    }
};