#uva_11727
gi = lambda: list(map(int,input().split()))
for k in range(gi()[0]):
        print("Case "+str(k+1)+": "+str(sorted(gi())[1]))
