#Rod cutting problem

length = [1, 2, 3, 4,   5,  6,  7,  8,  9,  10]
price =  [1, 5, 8, 9,   10, 17, 17, 20, 24, 30]

#complexity = O(2^n)
#find cuts (or uncut) that maximizes price for the given rod length n
# fun call count
count=1
def optimumCut(n):
    global count
    count += 1
    # if length is 1, return corresponding price
    if n==0:
        return 0
    # else check all possible combinations
    optimumRevenue = -999
    for i in range(1,n+1):
        optimumRevenue = max(optimumRevenue, price[i-1]+optimumCut(n-i))
    
    return optimumRevenue
 
print("For non DP optimalCuts - recursive=====================")        
# x=optimumCut(6)
# print(x)

# check function call stats = 1+2^n
countDict = {}
for x in range(1,10+1):
    count = 1   #reset count 
    optimumCut(x)
    countDict[x]=count

print(countDict)

print("For DP optimimalCuts - Memoization======================")
optCuts = [-99] * len(length)
#print(optCuts)
#complexity = O(n^2)
# In rod cutting, we have n subproblems
# overall, and at most n choices to examine for each, yielding an O(n2)  running time.

def optimalCutDP(n):
    global count
    count += 1
    if n==0:
        return 0
    if optCuts[n-1] > 0:
        return optCuts[n-1]
    else:
        #optimalRevenue = -99
        for i in range(1,n+1):
            #optimalRevenue =  max(optimalRevenue, price[i-1]+optimalCutDP(n-i))
            optCuts[n-1] =  max(optCuts[n-1], price[i-1]+optimalCutDP(n-i))
        
        #optCuts[n-1] = optimalRevenue
        
        #return optimalRevenue
        return optCuts[n-1]
            

# x=optimalCutDP(6)
# print(f'optimalCutDP={x}')
# print(optCuts)
    
# check function call stats = 2+n = O(n)
countDict = {}
for x in range(1,10+1):
    count = 1   #reset count 
    optimalCutDP(x)
    countDict[x]=count

print(countDict)

for x in optCuts:
    print(x, end=", ")