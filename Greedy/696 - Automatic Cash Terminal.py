from math import gcd

t = int(input())

while t != 0:
    t -= 1

    a, b, s = map(int, input().split())
    a_cnt = 0
    b_cnt = 0

    if s == 0:
        print(0, 0)
        continue

    if s % gcd(a, b) != 0:
        print('Impossible')
        continue

    swapped = False
    if a < b:
        a, b = b, a
        swapped = True

    a_cnt = s // a
    s %= a

    k = 0
    while True:
        if (s + a * k) % b == 0:
            a_cnt -= k
            b_cnt = (s + a * k) // b
            break
        k += 1

    if a_cnt < 0 or b_cnt < 0:
        print('Impossible')
        continue

    if swapped:
        print(b_cnt, a_cnt)
    else:
        print(a_cnt, b_cnt)
