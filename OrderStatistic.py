def quicksort(arr):
    if len(arr) <= 1:
        return arr
    pivot = arr[len(arr) // 2]
    left = [x for x in arr if x < pivot]
    middle = [x for x in arr if x == pivot]
    right = [x for x in arr if x > pivot]
    return quicksort(left) + middle + quicksort(right)

def ith_order_statistic(arr, i):
    sorted_arr = quicksort(arr)
    return sorted_arr[i - 1]

arr = [23, 14, 16, 7, 19, 3, 5, 11, 9, 32]
print("Original array:", arr)
    
i = int(input("Enter the order statistic i (1-indexed): "))
if i < 1 or i > len(arr):
    print(f"Invalid input. Please enter a value between 1 and {len(arr)}.")
else:
    result = ith_order_statistic(arr, i)
    print(f"The {i}th order statistic (i-th smallest element) is: {result}")
