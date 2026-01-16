def is_valid(isbn):
    is_isbn = False
    isbn_clean = isbn.replace("-", "").upper()
    if not isbn_clean[:-1].isnumeric() or len(isbn_clean) != 10 or not(isbn_clean.endswith("X") or isbn_clean[-1].isnumeric()):
        return is_isbn
    multilayer = 10
    helper = 0
    for number in isbn_clean:
        if number == "X":
            number = 10
        helper += int(number) * multilayer
        multilayer -= 1
    if helper%11 == 0:
        is_isbn = True
    return is_isbn