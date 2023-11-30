print(f"PI approximation --> PI/4 = 1/1 - 1/3 + 1/5 - 1/7 + 1/9 - ...")

def pi_approx(niter):
	RANGE = (niter * 2) + 1
	sum = 0
	cnt = 0

	for i in range(1, RANGE, 2):
		if cnt == 0:
			sum = 1/i
			# print(f"1/{i} - ", end="")

		elif  cnt % 2 == 0:
			# print(f"1/{i} - ", end="")
			sum = sum + 1/i
		else:
			# print(f"1/{i} + ", end="")
			sum = sum - 1/i
		cnt += 1
		# print(f"{cnt:<3} - {sum}")

	print(f"PI approx after {(RANGE - 1)/2} iterations: {sum * 4}")


for N in range (0, 100000001, 5000000):
	pi_approx(N)

'''
$> time python3 infinite_sum.py
PI approximation --> PI/4 = 1/1 - 1/3 + 1/5 - 1/7 + 1/9 - ...
PI approx after 0.0 iterations: 0
PI approx after 5000000.0 iterations: 3.1415924535897797
...
PI approx after 100000000.0 iterations: 3.141592643589326

real    4m55.488s
user    4m34.968s
sys     0m0.421s
'''
