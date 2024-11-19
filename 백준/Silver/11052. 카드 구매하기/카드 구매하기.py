import sys
input = sys.stdin.readline

n = int(input())
card = [0] + list(map(int, input().split()))
dy = [0] * (n+ 1)
for i in range(1, n + 1):
    for j in range(i, n + 1):
        dy[j] = max(dy[j], dy[j - i] + card[i])
print(dy[n])