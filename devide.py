with open("devide.txt", "r") as f:
	distri = []
	i = 0
	for line in f.readlines():
		nums = line.rstrip().split()
		print(nums)
		d = {}
		for num in nums:
			num = abs(int(num))
			
			if num in d:
				d[num] += 1
			else:
				d[num] = 1
		distri.append(d)
	print(distri)
