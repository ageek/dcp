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
        
x=optimumCut(10)
print(x)

countDict = {}
for x in range(1,10+1):
    count = 1   #reset count 
    optimumCut(x)
    countDict[x]=count

print(countDict)

    
    