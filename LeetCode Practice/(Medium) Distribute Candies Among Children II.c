//Given 'n' candies which have to be distributed entirely among 3 children
//The only constraint being that each of the 3 kids, can have at most 'k' candies.

//Initial approach - Using 3 loops.
//Time Complexity - O((limit+1)^3)
//Space Complexity - O(1)
long long distributeCandies(int n, int limit) {
  long long count = 0;
  int a, b, c;
  for (a = 0; a <= limit; a++){
    for (b = 0; b <= limit; b++){
      for (c = 0; c <= limit; c++){
        if (a+b+c == n)
          count++;
      }
    }
  }
  return count;
}

//Slightly Better approach - Using 2 loops.
//Time complexity - O((limit+1)^2)
//Space complexity - O(1)
long long distributeCandies(int n, int limit) {
  long long count = 0;
  int a, b;
  for (a = 0; a <= limit; a++){
    for (b = 0; b <= limit; b++){
      if (n-a-b <= limit && n-a-b >= 0)
        count++
    }
  }
  return count;
}

//Better approach - Mathematical manipulation
//Time complexity - O(limit+1)
//Space complexity - O(1)
long long distributeCandies(int n, int limit) {
  long long count = 0;
  for (int a = 0; a <= limit; a++){
    int s = n-a;
    int b_min = (0 > s-limit) ? 0 : s-limit;
    int b_max = (limit < s) ? limit : s;
    if (b_min <= b_max)
      count += (b_max - b_min + 1);
  }
  return 0;
}

//Most optimal approach - Stars and Bars theorem
//Time complexity - O(1)
//Space complexity - O(1)
/*
Consider * | * * | * * -> This is 5 stars being divided into 3 groups using 2 bars
Same logic can be applied to this question.
Since we need to distribute among 3 children we will require 3-1 = 2 bars (for general cases for distributing among c children, we will need c-1 bars.
| * * * * * | [0, 5, 0]
| * * * * | * [0, 4, 1]
| * * * | * * [0, 3, 2]
| * * | * * * [0, 2, 3]
| * | * * * * [0, 1, 4]
| | * * * * * [0, 0 ,5]

and so on...

We can see that this approach will return (n+2)C(2) no. of ways {(n+c-1)C(c-1) for general 'c' children.}
ways = (n+2)(n+1)/2 ... 1
However, these results also include cases where a > limit, or b > limit, or c > limit might exist

coming back to the original set of equations,
we had a + b + c = n
and a, b, c >= 0, which we found using the stars and bars theorem.

Deducting (limit+1) on both sides, we get
a + b + c - (limit+1) = n - (limit+1), which implies
(a-limit-1) + b + c = n - (limit+1)
a' + b + c = n'
where a', b, c >= 0, again using the stars and bars theorem

This scenario will have (n-limit-1+3-1)C(3-1) = (n-limit+1)C(2) for 3 children {or (n-limit+c-2)C(c-1) for general 'c' children.}

counts = (n-limit+1)!/((n-limit-1)!(2)!) = (n-limit+1)(n-limit)/2

This is the case where a >= limit+1
similarly cases where b >= limit+1 and c >= limit+1 will have the same number of counts

counts where a, or b, or c >= limit + 1 = (n-limit+1)(n-limit)/2 ... 2

now let's consider cases where 2 of the 3 children get more than the limit candies
for example let's say a >= limit+1 and b >= limit+1
(a-limit-1) + (b-limit-1) + c = n - 2*(limit+1)

there would be 3 such cases (a,b; b,c; c,a; violating the limit independently)
so this count will be (n-2*(limit+1)+2)C(2) ... 3

finally the case where both a, b, and c violate the limit will be
(a-limit-1) + (b-limit-1) + (c-limit-1) = n-3*(limit+1)
here no. of ways = (n-3*(limit+1)+2)C(2) ... 4

Lets say (n+2)(n+1)/2 = U
and cases where a, b, and c violate the limit are denoted by A, B, and C, respectively.

This would mean we aim to find |U - (A u B u C)|
|U| = (n+(c-1))C((c-1)) = (n+2)C(2) = (n+2)(n+1)/2
|A| = |B| = |C| = (n-limit-1+(c-1))C(c-1) = (n-limit+1)C(2) = (n-limit+1)(n-limit)/2
|AnB| = |BnC| = |CnA| = (n-2*(limit+1)+(c-1))C(c-1) = (n-2limit)C(2) = (n-2limit)(n-2limit-1)/2
|AnBnC| = (n-3(limit+1)+(c-1))C(c-1) = (n-3limit-1)C(2) = (n-3limit-1)(n-3limit-2)/2

|AuBuC| = |A| + |B| + |C| - |AnB| - |BnC| - |CnA| + |AnBnC|
*/
long long distributeCandies(int n, int limit) {
    long long total = (long long)(n + 2) * (n + 1) / 2;

    int x1 = n - (limit + 1) + 2;
    long long over1 = (x1 < 2) ? 0 : (long long)x1 * (x1 - 1) / 2;

    int x2 = n - 2 * (limit + 1) + 2;
    long long over2 = (x2 < 2) ? 0 : (long long)x2 * (x2 - 1) / 2;

    int x3 = n - 3 * (limit + 1) + 2;
    long long over3 = (x3 < 2) ? 0 : (long long)x3 * (x3 - 1) / 2;

    long long bad = 3 * over1 - 3 * over2 + over3;
    return total - bad;
}
