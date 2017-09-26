#Input a string and get a string with all the vowels removed

def antiv(text)
  vowels=['a','e','i','o','u','A','E','I','O','U']
  indexr=0
  answer=""
  while indexr<text.length
    answer += text[indexr] if (!(vowels.include? text[indexr]))
    indexr+=1
  end
  return answer
end

puts antiv("What is love, I don't know!")
