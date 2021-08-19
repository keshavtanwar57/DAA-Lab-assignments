T = int(input('Test Case: '))
for i in range(T):
    n = int(input('Array size: '))
    m = dict()
    found = False
    for j in range(n):
        num = int(input('enter value: '))
        if num not in m:
            m[num] = j
        else:
            pass
    for j in m:
        if found:
            break
        for k in m:
            if j + k in m and m[j] != m[k]:
                print(m[j+k], " ", m[j], " ", m[k])
                found = True
                break
    if not found:
        print('No sequence found')

    m.clear()
