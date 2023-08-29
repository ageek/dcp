#In this problem, we’re given an array of integers, representing the amount of money in 
# each house that a robber can rob. The houses are lined up on a street. There is one 
# constraint though, that the robber cannot rob adjacent houses. For example, if the 
# houses are indexed from 0 to 4, the robber can rob houses 0,2,4, or houses 1,3.
#What is the maximum amount of money that the robber can rob from the houses?

#https://towardsdatascience.com/mastering-dynamic-programming-a627dbdf0229
#for storing results in Top-Dn approach ( Memoization)

result = {}
#house=[10, 60, 80, 20, 8]
house=[10, 20, 10, 20, 40]


def rob_house(n):
    if n==0:
        return house[0]
    elif n==1:
        return max(house[0], house[1])
    
    if n not in result: 
        result[n] = max(rob_house(n-2)+house[n], rob_house(n-1))
    return result[n]
    


x=rob_house(len(house)-1)
print(x)
