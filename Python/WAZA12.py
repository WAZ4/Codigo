a = [1, 4, 9, 16, 25, 36]

b = []

for x in range(6, 0, -1):
    b.append(a[x-1])

print(b)