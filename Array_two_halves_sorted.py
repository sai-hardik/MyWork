# -*- coding: utf-8 -*-
"""
Created on Sat Apr 20 20:59:35 2024

@author: babut
"""

def sort_array(array):
    
    mid = len(array) // 2
    first = array[:mid]
    second = array[mid:]
    sorted_array = sorted(first + second)
    return sorted_array

array = [1, 3, 5, 7, 9, 2, 4, 6, 8, 10]
result = sort_array(array)
print(result)
