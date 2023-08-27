# dcp-009
# This problem was asked by Airbnb.
# Given a list of integers, write a function that returns the largest sum of non-adjacent numbers.
# Numbers can be 0 or negative.
# For example, [2, 4, 6, 2, 5] should return 13, since we pick 2, 6, and 5. [5, 1, 1, 5] should
# return 10, since we pick 5 and 5.
# Follow-up: Can you do this in O(N) time and constant space?

#complexity=O(2^n)
result = {}

house = [5,1,1,5]
#house = [2, 4, 6, 2, 5]
#house = [26,-2, -15, 0, 80, -100, -20]

def rob_house(n):
    if n==0:
        return house[0]
    elif n==1:
        return max(house[0],house[1])
    
    if n not in result:
        result[n] = max(rob_house(n-2)+house[n], house[n-1])
    
    return result[n]


# using Memoization/DP 
# complexity = O(n)
cache = [0 for i in house]
def rob_house_DP():
    if len(house) <=2: 
        return max(0, max(house))
    
    #cache = [0 for i in house]
    cache[0] = max(0, house[0])
    cache[1] = max(cache[0], cache[1])
    
    for i in range(2, len(house)):
        num = house[i]
        cache[i] = max(cache[i-2]+num, cache[i-1])
    
    #return the last element, which contains the max sum till end
    return cache[len(house)-1]  # =cache[-1]


amount=rob_house_DP()
print(amount)

# for x in cache:
#     print(x)
        


amount=rob_house(len(house)-1)
print(amount)

# for x in enumerate(result):
#     print(x)
    