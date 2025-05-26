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
void expandAroundCenter(char* s, int l, int r, int* lout, int* rout){
	int n = strlen(s);
	while(l >= 0 && r <= n-1 && s[l] == s[r]) { l--; r++; }
	*lout = l+1;
	*rout = r-1;
}

char* longestPossiblePalindrome(char* s){
	int start = 0, end = 0, n = strlen(s);

	for (int i = 0; i < n; i++){
		int l1, l2, r1, r2;
		expandAroundCenter(s, i, i, l1, r1);
		expandAroundCenter(s, i, i+1, l2, r2);

		if (r1-l1 > end-start) { start = l1; end = r1;}
		if (r2-l2 > end-start) { start = l2; end = r2;}
	}
	n = end-start+1;
	char* res = (char*)malloc((n+1)*sizeof(char));
	strncpy(res, s+start, n);
	res[n+1] = '\0';

	return res;
}

/*Best Approach: Manacher's Algorithm*/
