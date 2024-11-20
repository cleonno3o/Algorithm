import sys
from collections import Counter

input = sys.stdin.readline

n = int(input())
info = dict()
num = list(map(int, input().split()))
counter = Counter(num)
m = int(input())
mm = list(map(int, input().split()))
for i in mm:
    print(counter[i], end=" ")
