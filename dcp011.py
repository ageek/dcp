# dcp011
# autocomplete system
input=['deal', 'deer', 'dog', 'demand']

# Naive approach
# complexity = O(n) 
def prefixMatch(input, pre):
    res=set()
    for x in input: 
        if x.startswith(pre):
            res.add(x)
    return res
        

pre='de'
op = prefixMatch(input, pre)

for x in op:
    print(x)


