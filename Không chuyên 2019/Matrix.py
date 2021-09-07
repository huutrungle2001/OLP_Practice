import numpy as np

s = input().split()
K = int(s[0])
n = int(s[1])
I = int(s[2]) - 1
J = int(s[3]) - 1
S = int(s[4])

A = []
for i in range(n):
    s = input().split()
    for j in range(n):
        A.append(int(s[j]))

A = np.array(A).reshape((n, n))

for i in range(K-1):
    B = []
    for j in range(n):
        s = input().split()
        for k in range(n):
            B.append(int(s[k]))
    A = A.dot(np.array(B).reshape(n, n))

print(A[i][j] % S)
