import sys

t = int(input())
for i in range(t):
    n = int(input())
    l = input().split()
    for j in range(n):
        l[j] = int(l[j])

    flag = 0
    yes = 1
    for j in range(1,n):
        if l[j]>l[j-1]: flag = 1
        if (flag and l[j]<l[j-1]):
            print("NO")
            yes = 0
            break

    if yes: print("YES")
