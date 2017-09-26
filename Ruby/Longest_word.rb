# Input a string and find the longest word in it.

def longest_word(sentence)
list=sentence.split(' ')
leng = list[0].length
answer=nil
for i in (1..list.length-1)
  answer = list[i] if (list[i].length>leng)
end
return answer
end

puts longest_word("This sentence is short")
