def first_missing_positive(nums):
    if not nums:
        return 1
    for i, num in enumerate(nums):
        print(f"{i}")
        while i + 1 != nums[i] and 0 < nums[i] <= len(nums):
            v = nums[i]
            nums[i], nums[v - 1] = nums[v - 1], nums[i]
            nums[v - 1] = v
            for x in nums:
                print(f"{x }", end=" ")
            print("")
            if nums[i] == nums[v - 1]:
                print(i , v-1)
                break
    for i, num in enumerate(nums, 1):
        if num != i:
            return i
    return len(nums) + 1
            
#nums=[3,4,-1,1]
nums=[-10,-20,80,1,2,555,4]
x=first_missing_positive(nums)
print(x)