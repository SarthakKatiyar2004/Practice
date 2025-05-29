//Given an array containing just 0s, 1s, and 2s.
//We have to sort it in ascending order

//Brute Force - Bubble Sort
//Time Complexity - O(N^2)
//Space Complexity - O(1)
void sortColors(int* nums, int numsSize) {
    for (int i = 0; i < numsSize-1; i++){
        for (int j = i+1; j < numsSize; j++){
            if (nums[i] > nums[j]){
                nums[i] = nums[i] + nums[j];
                nums[j] = nums[i] - nums[j];
                nums[i] = nums[i] - nums[j];
            }
        }
    }
}

//Better Approach - Counting Sort
//We count the number of 0s, 1s, and 2s then rewrite the array.
//Time Complexity - O(2n)
//Space Complexity - O(3)
void sortColors(int* nums, int numsSize) {
    int count[3] = {0, 0, 0};
    for (int i = 0; i < numsSize; i++){
        count[nums[i]]++;
    }

    int index = 0;
    for (int color = 0; color <= 2; color++) {
        for (int j = 0; j < count[color]; j++) {
            nums[index++] = color;
        }
    }
}

//Best Approach - 3 Pointer Approach
//We declare 3 pointers, low = 0, mid = 0, high = numsSize -1
//We iterate till mid > high, if mid = 0, we swap the entries at mid and low, & increment both mid and low
//if mid = 1, we increment mid
//if mid = 2, we swap the entries at mid and high, & increment mid, while decrementing high
void sortColors(int* nums, int numsSize) {
    int low = 0, mid = 0, high = numsSize - 1;

    while (mid <= high) {
        if (nums[mid] == 0) {
            int temp = nums[low];
            nums[low++] = nums[mid];
            nums[mid++] = temp;
        } else if (nums[mid] == 1) {
            mid++;
        } else {
            int temp = nums[mid];
            nums[mid] = nums[high];
            nums[high--] = temp;
        }
    }
}
