//Given an int x, we have to find its square root.

//Brute force approach
//Time Complexity - O(root(n))
//Space complexity - O(1)

int sqrt(int x){
  int i;
  for (i = 0; i*i <= x; i++);
  return i-1;
}

//Better approach - Using Linear search algorithm
//Time Complexity - O(log(n))
//Space complexity - O(1)
int sqrt(int x) {
    if (x < 2) return x;
    int left = 1, right = x / 2, mid, ans = 0;
    while (left <= right) {
        mid = left + (right - left) / 2;
        if (mid <= x / mid) {
            ans = mid;
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    return ans;
}

//Most optimal approach - Newton's method
//Time Complexity - O(log(log(n)))
//Space Complexity - O(1)
int sqrt(int x){
  if (x == 0) return 0;
  long r = x;
  while (r*r > x){
    r = (r+x/r)/2;
  }
  return r;
}
