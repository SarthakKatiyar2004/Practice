//Given a 32 bit integer [-2^31 to 2^31 - 1]
//We have to reverse it.
//Suppose given 104, we must return 401; 10 becomes 1; and so on.
//Also if the reversal makes the integer go out of bounds of 32-bits, we must return 0.

//Brute Force approach - This leads to overflow error.
//Time Complexity = O(log n base 10)
int reverse(int x){
  int res = 0;
  while (x){
    res = res*10 + x%10;
    x /= 10;
  }
  return res;
}

//Most Optimal approach - Handle overflow
int reverse(int x){
  int res = 0;
  while (x){
    int digit = x % 10;
    if (res > INT_MAX/10 || (res == INT_MAX/10 && digit > 7)) return 0;
    if (res < INT_MIN/10 || (res == INT_MIN/10 && digit < -8)) return 0;

    res = res*10 + digit;
    x /= 10;
  }
  return res;
}
