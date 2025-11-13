n, m = map(int, input().split())
print("Yes")
for i in range(n):
    for j in range(m):
        print(i * m + j + 1, end=' ')
    print()