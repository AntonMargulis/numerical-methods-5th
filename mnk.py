def draw1(a, b, x):
    return a*x +b

def draw2(a, b, c, x):
    return a * x * x + b * x + c

def draw3(a, b, c, d, x):
    return a * x * x * x + b * x * x + c * x + d


pp = 0.01
import sympy
import matplotlib.pyplot as plt
from numpy import arange
q = sympy.symbols('x')
x = [-3.0, -2.0, -1.0, 0.0, 1.0, 2.0]
y = [0.04978, 0.13534, 0.36788, 1.0, 2.7183, 7.3891]
k0 = len(x)
k1 = k2 = k3 = k4 = k5 = k6 = k7 = k8 = k9 = k10 = 0
for i in range(k0):
    k1 += x[i]
    k2 += pow(x[i], 2)
    k3 += pow(x[i], 3)
    k4 += pow(x[i], 4)
    k5 += pow(x[i], 5)
    k6 += pow(x[i], 6)
    k7 += y[i]
    k8 += x[i] * y[i]
    k9 += pow(x[i], 2) * y[i]
    k10 += pow(x[i], 3) * y[i]

a = (k0 * k8 - k1 * k7) / (k2 * k0 - k1 * k1);
b = (k7 - k1 * a) / k0;
pol1 = a * q + b
print(pol1)
yy1 = [ draw1(a, b, i) for i in arange(x[0], x[-1], pp)]

a = ((k2 * k9 - k8 * k3) * (k1 * k2 - k0 * k3) - (k9 * k1 - k7 * k3) * (k2 * k2 - k1 * k3)) / ((k4 * k2 - k3 * k3) * (k1 * k2 - k0 * k3) - (k1 * k4 - k2 * k3) * (k2 * k2 - k1 * k3))
c = (a * (k3 * k3 - k4 * k2) + k2 * k9 - k8 * k3) / (k2 * k2 - k1 * k3)
b = (k7 - k0 * c - k2 * a) / k1
pol2 = a * q * q + b * q + c
print(pol2)
yy2 = [ draw2(a, b, c, i) for i in arange(x[0], x[-1], pp)]

res1 = (k6 * k2 - k5 * k3) * (k2 * k0 - k1 * k1) - (k4 * k0 - k3 * k1) * (k4 * k2 - k3 * k3)
res2 = (k5 * k2 - k4 * k3) * (k2 * k0 - k1 * k1) - (k3 * k0 - k2 * k1) * (k4 * k2 - k3 * k3)
res3 = (k10 * k2 - k9 * k3) * (k2 * k0 - k1 * k1) - (k8 * k0 - k7 * k1) * (k4 * k2 - k3 * k3)
res4 = (k5 * k0 - k3 * k2) * (k4 * k1 - k2 * k3) - (k6 * k1 - k4 * k3) * (k3 * k0 - k1 * k2)
res5 = (k4 * k0 - k2 * k2) * (k4 * k1 - k2 * k3) - (k5 * k1 - k3 * k3) * (k3 * k0 - k1 * k2)
res6 = (k9 * k0 - k7 * k2) * (k4 * k1 - k2 * k3) - (k10 * k1 - k8 * k3) * (k3 * k0 - k1 * k2)
a = (res3 * res5 - res6 * res2) / (res1 * res5 - res2 * res4)
b = (res6 - a * res4) / res5
c = ((k9 * k0 - k7 * k2) - a * (k5 * k0 - k3 * k2) - b * (k4 * k0 - k2 * k2)) / (k3 * k0 - k1 * k2)
d = (k10 - k4 * c - k5 * b - k6 * a) / k3
pol3 = a * q * q * q + b * q * q + c * q + d
print(pol3)
yy3 = [ draw3(a, b, c, d, i) for i in arange(x[0], x[-1], pp)]


xx = [i for i in arange(x[0], x[-1], pp)]
plt.grid(True)
#plt.scatter(x, y)
legend = []
plt.plot(xx, yy1)
legend.append("Первая степень")
plt.plot(xx, yy2)
legend.append("Вторая степень")
plt.plot(xx, yy3)
legend.append("Третья степень")
plt.legend(legend)
plt.scatter(x, y)
sum1 = sum2 = sum3 = 0
for i in range(k0):
	sum1 += pow(y[i] - pol1.subs(q, x[i]), 2)
	sum2 += pow(y[i] - pol2.subs(q, x[i]), 2)
	sum3 += pow(y[i] - pol3.subs(q, x[i]), 2)
print(sum1, sum2, sum3)

err12=[]
err13=[]
err23=[]
for i in range(k0):
	err12.append(pol1.subs(q, x[i])-pol2.subs(q,x[i]))
	err13.append(pol1.subs(q, x[i])-pol3.subs(q,x[i]))
	err23.append(pol2.subs(q, x[i])-pol3.subs(q,x[i]))
print(err12)
print(err13)
print(err23)

plt.show()





