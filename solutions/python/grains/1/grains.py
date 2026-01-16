def square(number):
    if number < 1 or number > 64:
        raise ValueError("square must be between 1 and 64")
    return 2**(number-1)


def total():
    total_sum = 0
    for i in range(64):
        result = 2**i + total_sum
        total_sum = result
    return total_sum
