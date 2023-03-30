import hashlib
import time

string="Aidan Martin"
print(string)

'''
encoded=string.encode()
result = hashlib.sha256(encoded)
print("String : ", end ="")
print(string)
print("Hash Value : ", end ="")
print(result)
print("Hexadecimal equivalent: ",result.hexdigest())
print("Digest Size : ", end ="")
print(result.digest_size)
print("Block Size : ", end ="")
print(result.block_size)
'''
i=0
j=(2**256)
seconds = time.time()
while(i<j):       #((time.time()-seconds)<10):
    encoded=string.encode()
    result = hashlib.sha256(encoded)
    print(result.hexdigest())
    string=result.hexdigest()
    i=i+1
print(i)
