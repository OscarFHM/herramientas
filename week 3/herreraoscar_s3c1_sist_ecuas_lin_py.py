#Escriba un código de eliminación Gaussiana para resolver el sistema Ax=B.

import numpy as np
import time
ini1 = time.time()
N=1000
A=(np.random.random((N,N))*10.0)-5.0
B=(np.random.random((N,1))*10.0)-5.0
N_A=np.concatenate((A,B),axis=1)
t1 = time.time()

ini2 = time.time()
for i in range(N):
  N_A[i,:]=N_A[i,:]/N_A[i,i]
  for j in range(i+1,N):
      N_A[j,:]=N_A[j,:]-(N_A[i,:]*N_A[j,i])
t2 = time.time()

ini3 = time.time()
for i in range(N-1,0,-1):
  for j in range(i-1,-1,-1):
    N_A[j,-1]=N_A[j,-1]-N_A[j,i]*N_A[i,-1]
SOlUCION=N_A[:,-1]
t3 = time.time()

ini4 = time.time()
SOlUCION_NP=np.linalg.solve(A,B)
t4 = time.time()

# Error=SOlUCION.T-SOlUCION_NP
print(f"Tiempo 1 :{t1-ini1},Tiempo 1 gaus :{t2-ini2},Tiempo 2 gaus :{t3-ini3}, tiempo total gaus{t3+t2-ini3-ini2},Tiempo numpy :{t4-ini4},que tanto se deomora mas gaus que numpy {(t3+t2-ini3-ini2)/(t4-ini4)}")
# print(Error)
#compare sus resultados con el paquete de numpy: https://numpy.org/doc/stable/reference/generated/numpy.linalg.solve.html