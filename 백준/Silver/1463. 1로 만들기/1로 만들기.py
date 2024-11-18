import sys
input = sys.stdin.readline
n = int(input().rstrip())
dy = [i - 1 for i in range(10 ** 6 + 1)]
dy[2] = dy[3] = 1
for i in range(4, n + 1):
    if i % 2 == 0:
        dy[i] = min(dy[i], dy[i // 2] + 1)
    if i % 3 == 0:
        dy[i] = min(dy[i], dy[i // 3] + 1)
    dy[i] = min(dy[i], dy[i - 1] + 1)
print(dy[n])