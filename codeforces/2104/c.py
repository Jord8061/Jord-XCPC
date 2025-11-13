t = int(input())
for _ in range(t):
    n = int(input())
    s = input()
    if s == "AB":
        print("Alice")
    elif s == "BA":
        print("Bob")
    else:
        if s[0] == 'A' and s[-1] == 'A':
            print("Alice")
        elif s[0] == 'B' and (s[-1] == 'B' or s[-2] == 'B'):
            print("Bob")
        else:
            if s[0] == 'A' and s[-1] == 'B':
                t = True
                for i in range(1, n - 1):
                    if s[i] == 'B':
                        print("Bob")
                        t = False
                        break
                if t:
                    print("Alice")
            elif s[0] == 'B' and s[-1] == 'A':
                t = True
                for i in range(1, n - 1):
                    if s[i] == 'A':
                        print("Alice")
                        t = False
                        break
                if t:
                    print("Bob")