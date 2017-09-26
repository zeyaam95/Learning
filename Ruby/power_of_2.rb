# Input an integer and return if it is a power of two or not

def is_pow_2(num)
  return false if (num%3==0 || num<=0)
  while num%2==0 && num >=0
    num=num/2
  end
  num==1 ? true:false
end

puts is_pow_2(2050)
