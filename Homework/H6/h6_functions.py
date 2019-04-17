twoMaxElems(A):
  arr = []
  maxElem = findMax(A, arr)
  secondMaxElem = max(arr)
  return (maxElem, secondMaxElem)

findMax(A, arr):
  if |A| = 1 then
    return A0
  if |A| = 2 then
    return max(A0, A1)

  n = len(A)
  L = findMax(A[0..n/2], arr)
  R = findMax(A[n/2+1..n], arr)
  if (L > R) then 
    add R to arr
    return L
  else 
    add L to arr
    return R

CoinChange(coins, C)
  n = size of coins
  dp[1..C] where each dp[i] = inf
  for j = 1 to n
    for i = 1 to n
      if i >= coins[j] and dp[i - coins[j]] + 1 < dp[i]
        dp[i] = 1 + dp[1 - coins[j]]
  return dp[size of dp - 1]


Sort-And-Count(L):
  if |L| = 1 then no inversions
  else
    n = len(L)
    (rA, A) = Sort-And-Count(L[0..n/2])
    (rB, B) = Sort-And-Count(L[n/2+1..n])
    (rL, L) = Merge-And-Count(A, B)
  return (r = rA + rB + rC, L)

Merge-And-Count(A, B):
  Maintain curr ptrs i and j into each list, init to front elems
  Maintain cnt of significant inversions
  while both lists are not empty:
      if A[i] > 2 * B[j] then
        incr. cnt by num elems remaining in A
        j++
      else 
        i++

  C = []
  reset i and j to start of the two lists
  while both lists are not empty:
    if A[i] > B[j] then
      append B[j] to C
      j++
    else
      append A[i] to C
      i++
  once one list is empty, append the remainder of the other list to C
  return (cnt, C)