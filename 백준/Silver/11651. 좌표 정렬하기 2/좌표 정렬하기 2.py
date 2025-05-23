import sys
input = sys.stdin.readline
n = int(input())
arr = []
for _ in range(n):
    arr.append(input())
def compare(point:str):
    x, y = point.split()
    return int(y) + int(x)/1000000

arr.sort(key=lambda x:compare(x))
print("".join(arr))