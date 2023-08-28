# dcp-012
# This problem was asked by Amazon.
# There exists a staircase with N steps, and you can climb up either 1 or 2 steps at a time. Given N,
# write a function that returns the number of unique ways you can climb the staircase. The order of
# the steps matters.
# For example, if N is 4, then there are 5 unique ways:
# 1, 1, 1, 1
# 2, 1, 1
# 1, 2, 1
# 1, 1, 2
# 2, 2
# What if, instead of being able to climb 1 or 2 steps at a time, you could climb any number from a
# set of positive integers X? For example, if X = {1, 3, 5}, you could climb 1, 3, or 5 steps at a time.

# comlexity = O(2^n)
def solve12(n):
    if n < 0:
        return 0
    elif n ==0:
        return 1
    else:
        return solve12(n-1)+solve12(n-2)


n=4 # 5 ways
print(solve12(n))

# complexity = O(3^n)
def solve135(n):
    if n<0:
        return 0
    elif n==0:
        return 1
    else:
        return solve135(n-1)+solve135(n-3)+solve135(n-5)
    
n=6 #8 ways
print(solve135(n))


MAX=20
result = [0] * MAX 
#  Using Dynamic Programming (Memoization )
# complexity = O(n)
def solve135DP(n):
    if n<0:
        return 0
    elif n==0:
        return 1
    
    if(result[n]!=0):
        return result[n]
    
    result[n] = solve135DP(n-1) + solve135DP(n-3)+ solve135DP(n-5)
    
    return result[n]

n=6  # 8
print(solve135DP(n))
        
        
    