def convert(number):
    result = ""
    finished = False
    if number % 3 != 0 and number % 7 != 0 and number % 5 != 0:
        result += str(number)
        return result
    elif number % 3 == 0 and number % 7 == 0 and number % 5 == 0:
        result += "PlingPlangPlong"
    elif number % 3 == 0 and number % 5 == 0:
        result += "PlingPlang"
    elif number % 5 == 0 and number % 7 == 0:
        result += "PlangPlong"
    elif number % 3 == 0 and number % 7 == 0:
        result += "PlingPlong"
    elif number % 3 == 0:
        number /= 3
        result += "Pling"
    elif number % 5 == 0:
        number /= 5
        result += "Plang"
    elif number % 7 == 0:
        number /= 7
        result += "Plong"
    return result
