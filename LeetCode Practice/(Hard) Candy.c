//Given an array of 'n' children each having a rating
//We have to distribute candies among these 'n' children with the constraint that children with higher rating should have more candies than their neighbours

//Brute force - Keep traversing the array changing it everytime until no change is possible
//Time Complexity = O(n^2)
//Space Complexity = O(n)

int candy(int* ratings, int ratingsSize) {
    int* candies = (int*)malloc(sizeof(int) * ratingsSize);
    for (int i = 0; i < ratingsSize; i++) candies[i] = 1;

    int changed = 1;
    while (changed) {
        changed = 0;
        for (int i = 0; i < ratingsSize; i++) {
            if (i > 0 && ratings[i] > ratings[i - 1] && candies[i] <= candies[i - 1]) {
                candies[i] = candies[i - 1] + 1;
                changed = 1;
            }
            if (i < ratingsSize - 1 && ratings[i] > ratings[i + 1] && candies[i] <= candies[i + 1]) {
                candies[i] = candies[i + 1] + 1;
                changed = 1;
            }
        }
    }

    int total = 0;
    for (int i = 0; i < ratingsSize; i++) total += candies[i];
    free(candies);
    return total;
}

//Better approach - 2 key passes approach
//Time complexity = O(4n + c)
//Space complexity = O(n+1)

int candy(int* ratings, int ratingsSize) {
    int* candies = (int*)malloc(ratingsSize*sizeof(int));
    for (int i = 0; i < ratingsSize; i++) candies[i] = 1;

    //left to right
    for (int i = 1; i < ratingsSize; i++){
        if (ratings[i] > ratings[i-1])
            candies[i] = candies[i-1] + 1;
    }

    //right to left
    for (int i = ratingsSize-2; i >= 0; i--){
        if (ratings[i] > ratings[i+1] && candies[i] <= candies[i+1])
            candies[i] = candies[i+1] + 1;
    }

    int total = 0;
    for (int i = 0; i < ratingsSize; i++) total += candies[i];
    free(candies);
    return total;
}
