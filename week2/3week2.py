T = int(input('Test Case: '))
for i in range(T):
    n = int(input('Array size: '))
    m = dict()
    count = 0
    for j in range(n):
        num = int(input('enter value: '))
        if num not in m:
            m[num] = j
        else:
            pass
    key = int(input('key: '))
    for j in m:
        for k in m:
            if j - k == key and m[j] != m[k]:
                count += 1
    m.clear()
    print(count)
