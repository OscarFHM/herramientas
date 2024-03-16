import numpy as np
import matplotlib.pylab as plt
 

datosE=np.genfromtxt("datosE.dat")
datosRK=np.genfromtxt("datosRK.dat")
ErrorE=np.genfromtxt("ErrorE.dat")
ErrorRK=np.genfromtxt("ErrorRK.dat")

plt.figure(1)
plt.plot(datosE[:,0],datosE[:,1],'b',label='Metodo Euler')
plt.plot(datosRK[:,0],datosRK[:,1],'--r',label='Metodo RungeKutta')
plt.legend()
plt.grid()
plt.savefig("solucion.pdf")
plt.figure(2)
plt.plot(ErrorE[:,0],ErrorE[:,1],'b',label='Error Euler')
plt.plot(ErrorRK[:,0],ErrorRK[:,1],'--r',label='Error RungeKutta')
plt.legend()
plt.grid()
plt.savefig("Error.pdf")