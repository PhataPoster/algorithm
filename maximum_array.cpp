#include <iostream>

using namespace std;

struct RetVal
{
    int leftIndex;
    int rightIndex;
    int maxValue;
};

RetVal constructStructure(int li, int ri, int mx) {
    RetVal retVal;
    retVal.leftIndex = li;
    retVal.rightIndex = ri;
    retVal.maxValue = mx;
    return retVal;
}

RetVal findMergingSubarray(int arr[], int low, int mid, int high) {
    RetVal retVal;

    int leftSum = -1000000;
    int rightSum = -1000000;

    int leftIndex;
    int rightIndex;

    int sum = 0;

    for(int i = mid; i >= low; i--) {
        sum += arr[i];
        if(leftSum  < sum) {
            leftSum = sum;
            leftIndex = i;
        }
    }

    sum = 0;

    for (int i = mid+1; i<=high; i++) {
        sum += arr[i];
        if(rightSum < sum) {
            rightSum = sum;
            rightIndex = i;
        }
    }

    return constructStructure(leftIndex, rightIndex, leftSum + rightSum);
}

RetVal findMaxSubarray(int arr[], int low, int high) {
    RetVal retVal;
    int mid = (low + high)/2;

    if(low == high) {
        // arr[low] / arr[high]
        return constructStructure(low, high, arr[high]);
    }

    RetVal leftSubArray = findMaxSubarray(arr, low, mid);
    RetVal rightSubarray = findMaxSubarray(arr, mid+1, high);
    RetVal mergingSubarray = findMergingSubarray(arr, low, mid, high);
    
    if(leftSubArray.maxValue >= rightSubarray.maxValue && 
        leftSubArray.maxValue >= mergingSubarray.maxValue) return leftSubArray;

    if(rightSubarray.maxValue >= leftSubArray.maxValue &&
        rightSubarray.maxValue >= mergingSubarray.maxValue) return rightSubarray;

    return mergingSubarray;
    
}

int main() {
    int arr[] = {-2, -5, 6, -2, -3, 1, 5, -6};
    RetVal retVal = findMaxSubarray(arr, 0, 7);

    cout << retVal.leftIndex << " " << retVal.rightIndex << " " << retVal.maxValue << endl;
    return 0;
}