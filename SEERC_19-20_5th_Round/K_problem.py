def solution():
    n, m, k = list(map(int, input().split()))
    a, b, c = list(map(int, input().split()))

    min_cost = min(a * n * m,
                   b * n,
                   c * (n // k) + min(a * (n % k) * m, b * (n % k)))

    print(min_cost)


if __name__ == '__main__':
    solution()
