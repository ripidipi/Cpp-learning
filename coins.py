min_coins = 10 ** 9
ans = []
def rec(left, cur):
    global min_coins
    global ans
    if left == 0:
        summ = 0
        cnt = 0
        for i in range(m):
            summ += cur[i] * a[i]
            cnt += cur[i]
        if summ == n:
            if cnt < min_coins:
                min_coins = cnt
                cur_coins = []
                for i in range(m):
                    for j in range(cur[i]):
                        cur_coins.append(a[i])
                ans = cur_coins
        return None
    for i in range(3):
        rec(left - 1, cur + [i])

n, m = [int(i) for i in input().split()]
a = [int(i) for i in input().split()]
max_sum = 0
for i in range(m):
    max_sum += a[i] * 2
if max_sum < n:
    print(-1)
    exit(0)
rec(m, [])
if min_coins == 10 ** 9:
    print(0)
    exit(0)
print(min_coins)
print(*ans)
