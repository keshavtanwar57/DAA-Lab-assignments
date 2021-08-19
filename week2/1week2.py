t = int(input('Test Case: '))
for i in range(t):
    n = int(input('Array size: '))
    m = dict()
    for j in range(n):
        num = int(input())
        if num not in m:
            m[num] = 1
        else:
            m[num] += 1
    key = int(input('Enter key: '))
    if key not in m:
        print('Key Not Present')
    else:
        print(key, " - ", m[key])
    m.clear()
