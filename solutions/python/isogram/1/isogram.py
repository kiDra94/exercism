def is_isogram(string):
    word = string.lower()
    is_isogra = False
    count = 0
    for cha in word:
        if word.count(cha) > 1 and 'a' <= cha <= 'z':
            count += 1
    if count == 0:
        is_isogra = True
    return is_isogra
        
