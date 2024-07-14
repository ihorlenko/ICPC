n, k = [int(i) for i in input().split()]
candidates = [0] * k
voters = [int(i) - 1 for i in input().split()]

for vote in voters:
    candidates[vote] += 1

statement = False
for candidate in candidates:
    if candidate > n // 2:
        statement = True

if statement:
    print('YES')
else:
    print('NO')
