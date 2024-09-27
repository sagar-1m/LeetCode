class Solution {
public:
    // Merge two sorted subarrays into one sorted array
    void merge(vector<int>& nums, int left, int mid, int right) {
        int n1 = mid - left + 1;   // Size of the left subarray
        int n2 = right - mid;      // Size of the right subarray

        // Create temporary arrays to hold the subarrays
        vector<int> leftArray(n1), rightArray(n2);

        // Copy data to temp arrays leftArray[] and rightArray[]
        for (int i = 0; i < n1; i++)
            leftArray[i] = nums[left + i];
        for (int j = 0; j < n2; j++)
            rightArray[j] = nums[mid + 1 + j];

        // Merge the temp arrays back into nums[left..right]
        int i = 0, j = 0, k = left;

        // Merge the two sorted subarrays
        while (i < n1 && j < n2) {
            if (leftArray[i] <= rightArray[j]) {
                nums[k] = leftArray[i];
                i++;
            } else {
                nums[k] = rightArray[j];
                j++;
            }
            k++;
        }

        // Copy the remaining elements of leftArray[], if any
        while (i < n1) {
            nums[k] = leftArray[i];
            i++;
            k++;
        }

        // Copy the remaining elements of rightArray[], if any
        while (j < n2) {
            nums[k] = rightArray[j];
            j++;
            k++;
        }
    }

    // Merge sort function
    void mergeSort(vector<int>& nums, int left, int right) {
        if (left < right) {
            int mid = left + (right - left) / 2; // Find the midpoint

            // Recursively sort the first and second halves
            mergeSort(nums, left, mid);
            mergeSort(nums, mid + 1, right);

            // Merge the sorted halves
            merge(nums, left, mid, right);
        }
    }

    vector<int> sortArray(vector<int>& nums) {
        mergeSort(nums, 0, nums.size() - 1);  // Sort the entire array
        return nums;
    }
};
