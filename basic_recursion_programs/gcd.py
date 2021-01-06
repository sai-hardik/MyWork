def gcd(a,b):
    if(b==0):
        return a
    else:
        return gcd(b,a%b)
    
a=24
b=16

print(" the gcd of 24 and 16 is:")
print(gcd(24,16))
   
    

# -*- coding: utf-8 -*-
"""
Spyder Editor

This is a temporary script file.
"""

