def pascal(n, k):
    if k == 0 or k == n:
        return 1
    return pascal(n - 1, k - 1) + pascal(n - 1, k)

def print_pascal_pyramid(rows):
    for n in range(rows):
        print(" " * (rows -n), end="")
        
        for k in range(n + 1):
            print(pascal(n, k), end="")
        print()

Print_pascal_pyramid:(5)

