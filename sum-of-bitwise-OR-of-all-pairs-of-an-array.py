#https://www.geeksforgeeks.org/calculate-sum-of-bitwise-and-of-all-pairs/
# Barclays round 1 Q2

def pairAndSum(arr, n) : 
	ans = 0
	ans2 = 0
	total = n*(n-1)//2
	for i in range(0,32) : 
		
		k = 0
		
		for j in range(0,n) :
		    if  not ( (arr[j] & (1 << i)) ):
		        k = k + 1

		ans = ans + (1 << i) * (k * (k - 1) // 2) 
		cnt = (k * (k - 1) // 2)
		
		if i<=n:
		    ans2 = ans2 + ((2**i) * (total-cnt))*2
	
	return ans2+sum(arr) 
	
arr = [1, 2, 3, 4, 5, 6] 
n = len(arr) 
print(pairAndSum(arr, n)) 

