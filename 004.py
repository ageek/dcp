#dcp004:
#Time complexity= O(n)
#Space complexity= O(n)        

def first_missing(nums):
    s = set(nums)
    print(s)
    i=1
    while i in s:
        i =i+1
    return i


nums=[3,4,-1,1]
#nums=[-10,-8,-6,-5,1,2,4,5]
#nums=[1,2,0]
missing=first_missing(nums)
print(f"Missing number: {missing}")