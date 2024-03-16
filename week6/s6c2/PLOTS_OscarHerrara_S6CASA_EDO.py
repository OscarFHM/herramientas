import numpy as np
import matplotlib.pylab as plt
 

DatosE2=np.genfromtxt("DatosE2.dat")
DatosRK=np.genfromtxt("DatosRK2.dat")
ErrorE=np.genfromtxt("ErrorE2.dat")
ErrorRK=np.genfromtxt("ErrorRK2.dat")
DatLFRE=np.genfromtxt("DatLFE.dat")
DatLFRK=np.genfromtxt("DatLFRK.dat")

plt.figure()
plt.plot(DatosE2[:,0],DatosE2[:,1],'b',label='Metodo Euler')
plt.plot(DatosRK[:,0],DatosRK[:,1],'--r',label='Metodo RungeKutta')
plt.plot(DatLFRE[:,0],DatLFRE[:,1],'.-g',label='LeapFrog Euler')
plt.plot(DatLFRK[:,0],DatLFRK[:,1],'.-m',label='LeapFrog RungeKutta')
plt.legend()
plt.grid()
plt.savefig("solucionEdo2.pdf")
plt.figure(2)
plt.plot(ErrorE[:,0],ErrorE[:,1],'b',label='Error Euler')
plt.plot(ErrorRK[:,0],ErrorRK[:,1],'--r',label='Error RungeKutta')
plt.legend()
plt.grid()
plt.savefig("ErrorEdo2.pdf")