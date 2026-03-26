t = int(input())

while (t):
    t -= 1

    n = int(input())
    l = input().split()

    odd = 0
    even = 0

    for i in l:
        if (int(i)%2 == 0): even+=1
        else: odd += 1

    print(min(even, odd))