def sum_of_multiples(limit, multiples):
    points = set()
    total = 0
    if len(multiples) < 1:
        return 0
    for multiple in multiples:
        for i in range(limit):
            if multiple == 0:
                continue
            if i % multiple == 0:
                points.add(i)
    for point in points:
        total += point
    return total