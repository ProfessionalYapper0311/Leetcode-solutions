class Solution:
    def minOperations(self, nums: List[int], x: int, k: int) -> int:
        n = len(nums)
        vals = sorted(set(nums))
        idx = {v: i + 1 for i, v in enumerate(vals)}
        m = len(vals)
        cnt = [0] * (m + 1)
        sm = [0] * (m + 1)

        def upd(i, c, v):
            while i <= m:
                cnt[i] += c
                sm[i] += v
                i += i & -i

        def prefix(i):
            c = s = 0
            while i > 0:
                c += cnt[i]
                s += sm[i]
                i -= i & -i
            return c, s

        LOG = m.bit_length()

        def kth(kk):  # compressed index of the kk-th smallest element
            pos = 0
            for b in range(LOG, -1, -1):
                np_ = pos + (1 << b)
                if np_ <= m and cnt[np_] < kk:
                    pos = np_
                    kk -= cnt[np_]
            return pos + 1

        # cost of making each window of size x equal
        W = n - x + 1
        cost = [0] * W
        total = 0
        for i in range(n):
            upd(idx[nums[i]], 1, nums[i])
            total += nums[i]
            if i >= x:
                upd(idx[nums[i - x]], -1, -nums[i - x])
                total -= nums[i - x]
            if i >= x - 1:
                p = kth((x + 1) // 2)
                med = vals[p - 1]
                c1, s1 = prefix(p)
                cost[i - x + 1] = med * c1 - s1 + (total - s1) - med * (x - c1)

        INF = float('inf')
        prev = [0] * (n + 1)          # j = 0: zero cost
        for j in range(1, k + 1):
            cur = [INF] * (n + 1)
            for i in range(x, n + 1):
                cur[i] = min(cur[i - 1], prev[i - x] + cost[i - x])
            prev = cur
        return prev[n]