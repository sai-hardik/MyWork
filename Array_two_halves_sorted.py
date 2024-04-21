# -*- coding: utf-8 -*-
"""
Created on Sat Apr 20 20:59:35 2024

@author: babut
"""

def merge(arr, left_start, mid, right_end):
    left_half = arr[left_start:mid+1]
    right_half = arr[mid+1:right_end+1]
    i = j = 0
    result_idx = left_start
    while i < len(left_half) and j < len(right_half):
        if left_half[i] <= right_half[j]:
            arr[result_idx] = left_half[i]
            i += 1
        else:
            arr[result_idx] = right_half[j]
            j += 1
        result_idx += 1
    while i < len(left_half):
        arr[result_idx] = left_half[i]
        i += 1
        result_idx += 1
    while j < len(right_half):
        arr[result_idx] = right_half[j]
        j += 1
        result_idx += 1
def merge_sort(arr, left, right):
    if left < right:
        mid = (left + right) // 2
        merge_sort(arr, left, mid)
        merge_sort(arr, mid+1, right)
        merge(arr, left, mid, right)
def merge_sort_custom(arr):
    merge_sort(arr, 0, len(arr)-1)
    return arr
arr = [1, 3, 5, 7, 2, 4, 6, 8]
sorted_arr = merge_sort_custom(arr)
print(sorted_arr)

