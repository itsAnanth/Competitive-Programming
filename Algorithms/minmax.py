import random


def minmax(arr, start, end):

    if end == start:
        return [arr[start], arr[end]]
    elif end == start + 1:
        x = arr[start]
        y = arr[end]
        return [x, y] if x <= y else [y, x] 
    else:
        mid = int((start + end) / 2)
        [mm1, mx1] = minmax(arr, start, mid)
        [mm2, mx2] = minmax(arr, mid + 1, end)
        
        return [mm1 if mm1 < mm2 else mm2, mx1 if mx1 > mx2 else mx2]


 
def main():
    length = 10
    arr = []
    for i in range(length):
        arr.append(random.randint(1, 20))

    print(arr)

    print(minmax(arr, 0, length - 1))

main()
