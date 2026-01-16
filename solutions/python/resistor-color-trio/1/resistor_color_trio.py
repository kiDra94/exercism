def label(colors):
    color_code_dict = {
    "black": 0,
    "brown": 1,
    "red": 2,
    "orange": 3,
    "yellow": 4,
    "green": 5,
    "blue": 6,
    "violet": 7,
    "grey": 8,
    "white": 9}

    first_digit = color_code_dict[colors[0]]
    second_digit = color_code_dict[colors[1]]
    zeros = color_code_dict[colors[2]]

    resistance_value = (first_digit * 10 + second_digit) * (10 ** zeros)
    if resistance_value >= 1_000_000_000:
        resistance_str = f"{resistance_value // 1_000_000_000} gigaohms"
    elif resistance_value >= 1_000_000:
        resistance_str = f"{resistance_value // 1_000_000} megaohms"
    elif resistance_value >= 1_000:
        resistance_str = f"{resistance_value // 1_000} kiloohms"
    else:
        resistance_str = f"{resistance_value} ohms"
    
    return resistance_str
        

