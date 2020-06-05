given_list = [1, 3, 4, 1, 3, 1]

a = set()
for x in given_list:
    a.add(x)
total = 0
for x in a:
    total += x

print(total)