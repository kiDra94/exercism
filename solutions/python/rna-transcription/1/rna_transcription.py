def to_rna(dna_strand):
    rna = ""
    translaton = {'G' : 'C', 'C' : 'G', 'T' : 'A', 'A' : 'U'}
    for cha in dna_strand:
        rna += translaton.get(cha)
    return rna
