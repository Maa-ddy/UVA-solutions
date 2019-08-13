#uva_11547
gi = lambda: list(map(int,input().split()))
for k in range(gi()[0]):
        print(str((gi()[0]*63+7492)*5-498)[-2])
