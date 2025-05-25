/*Brute Force Approach
Time complexity = O(N^3) = O(N^2) for finding all possible sub-string and O(N) for verifying every string being palindrome or not.
*/
int isPalindrome(char* s, int start, int end){
	while (start < end){
		if (s[start] != s[end]) return false;
		start++;
		end--;
	}
	return true;
}

char* longestPossiblePalindrome(char* s){
	int maxLen = 0, startId = 0, n = strlen(s);
	for (int i = 0; i < n; i++){
		for (int j = 0; j < n; j++){
			if (isPalindrome(s, i, j) && (j - i + 1) > maxLen){maxLen = j-i+1; startId = i;}
		}
	}
	char* result = (char*)malloc((maxLen+1)*sizeof(char));
	strncpy(result, s+startId, maxLen);
	result[maxLen] = '\n';

	return result;
}

/*Better Approach: Expand Around Center
This approach is based on the fact that every palindrome is based around a character (odd length) or pair (even length)
Time complexity = O(N^2)*/


/*Best Approach: Manacher's Algorithm*/
