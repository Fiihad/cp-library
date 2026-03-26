t = int(input())
while t:
    t -= 1

    n = int(input())
    l = input().split()
    for i in range(0,n): l[i] = int(l[i])

    l.sort()

    maxi = 0
    for i in range(1,n):
        if l[i]!=l[i-1]: maxi = max(maxi, (n-i)*i)

    if maxi==0: maxi = n//2
    print(maxi)