#Input a list of lists and have it flattened

def flattent(list_o_l):
    answer=[]
    for i in list_o_l:
        answer+=flattent(i) if isinstance(i,list) else [i]
    return answer


print(flattent([1,2,3,[4,5,6,[7,8,9]]]))
