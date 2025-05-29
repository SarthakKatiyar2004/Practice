//Given 'n' stairs which could be climbed up either stepping 1 or 2 at a time.
//We have to find ways to climb the stairs.

//Brute force - Recursion
//Tn = Tn-1 + Tn-2 {T1 = 1, T2 = 2}
//Time Complexity = O(2^n)
//Space complexity = O(n)
int climbStairs(int n){
  if (n <= 2) return n;
  else return (climbStairs(n-1)+climbStairs(n-2));
}

//Better approach - Memoization
//Time Complexity = O(n)
//Space Complexity = O(n)
int climbStairs(int n) {
    if (n <= 2) return n;
    int* dp = (int*)malloc((n + 1) * sizeof(int));
    dp[1] = 1;
    dp[2] = 2;
    for (int i = 3; i <= n; i++)
        dp[i] = dp[i - 1] + dp[i - 2];
    int result = dp[n];
    free(dp);
    return result;
}

//Most Optimal approach
//Time Complexity = O(n)
//Space Complexity = O(1)
int climbStairs(int n) {
    if (n <= 2) return n;
    int a = 1, b = 2;
    for (int i = 3; i <= n; i++) {
        int temp = a + b;
        a = b;
        b = temp;
    }
    return b;
}
