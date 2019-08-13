gi = lambda : list(map(int,input().strip().split()))
s = input()
c = 1
while s != "end":
	stacks = []
	for e in s:
		d = [ord(e)-ord(j[-1]) for j in stacks if ord(e)-ord(j[-1]) <= 0]
		if d == []:
			stacks.append([e])
		else:
			m = max(d)
			for j in stacks:
				if ord(e) - ord(j[-1]) == m:
					j.append(e)
					break;
	print("Case "+str(c)+":",len(stacks))
	c += 1
	s = input()
