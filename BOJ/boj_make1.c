#include <stdio.h>
#include <stdlib.h>

//Dynamic Programming
//recursion searching


int shortpath(int n){
	int *dp = (int *)malloc((n + 1) * sizeof(int));
	dp[1] = 0;
	
	for(int i = 2; i <= n; i++){
		dp[i] = dp[i - 1] + 1;
		if(i%2 == 0){
			if (dp[i] > dp[i / 2] + 1) { dp[i] = dp[i / 2] + 1; }
			
		}
		if(i%3 == 0){
			if (dp[i] > dp[i / 3] + 1) { dp[i] = dp[i / 3] + 1; }
		}
	}
	
	int result = dp[n];
	free(dp);	
	return result;
}

int main(void){
	int n, result;
	
	scanf("%d", &n);
	
	result = shortpath(n);
	
	printf("%d", result);
	
	return 0;
}
