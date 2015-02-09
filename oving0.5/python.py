def isFibonacciNumber(n):
	a = 0
	b = 1
	while b < n:
		a, b = b, a + b
	if b == n:
		return True
	else:
		return False

print isFibonacciNumber(5)
print isFibonacciNumber(7)