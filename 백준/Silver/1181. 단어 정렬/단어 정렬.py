import sys
input = sys.stdin.readline
n = int(input())
arr = []
for _ in range(n):
    tmp = input()
    if arr.count(tmp) == 0:
        arr.append(tmp)
arr.sort(key=lambda x: (len(x), x))
print("".join(arr))