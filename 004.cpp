#include <iostream>
#include <vector>

int firstMissing(std::vector<int> nums)
{
    for (int i = 0; i < nums.size(); i++)
    {
        std::cout << "for i=" << i << std::endl;
        // ignore 0,  negative, >len(array) numbers
        while ((nums[i] != i + 1) && (nums[i] > 0) && (nums[i] <= nums.size()))
        {
            // value
            auto v = nums[i];

            // swap  nums[i] and nums[v-1]
            auto t = nums[i];
            nums[i] = nums[v - 1];
            nums[v - 1] = t;

            // put v at its correct index
            nums[v - 1] = v;

            for (auto p : nums)
            {
                std::cout <<"   " << p << " ";
            }
            std::cout << std::endl;

            // element i is at its correct index i
            if (nums[i] == nums[v - 1])
                break;
        }
    }
    for (int j = 0; j < nums.size(); j++)
    {
        if (nums[j] != j + 1)
            // std::cout << j+1 << std::endl;
            return j+1;
    }
    // if all the elments are availalbe in correct order and nothing seems missing, then
    // answer is len+1;
    // std::cout << len+1 << std::endl;
    return nums.size() + 1;
}


int main()
{
    //int nums[len] = {3, 4, -1, 1};
    //std::vector<int> nums= {3,4,-1,1};
    std::vector<int> nums={-10,-20,80,1,2,555,4};
    for (auto p : nums)
        std::cout << p << ",";
    std::cout << std::endl;

    std::cout << "First missing=" << firstMissing(nums) << std::endl;
}
