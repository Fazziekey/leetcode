j = 0;
do {
  swapped = false; ++j; 
  for (i = 0; i < n-j; ++i)
    if (A[i] > A[i+1]) {
      swap(A[i], A[i+1]);
      swapped = true;
    }
} while (swapped);
