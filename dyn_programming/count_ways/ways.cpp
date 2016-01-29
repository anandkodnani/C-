/*

Input:  n = 3
Output: 4
Below are the four ways
 1 step + 1 step + 1 step
 1 step + 2 step
 2 step + 1 step
 3 step


recursion:

int count_ways(int n) {

if (n < 0)
return 0;

if (n == 0)
return 0;

return count_ways(n - 1) + count_ways(n - 2)
+ count_ways(n -3);
}

dyn program:

int count_ways(int n) {

int dp[n + 1];
}
 */
