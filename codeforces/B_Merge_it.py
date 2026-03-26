t = int(input())
while t:
    t-=1
    input()
    l = input().split()

    freq = [0,0,0]
    for x in l:
        freq[int(x)%3]+=1

    out = freq[0]
    flag = min(freq[1], freq[2])
    out += flag + (freq[1]-flag)//3 + (freq[2]-flag)//3

    print(out)