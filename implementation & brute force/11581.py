gi = lambda : list(map(int,list(input())))
def test(m):
	return sum([sum(e) for e in m]) > 0
def apply(m):
	ans = [[0,0,0],[0,0,0],[0,0,0]]
	ans[0][0] = m[0][1] + m[1][0]
	ans[0][1] = m[0][0] + m[1][1] + m[0][2]
	ans[0][2] = m[0][1] + m[1][2]
	ans[2][0] = m[2][1] + m[1][0]
	ans[2][1] = m[2][0] + m[1][1] + m[2][2]
	ans[2][2] = m[2][1] + m[1][2]
	ans[1][0] = m[0][0] + m[2][0] + m[1][1]
	ans[1][2] = m[0][2] + m[2][2] + m[1][1]
	ans[1][1] = m[0][1] + m[1][0] + m[2][1] + m[1][2]
	for k in range(3):
		for j in range(3):
			ans[k][j] %= 2
	return ans
for k in range(int(input())):
	input()
	m = [gi(),gi(),gi()]
	ans = -1
	while test(m):
		m = apply(m)
		ans += 1
	print(ans)
