import sys
from collections import deque

input = sys.stdin.readline
dr = [0, 0, 1, 0, -1, 0]
dc = [0, 0, 0, 1, 0, -1]
dh = [1, -1, 0, 0, 0, 0]
m, n, h = map(int, input().split())
box = [[[] * m for j in range(n)] for i in range(h)]
isChecked = [[[False] * m for _ in range(n)] for __ in range(h)]
tomato = deque()
waitTomato = 0
totalDay = 0


def inRange(nH, nR, nC):
    global m, n, h
    return (0 <= nH and nH < h and
            0 <= nR and nR < n and
            0 <= nC and nC < m)


for hh in range(h):
    for nn in range(n):
        box[hh][nn] = list(map(int, input().split()))
        waitTomato += box[hh][nn].count(0)
        for mm in range(m):
            if box[hh][nn][mm] == 1:
                isChecked[hh][nn][mm] = True
                tomato.append((hh, nn, mm))
while True:
    prevTomato = waitTomato
    for _ in range(len(tomato)):
        hh, nn, mm = tomato.popleft()
        for ii in range(6):
            nH = hh + dh[ii]
            nR = nn + dr[ii]
            nC = mm + dc[ii]
            if inRange(nH, nR, nC) and box[nH][nR][nC] == 0:
                box[nH][nR][nC] = 1
                tomato.append((nH, nR, nC))
                isChecked[nH][nR][nC] = True
                waitTomato -= 1
    if prevTomato == waitTomato:
        break
    else:
        totalDay += 1

if waitTomato != 0:
    print(-1)
else:
    print(totalDay)
