tc = int(input())
while tc:
    tc-=1

    l = input().split()
    for i in range(3): l[i] = int(l[i])

    l.sort()

    print(l[1])