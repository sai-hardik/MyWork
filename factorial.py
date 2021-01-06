# -*- coding: utf-8 -*-
"""
Created on Wed Nov  4 18:59:46 2020

@author: hardik
"""
def fact(n):
    return 1 if (n==1 or n==0) else n * fact(n - 1);

n = 0;
print("factorial of",n,"is",
fact(n))
