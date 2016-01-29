

double calcPhi(double tolerance, int n) {
  double val = pow(-1, n - 1) * (4 / n);
  if ( abs(val) < tolerance)
    return val;
  else
    val + calcPhi(tolerance, 2*n + 1);
}



void getCount(Node *head) {

  Node *temp = head;
  int max = -1;

  while (temp) {
    if (max < temp->data)
      max = temp->data;
    temp = temp->next;
  }

  int arr[max];

  temp = head;
  while (temp) {
    arr[temp->data]++;
    temp = temp->next;
  }

  int max_val = -1;
  for (int i = 0; i < max; ++i) {
    if (max_val < arr[i])
      max_val = i;
  }

  return max_val;
}
