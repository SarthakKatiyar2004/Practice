//Given an array of size 3 containing the length of sides of a given triangle
//We must find the type of triangle it is, if it is one.
//Most Optimal Approach = Brute Force
//Time Complexity = O(1)
//Space Complexity = O(1)

char* triangleType(int* nums, int numsSize) {
    int a = nums[0], b = nums[1], c = nums[2];
    if (a + b <= c || b + c <= a || c + a <= b)
        return "none";
    if (a == b && b == c)
        return "equilateral";
    if (a == b || b == c || c == a)
        return "isosceles";
    return "scalene";
}
