t = int(input())
while t:
    t -= 1
    input()

    s = input()
    maxi = 'a'
    for i in s:
        maxi = max(maxi, i)

    print(ord(maxi) - ord('a') + 1)