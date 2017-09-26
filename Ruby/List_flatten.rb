# Flattens a list of lists

def flatten(list)
  lis=[]
  list.each_with_object([]) do |element, flat|
    flat.push *(element.is_a?(Array)? flatten(element) : element)
    lis=flat
  end
  return lis
end


print "#{flatten([1,2,[3,4,5,[6,7,8])}"
