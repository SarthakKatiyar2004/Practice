/*Given two numbers n and m. We have to find the difference between num1 and num2
Such that num1 = sum of all numbers between 1 and n (ends inclusive) that are non-divisible by m
and num2 = sum of all numbers between 1 and n that are divisible by m*/

//Brute Force approach
//Time Complexity = O(n)
int differenceOfSums(int n, int m){
  int sum = 0;
  for (int i = 1; i <= n; i++)
    if (i % m) //non-divisible element
      sum += i;
  return (2*sum - n*(n+1)/2);
}

//Most Optimal approach - Using mathematical simplifications
//Time Complexity = O(1)
//Sum of divisible, sod = m + 2m + 3m + ... + km = m*k*(k+1)/2
//Here k = floor(n/m); this implies, sond - sod = son - 2sod
int differenceOfSums(int n, int m){
  int k = n/m;
  return (n*(n+1)/2 - m*k*(k+1));
}
