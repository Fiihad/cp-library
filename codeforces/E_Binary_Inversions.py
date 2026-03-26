t = int(input())
while t:
    t -= 1

    n = int(input())
    l = input().split()
    for i in range(n): l[i] = int(l[i])

    first0 = -1
    for i in range(n):
        if l[i]==0:
            first0 = i
            break

    last1 = -1
    for i in reversed(range(n)):
        if l[i]==1:
            last1 = i
            break

    sum = 0
    out = 0
    out2 = 0
    out3 = 0
    for i in reversed(l):
        if i==0: sum+=1
        else: out += sum

    if first0!=-1:
        l[first0] = 1
        sum = 0
        for i in reversed(l):
            if i==0: sum+=1
            else: out2 += sum
        l[first0] = 0

    if last1!=-1:
        l[last1] = 0
        sum = 0
        for i in reversed(l):
            if i==0: sum+=1
            else: out3 += sum

    print(max(out, out2, out3))
