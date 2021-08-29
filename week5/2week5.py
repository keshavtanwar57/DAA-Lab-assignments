t = int(input('Test Case: '))

for i in range(t):
    pair = False
    size = int(input('Array Size: '))
    l = []
    for j in range(size):
        num = int(input())
        l.append(num)
    key = int(input('key: '))
    for j in l:
        if key - j in l:
            pair = True
            print(j, " ", key-j)
            l.remove(key - j)
            l.remove(j)

    if not pair:
        print('No pair')
