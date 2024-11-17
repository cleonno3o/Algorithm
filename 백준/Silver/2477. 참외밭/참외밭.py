n = int(input())
info = []
# 1-동, 2-서, 3-남, 4-북
width = height = 0
wIdx = hIdx = 0
for i in range(6):
    d, l = map(int, input().split())
    if d == 1 or d == 2:
        if l > width:
            width = l
            wIdx = i
    else:
        if l > height:
            height = l
            hIdx = i
    info.append(l)
preW = wIdx - 1
posW = wIdx + 1
if preW < 0: preW = 5
if posW == 6: posW = 0
if info[preW] != height: info[preW] = 0
else: info[posW] = 0

preH = hIdx - 1
posH = hIdx + 1
if preH < 0: preH = 5
if posH == 6: posH = 0
if info[preH] != width: info[preH] = 0
else: info[posH] = 0

totalArea = width * height
info[wIdx] = info[hIdx] = 0
minus = 1
for l in info:
    if l != 0:
        minus *= l

print((totalArea - minus) * n)