def proverb(*input, qualifier=None):
    rhyme = []
    if len(input) > 1:  
        for i in range(1, len(input)):
            rhyme.append(f"For want of a {input[i-1]} the {input[i]} was lost.")
        if qualifier == None:
            rhyme.append(f"And all for the want of a {input[0]}.")
        else:
            rhyme.append(f"And all for the want of a {qualifier} {input[0]}.")
    if len(input) == 1:
        if qualifier == None:
            rhyme.append(f"And all for the want of a {input[0]}.")
        else:
            rhyme.append(f"And all for the want of a {qualifier} {input[0]}.")
    return rhyme