# -*- coding: utf-8 -*-
"""
Created on Wed Nov  4 19:18:58 2020

@author: babut
"""

def fib(n):
    if n<0:
        print("invalid")
    elif n==0:
        return 0
    elif n==1:
        return 1
    else:
        return fib(n-1)+fib(n-2)
    
n = 0;
print("finonacci of",n,"is",)
    
    
print(fib(0))  
    