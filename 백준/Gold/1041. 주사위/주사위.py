import sys

input = sys.stdin.readline

n = int(input())
dice = list(map(int, input().split()))
res = 0
twoMin = threeMin = 500

for i in range(6):
    oneSum = dice[i]
    for j in range(6):
        if (j == 5 - i) or (j == i): continue
        twoSum = oneSum + dice[j]
        if twoSum < twoMin: twoMin = twoSum
        for k in range(6):
            if (k == 5 - i) or (k == 5 - j) or (k == i) or (k == j): continue
            threeSum = twoSum + dice[k]
            if threeSum < threeMin: threeMin = threeSum

if n == 1:
    res = sum(dice) - max(dice)
elif n == 2:
    res = (twoMin + threeMin) * 4
else:
    res = (threeMin * 4 +
           twoMin * 4 * (n - 1) + twoMin * 4 * (n - 2) +
           min(dice) * 4 * (n - 2) * (n - 1) + min(dice) * (n - 2) * (n - 2))
print(res)