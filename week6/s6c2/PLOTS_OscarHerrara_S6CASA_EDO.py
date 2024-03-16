import numpy as np
import matplotlib.pylab as plt
 

DatosE2=np.genfromtxt("DatosE2.dat")
# datosRK=np.genfromtxt("datosRK.dat")
# ErrorE=np.genfromtxt("ErrorE.dat")
# ErrorRK=np.genfromtxt("ErrorRK.dat")

plt.figure(1)
plt.plot(DatosE2[:,0],DatosE2[:,1],'b',label='Metodo Euler')
# plt.plot(datosRK[:,0],datosRK[:,1],'--r',label='Metodo RungeKutta')
plt.legend()
plt.grid()
plt.savefig("solucion.jpg")
# plt.figure(2)
# plt.plot(ErrorE[:,0],ErrorE[:,1],'b',label='Error Euler')
# plt.plot(ErrorRK[:,0],ErrorRK[:,1],'--r',label='Error RungeKutta')
# plt.legend()
# plt.grid()
# plt.savefig("Error.jpg")