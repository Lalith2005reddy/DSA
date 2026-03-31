from typing import List

def lower_bound(arr : List[int], target : int) -> int:
    low,high = 0,len(arr)

    while low < high:
        mid = low + (high-low)//2
        
        if arr[mid] < target:
            low = mid+1
        else:
            high = mid
    
    return low

def upper_bound(arr : List[int], target : int) -> int:
    low,high = 0,len(arr)

    while low < high:
        mid = low + (high-low)//2

        if arr[mid] <= target:
            low = mid+1
        else:
            high = mid
    
    return low


def main():
    arr = [1,2,3,4,4,4,4,5,6,7,8]
    print(lower_bound(arr,4))
    print(upper_bound(arr,4))


if __name__ == "__main__":
    main()