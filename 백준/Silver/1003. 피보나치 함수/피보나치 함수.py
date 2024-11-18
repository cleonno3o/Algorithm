import sys
input = sys.stdin.readline

zero = [0 for _ in range(50)]
one = [0 for _ in range(50)]
zero[0] = 1
one[1] = 1
for i in range(2, 41):
    zero[i] = zero[i - 1] + zero[i - 2]
    one[i] = one[i - 1] + one[i - 2]

t = int(input().rstrip())
for _ in range(t):
    n = int(input().rstrip())
    print(zero[n], one[n])