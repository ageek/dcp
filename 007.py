#  This problem was asked by Facebook.
#  Given the mapping a = 1, b = 2, ... z = 26, and an encoded message, count the number of ways
#  it can be decoded.
#  For example, the message '111' would give 3, since it could be decoded as 'aaa', 'ka', and 'ak'.
#  You can assume that the messages are decodable. For example, '001' is not allowed.


def countEncodings(msg):
    if msg.startswith('0'): 
        return 0
    #for "" blank string and strings with one number
    elif len(msg)<=1:
        return 1
    
    total = 0
    total +=countEncodings(msg[1:])    
    #
    #if int("".join(str(x) for x in msg[:2])) <= 26: 
    if int(msg[:2]) <= 26:   
        total +=countEncodings(msg[2:])
   
    return total

msg='1234'
count=countEncodings(msg)
print(f'Total encodings found = {count:}')