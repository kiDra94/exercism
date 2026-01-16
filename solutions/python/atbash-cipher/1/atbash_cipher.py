def encode(plain_text):
    plain = "abcdefghijklmnopqrstuvwxyz"
    cipher = "zyxwvutsrqponmlkjihgfedcba"
    word = plain_text.lower().replace(" ", "").replace(",", "").replace(".", "")
    encoded = ""
    cnt = 0
    for i, cha in enumerate(word):
        if i>=5 and i%5==0:
            encoded += " "
        if cha.isnumeric() or cha.isalpha():
            if 'a' <= cha <= 'z':
                encoded += cipher[plain.index(cha)]
            else:
                encoded += cha
    return encoded.removeprefix(" ")

def decode(ciphered_text):
    plain = "abcdefghijklmnopqrstuvwxyz"
    cipher = "zyxwvutsrqponmlkjihgfedcba"
    word = ciphered_text.lower()
    encoded = ""
    for cha in word:
        if 'a' <= cha <= 'z':
            encoded += plain[cipher.index(cha)]
        else:
            encoded += cha
    return encoded.replace(" ", "")
