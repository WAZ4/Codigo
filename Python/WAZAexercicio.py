def count_evens(lista):
    total = 0
    for x in lista:
        if (x % 2) == 0:
            total += 1
    return total

print(count_evens([2, 1, 2, 3, 4]))