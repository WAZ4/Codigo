given_list = [7 ,5, 4, 4, 3, 1, -2, -3, -5, -7]

total = 0
i = 0

while i < len(given_list):
    if given_list[i] < 0:
        total += given_list[i]
    i += 1
print(total)
