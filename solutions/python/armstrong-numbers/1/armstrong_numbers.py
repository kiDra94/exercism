def is_armstrong_number(number):
    number_string = str(number)
    armstrong = 0
    for ch in number_string:
        result = armstrong + (int(ch)**len(number_string))
        armstrong = result
    if armstrong == number:
        return True
    return False
    
