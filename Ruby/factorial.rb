# Return the factorial of a number

def factorial(n)
while n >= 1
  return(n*factorial(n-1))
end
if n==0
  return 1
end
return nil
end

puts factorial(44)
