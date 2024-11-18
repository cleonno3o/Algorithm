import sys
input = sys.stdin.readline

n = int(input().rstrip())
sugar = [-1 for _ in range(n + 1)]
for i in range(3, n + 1):
    if i % 3 == 0:
        sugar[i] = i // 3

for i in range(5, n + 1):
    if i % 5 == 0:
        sugar[i] = i // 5
    else:
        if sugar[i - 5] != -1:
            sugar[i] = sugar[i - 5] + 1
print(sugar[n])