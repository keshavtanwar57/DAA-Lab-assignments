m = int(input('m: '))
l1 = set()
l2 = set()
for i in range(m):
    num = int(input())
    l1.add(num)
n = int(input('n: '))
for i in range(n):
    num = int(input())
    l2.add(num)

print(l1.intersection(l2))
