t = int(input())

while(t):
    t = t-1
    n,x = map(int,input().split())

    arr = [] * n

    for i in range(0,n):
        arr.append(int(input()))
    
    maxi = arr[0]
    last_maxi = 2 * (x - arr[n-1])

    for i in range(1,n):
        maxi = max(maxi,arr[i] - arr[i-1])
    
    print(max(maxi,last_maxi))


