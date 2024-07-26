def count_buckets(buckets):
    if buckets[-1] > k:
        return -1

    i, j = 0, len(buckets) - 1
    result = 0
    while i < j:
        if buckets[i] + buckets[j] > k:
            j -= 1
        else:
            i += 1
            j -= 1
        result += 1
    if i == j:
        result += 1
    return result


n, k = map(int, input().split())
buckets = list(map(int, input().split()))
buckets.sort()
res = count_buckets(buckets)

if res == -1:
    print('Impossible')
else:
    print(res)



