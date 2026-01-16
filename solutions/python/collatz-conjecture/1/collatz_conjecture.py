def steps(number):
    steps = 0
    if number == 1:
        return steps
    elif number % 2 != 0 or number == 0:
        raise ValueError("Only positive integers are allowed")
    while number > 1:
        if number % 2 == 0:
            number /= 2
            steps += 1
        else:
            number = number*3 +1
            steps += 1
    return steps
