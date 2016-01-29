int minOperations(char arr[][M], int i, int j, int time) {
  if (i < 1 || i > N || j < 1 || j > M)
    return 0;

  
  if (time > K)
    return -1;

  int val = INT_MAX;
  val = min(val, minOperations(arr, i - 1, j, time + 1));
  val = min(val, minOperations(arr, i, j - 1, time + 1));
  val = min(val, minOperations(arr, i + 1, j, time + 1));
  val = min(val, minOperations(arr, i, j + 1, time + 1));
}
