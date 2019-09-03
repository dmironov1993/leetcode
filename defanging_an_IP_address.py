# https://leetcode.com/problems/defanging-an-ip-address/

'''
address = input()
print (address.replace('.','[.]'))
'''

address = input()
address = list(address)
ans = ''
for i in address:
    if i == '.':
        ans = ans + '[.]'
    else:
        ans = ans + i
print (ans)
