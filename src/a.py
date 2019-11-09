from sympy import divisors, divisor_count

N = 100
#final=0xffffffffffffffff
final=800573297242118400
inicio=int(final)-100
MOD=int(1E9+7)
for i in range(N):
	n=i+inicio
	divis = int(divisor_count(0xffffffffffffffff))
	print(n)
#	print("n {} divis_tam {}".format(n, divis))
	r=(n**(divis>>1))%MOD
#	print(r)
