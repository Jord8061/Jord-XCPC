import sys
input = sys.stdin.readline
t = int(input())
for _ in range(t):
    n = int(input())
    if bin(n)[2:].count("1")%2==0:
        s = bin(n)[2:].rstrip("0")
        if s == s[::-1]:
            print("YES")
        else:
            print("NO")
    else:
        print("NO")