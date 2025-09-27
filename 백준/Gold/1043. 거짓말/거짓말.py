import sys
from collections import deque

input = sys.stdin.readline

n, m = map(int, input().rstrip().split())
answerList = list(map(int, input().rstrip().split()))[1:]
knowList = [False] * (n + 1)
for person in answerList:
    knowList[person] = True

maxParty = 0
partyList = []
graph = [[] for _ in range(n + 1)]
q = deque()

for i in range(m):
    party = list(map(int, input().rstrip().split()))[1:]
    partyList.append(party)
    for s in party:
        for e in party:
            if s != e:
                graph[s].append(e)

for i in range(1, n + 1):
    if knowList[i]:
        q.append(i)

while len(q) != 0:
    s = q.popleft()
    for e in graph[s]:
        if not knowList[e]:
            knowList[e] = True
            q.append(e)

for party in partyList:
    isKnow = False
    for p in party:
        if knowList[p]:
            isKnow = True
            break
    if not isKnow:
        maxParty += 1

print(maxParty)
