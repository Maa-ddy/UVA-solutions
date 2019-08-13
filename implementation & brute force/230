gi = lambda : list(map(int,input().strip().split()))
l = input()
books = []
while l != "END":
	book = l.split("\"")
	books.append((book[2][4:],book[1]))
	l = input()
M = {}
cur = 0
books.sort()
for e in books:
	M[e[1]] = cur
	cur += 1
state = [0]*len(books)
l = input()
ret = []
while l != "END":
	cmd = l.split("\"")
	if cmd[0].strip() == "BORROW":
		state[M[cmd[1]]] = -1
	elif cmd[0].strip() == "RETURN":
		ret.append((books[M[cmd[1]]][0], cmd[1]))
	else:
		ret.sort()
		for book in ret:
			place = M[book[1]] - 1
			while place >= 0 and state[place] == -1:
				place -= 1
			if place < 0:
				print("Put \"" + book[1] + "\" first")
			else:
				print("Put \"" + book[1] + "\" after \"" + books[place][1] + "\"")
			state[M[book[1]]] = 0
		print("END")
		ret = []
	l = input()
