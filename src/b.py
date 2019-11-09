#!/Library/Frameworks/Python.framework/Versions/3.7/bin/python3
from sympy import divisors, divisor_count

t=int(input())
MOD=int(1E9+7)
for i in range(t):
	n=int(input())
	if(not n):
		print(0)
		continue
	divis = int(divisor_count(n))
#	print("n {} divis_tam {}".format(n, divis))
	f=int(n**0.5) if divis&1 else 1
	r=(int(n**(divis>>1)*f))%MOD
	print(r)
