#include <stdio.h>      /* printf, scanf, NULL */
#include <stdlib.h>     /* malloc, free, rand */
#include <string.h>
#include <math.h>
unsigned long long int C(int n, int m) { // Pascal's Triangle
    int i = 0;
    int j = 0;
    unsigned long long ret = 0;
    long**arr = (long **)calloc((n+1), sizeof(long long *));
    for(i=0; i<=n; i++) {
        arr[i] = (long *)calloc((i+1), sizeof(long long));
        if(!arr[i]) 
            return -1;
        arr[i][0] = arr[i][i] = 1;
        for(j=1; j<i; j++) 
            arr[i][j] = arr[i-1][j-1] + arr[i-1][j];
    }
	ret = arr[n][m];
	for(i=0; i<n; i++)
		free(arr[i]);
	free(arr); 
    return ret;
}

int solution(int N) {
	int ret = 0;
	int i = 0;
	unsigned long long sum = 0;
	int exp = 0;
	int len = N*log10(11) + 1;
	long *map = (long *)calloc(len, sizeof(long long));
	for(i=0, exp=N; i<=N; i++, exp=N-i) {
		sum = C(N, i);
		while(sum > 0) {
			map[exp++] += (sum % 10);
			sum /= 10;
		}
	}
	for(i=0; i<len; i++) {
		if(map[i] > 9) {
			map[i+1] += (map[i] / 10);
			map[i] = map[i] % 10;
		}
		if(map[i] == 1)
			ret++;
	}
	free(map);
	return ret;
}

void main() {
	int N = 67; // Max val
	printf("11(%d)=%d\n", N, solution(N));
}
