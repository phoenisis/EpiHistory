#!/usr/local/bin/ruby

if (ARGV[0] == nil || File.exist?(ARGV[0]) == false || File.size?(ARGV[0]) == nil)   
  puts "Missing file.txt as an argument..."
  Process.exit(false)
end

file = File.new(ARGV[0])
file = file.read(file.size)
file =  file.split
$values = Array.new
file.each do |value|
  $values << value.to_f
end

$values.delete_at(0)
$eff = 0
i = 0
while i < $values.size do
  $eff += $values[i + 1]
  i += 2
end

def              arithm_moy
  i = 0
  x = 0
  nbef = 0
  while i < $values.size do
    x += $values[i] * $values[i + 1]
    i += 2
  end
  puts "Moyenne Arithmetique: %.3f.\n" % (x / $eff)
end

def             quadratic_moy
  i = 0
  x = 0
  nbef = 0
  res = 0
  while i < $values.size do
    x += (($values[i] * $values[i]) * ($values[i + 1]))
    i += 2
  end
  res = Math.sqrt((x) / ($eff))
  puts "Moyenne Quadratique: %.3f\n." % (res)
end

def             geo_moy
  i = 0
  x = 0
  nbef = 0
  res = 0
  while i < $values.size do
    x += $values[i + 1] * Math.log($values[i])
    i += 2
  end
  res = Math.exp(x / $eff)
  puts "Moyenne Geometrique: %.3f.\n" % (res)
end

def             harmo_moy
  i = 0
  x = 0
  res = 0
  nbef = 0
  while i < $values.size do
    x += $values[i + 1] / $values[i]
    i += 2
  end
  res = $eff / x
  puts "Moyenne Harmonique: %.3f.\n" % (res)
end

def             mediane
  res = 0
  puts "Mediane: %.3f.\n" % (res)
end

def             mode
  $values.sort 
  res = $values[10]
  puts "Mode: %.3f.\n" % (res)
  
end

def             variance
  i = 0
  x = 0
  nbef = 0
  moy = 0
  res = 0
  while i < $values.size do
    x += $values[i] * $values[i + 1]
    i += 2
  end
  moy = x / $eff
  x = 0
  i = 0
  while i < $values.size do
    x += $values[i + 1] * (($values[i] - moy) * ($values[i] - moy))
    i += 2
  end
  res = x / $eff
  puts "Variance: %.3f.\n" % res
end

def             ecartype
  i = 0
  x = 0
  nbef = 0
  moy = 0
  res = 0
  ecartype = 0
  while i < $values.size do
    x += $values[i] * $values[i + 1]
    i += 2
  end
  moy = x / $eff
  x = 0
  i = 0
  while i < $values.size do
    x += $values[i + 1] * (($values[i] - moy) * ($values[i] - moy))
    i += 2
  end
  res = x / $eff
  ecartype = Math.sqrt(res)
  puts "Ecart Type: %.3f.\n" % ecartype
end

def             ecartmoyen
  i = 0
  x = 0
  nbef = 0
  moy = 0
  res = 0
  while i < $values.size do
    x += $values[i] * $values[i + 1]
    i += 2
  end
  moy = x / $eff
  i = 0
  x = 0
  while i < $values.size do
    #x += ($values[i + 1] * $values[i]) - ($values[i + 3] * $values[i + 2]) 
    i += 2
  end
  res = x / $eff
  puts "Ecart Moyen: %.3f.\n" % res
end

def             ecartmedian
  res = 0
  puts "Ecart Median: %.3f.\n" % res
end
      
puts "\n\n"
arithm_moy
puts "\n\n"
quadratic_moy
puts "\n\n"
geo_moy
puts "\n\n"
harmo_moy
puts "\n\n"
mediane
puts "\n\n"
mode
puts "\n\n"
variance
puts "\n\n"
ecartype
puts "\n\n"
ecartmoyen
puts "\n\n"
ecartmedian
puts "\n\n"
