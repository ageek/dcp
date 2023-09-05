# dcp-013
# This problem was asked by Amazon.
# Given an integer k and a string s, find the length of the longest substring that contains at most k
# distinct characters.
# For example, given s = "abcba" and k = 2, the longest substring with k distinct characters is "bcb".


# Brute force technique
# complexity = O(n2 * k)
# This takes O(n2 * k) time, since we use
# n2 to generate each possible substring, and then take k to check each character.
current_longest =''
def find_longest_substring(s, k):
    global current_longest
    for i in range(len(s)):
        for j in range(i+1, len(s)+1):
            substring=s[i:j]
            #print(substring)
            if len(set(substring))<=k and len(substring)>len(current_longest):
                current_longest=substring
    print(current_longest)
    return len(current_longest)   
    
s='abcba'
k=2
c=find_longest_substring(s,k)
print(f"longest subtring: {current_longest}")