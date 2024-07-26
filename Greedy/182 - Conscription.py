import heapq


class MyHeap(object):
    def __init__(self, initial=None, key=lambda x: x):
        self.key = key
        self.index = 0
        if initial:
            self._data = [(key(item), i, item) for i, item in enumerate(initial)]
            self.index = len(self._data)
            heapq.heapify(self._data)
        else:
            self._data = []

    def push(self, item):
        heapq.heappush(self._data, (self.key(item), self.index, item))
        self.index += 1

    def pop(self):
        return heapq.heappop(self._data)[0]

    def __len__(self):
        return self.index


if __name__ == '__main__':
    n, g, h = map(int, input().split())

    grunts = MyHeap(key=lambda x: x[0] - x[1])
    headhunts = MyHeap(key=lambda x: x[1] - x[0])
    total_power = 0

    if g + h > n:
        print(-1)
    else:
        for i in range(n):
            g_power, h_power = map(int, input().split())
            if g_power > h_power:
                grunts.push((g_power, h_power))
                total_power += g_power
            else:
                headhunts.push((g_power, h_power))
                total_power += h_power

        if len(grunts) < g:
            added_grunts = g - len(grunts)
            for _ in range(added_grunts):
                total_power -= headhunts.pop()
        elif len(headhunts) < h:
            added_headhunts = h - len(headhunts)
            for _ in range(added_headhunts):
                total_power -= grunts.pop()

        print(total_power)
