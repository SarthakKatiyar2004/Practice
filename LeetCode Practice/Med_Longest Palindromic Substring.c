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

char* longestPalindromeSubstring(char* s){
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

char* longestPalindromeSubstring(char* s){
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

/*Best Approach: Manacher's Algorithm
Time Complexity = O(N)*/
char* preprocess(const char* s){
	int n = strlen(s), j = 0;
	char* t = (char*)malloc((2*n+4)*sizeof(char));
	t[j] = '^';
	t[j++] = '#';
	for (int i = 0; i < n; i++){
		t[j++] = s[i];
		t[j++] = '#';
	}
	t[j++] = '#';
	t[j++] = '$';
	t[j++] = '\0';

	return t;
}

char* longestPalindromeSubstring(char* s){
	char* t = preprocess(s);
	int n = strlen(t);
	int *p = (int*)calloc(n, sizeof(int));
	int center = 0, right = 0;

	for (int i = 1; i < n-1; i++){
		int mirror = 2*center-i;
		if (i < right)  {p[i] = (right - i < p[mirror] ? right-i : p[mirror]);}
		while (t[i + 1 + p[i]] == t[i - 1 - p[i]]) p[i]++;
		if (i + p[i] > right) {center = i; right = i + p[i]; }
	}

	int maxLen = 0, centerIndex = 0;
	for (int i = 1; i < n-1; i++){ if (p[i] > maxLen) maxLen = p[i]; centerIndex = i; }
	int start = (centerIndex - maxLen)/2;

	char* res = (char*)malloc((maxLen+1)*sizeof(char));
	strncpy(res, s+start, maxLen);
	s[maxLen] = '\0';

	free(t);
	free(p);
	return s;
}
