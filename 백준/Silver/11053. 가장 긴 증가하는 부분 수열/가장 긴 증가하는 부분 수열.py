import sys
input = sys.stdin.readline
n = int(input().rstrip())
num = list(map(int, input().rstrip().split()))
dy = [1] * n
for i in range(1, n):
    for j in range(i - 1, 0 - 1, -1):
        if num[j] < num[i] and dy[i] < dy[j] + 1:
            dy[i] = dy[j] + 1
print(max(dy))