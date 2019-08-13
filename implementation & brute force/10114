#uva_10114
gi = lambda: list(map(float,input().split()))
l = gi()
while l[0]>=0:
        months = [0]*(int(l[0])+1)
        cur = 1
        ows = l[2]
        amount = l[2]/l[0]
        l[2] += l[1]
        m = gi()
        months[0] = m[1]
        for k in range(int(l[-1])-1):
                m = gi()
                while cur < m[0]:
                        months[cur] = months[cur-1]
                        cur += 1
                months[cur] = m[1]
                cur += 1
        while cur < l[0]:
                months[cur] = months[cur-1]
                cur += 1
        cur = 1
        l[2] -= l[2] * months[0]
        while l[2] < ows:
                ows -= amount
                l[2] -= l[2] * months[cur]
                cur += 1
                
        if (cur-1 == 1):
                print("1 month")
        else:
                print(str(cur-1)+" months")
        l = gi()
