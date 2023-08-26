#  This problem was asked by Facebook.
#  Given the mapping a = 1, b = 2, ... z = 26, and an encoded message, count the number of ways
#  it can be decoded.
#  For example, the message '111' would give 3, since it could be decoded as 'aaa', 'ka', and 'ak'.
#  You can assume that the messages are decodable. For example, '001' is not allowed.


# Every branch calls inself twice for 2 branches
# complexity = O(2^n) 
def countEncodings(msg):
    if msg.startswith('0'): 
        return 0
    elif len(msg)<=1: #for "" blank string and strings with one number
        return 1
    
    total = 0
    total +=countEncodings(msg[1:])    
    #
    #if int("".join(str(x) for x in msg[:2])) <= 26: 
    if int(msg[:2]) <= 26:   
        total +=countEncodings(msg[2:])
   
    return total

# using DP (with tabulation)
# complexity = O(n)
def countEncodingsDP(s):
    n = len(s)
    if n == 0 or s[0] == '0':
        return 0

    dp = [0] * (n + 1)
    dp[0] = 1
    dp[1] = 1

    for i in range(2, n + 1):
        if s[i - 1] != '0':
            dp[i] += dp[i - 1]

        two_digit = int(s[i - 2:i])
        if 10 <= two_digit <= 26:
            dp[i] += dp[i - 2]

    return dp[n]



    
    

msg='123412'
count=countEncodings(msg)
print(f'Total encodings found = {count:}')

countDP=countEncodingsDP(msg)
print(f'Total encodings found = {countDP:}')