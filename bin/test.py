import bayesopt as kp
import numpy as np

def testfunc(Xin):
    total = 10.0
    print Xin
    for value in Xin:
        total = total + (value -0.53)*(value-0.53)

    print total
    return total

params = {"theta": 0.21, "p": 1.6, "alpha": 1.0, "beta": 0.1, "delta": 10.0, "noise": 0.001}

n = 6
lb = np.zeros((n,))
ub = np.ones((n,))
x = np.zeros((n,))

out = testfunc(x)
print out

mvalue, x_out, error = kp.optimize(testfunc, n, lb, ub, x, 100, params, 1, 0)
print x_out