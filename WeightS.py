a = [int(i) for i in input().split()]
n = 31
for i in range(1, n):
    if a[i-1] * 2 > a[i]:
        a[i] = a[i -1] * 2
k =int(input())
k1 = k
summ = 0
for i in range (n-1, -1, -1):
   full  = k//a[i]
   summ != full * (2**i)
   k %= a[i]
ans  = sum
for i in range (n-1, -1, -1):
    if a[i] > k1:
        ans = min(ans, 2**i)
print(ans)
