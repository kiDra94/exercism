def is_pangram(sentence):
    letters = [chr(i) for i in range(97,123)]
    let_dict = {}
    is_panagram_bool = True
    for cha in letters:
        let_dict.setdefault(cha, sentence.lower().count(cha))
    for value in let_dict.values():
        if value < 1:
            return False
    return is_panagram_bool
        
