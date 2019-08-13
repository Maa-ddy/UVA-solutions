#uva_11498
gi = lambda : list(map(int,input().split()))
q, = gi()
while q:
    div = gi()
    for k in range(q):
        point = gi()
        if point[0] == div[0] or point[1] == div[1]:
            print("divisa")
        elif point[0] > div[0]:
            if point[1] > div[1]:
                print("NE")
            else:
                print("SE")
        else:
            if point[1] > div[1]:
                print("NO")
            else:
                print("SO")
    q, = gi()
