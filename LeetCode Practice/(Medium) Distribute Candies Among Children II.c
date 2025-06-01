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
*/
long long distributeCandies(int n, int limit){
  long long count = 0;
}
