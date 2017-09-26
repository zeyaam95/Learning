#Remove vowels from a string

def antiv(txt):
    vowel = ['a','e','i','o','u','A','E','I','O','U']
    indexr=0
    while indexr < len(txt):
        if txt[indexr] in vowel:
            txt = txt.replace(txt[indexr],'')
        else:
            indexr+=1
    return txt

teststr="The expression itself is two values separated by the condition."


print(antiv(teststr))
