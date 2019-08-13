gi = lambda : list(map(int,input().strip().split()))
def eq(a,b):
	for k in range(len(a)):
		if a[k] == "*" and b[k] != "*":
			return False
	return True
n,m = gi()
while n or m:
	a = [input() for e in range(n)]
	b = [input() for e in range(m)]
	l = min([e.index("*") for e in b if "*" in e])
	r = m - 1 - min([e[::-1].index("*") for e in b if "*" in e])
	u = -1
	d = -1
	idx = 0
	for e in b:
		if "*" in e and u == -1:
			u = idx
		if "*" in e:
			d = idx
		idx += 1
	b = b[u:d+1]
	b = [e[l:r+1] for e in b]
	x,y = 0,0
	ans = -1
	while x + len(b) <= n:
		aa = a[x:x+len(b)]
		y = 0
		while y + len(b[0]) <= n:
			flag = True
			for k in range(len(b)):
				#print(aa[k][y:y+len(b[0])])
				if not eq(b[k], aa[k][y:y+len(b[0])]):
					flag = False
					break;
			if flag and ans < 1:
				ans += 1
				for k in range(n):
					for j in range(n):
						if x <= k < x + len(b) and y <= j < y + len(b[0]) and b[k-x][j-y] == "*":
							a[k] = a[k][:j] + "." + a[k][j+1:]
				x, y = -1, 0
				break;
			y += 1
		x += 1
	if ans < 1:
		print(0)
	else:
		print(1)
	n,m = gi()
