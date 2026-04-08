t = int(input())

for _ in range(t):
    n,k = map(int,input().split())
    arr = list(map(int,input().split()))

    if k >= 2:
        print("YES")
    else:
        is_Sorted = all(arr[i-1] <= arr[i] for i in range(1,n))
        print("YES" if is_Sorted else "NO")