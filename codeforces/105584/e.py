n = int(input())
while n:
    a = [int(x) for x in input().split()]
    flag = 0
    for i in range(1, n):
        if a[:i] == a[n-i:]:
            flag = i
            break
    if flag == 0:
        print("No")
        n = int(input())
        continue
    print("Yes")
    lst = [[0]*n for _ in range(n)]
    for i in range(0, flag):
        lst[i][flag-i-1] = a[i]
        lst[i-flag][i] = a[i]
        lst[flag-i-1][-i-1] = a[i]
        lst[-i-1][i-flag] = a[i]
    for i in range(flag, n-flag):
        lst[0][n-i-1] = a[i]
        lst[-1][i] = a[i]
        lst[i][0] = a[i]
        lst[n-i-1][-1] = a[i]
    for i in range(n):
        for j in range(n):
            print(lst[i][j], end=" ")
        print()
    n = int(input())