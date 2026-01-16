def transform(legacy_data):
    refactored = {}
    for key, value in legacy_data.items():
        for letter in value:
            refactored[letter.lower()] = key
    return refactored
