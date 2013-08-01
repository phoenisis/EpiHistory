##!/bin/ruby

#--------------------------209SONDAGE---------------------------#

if (ARGV[0] == nil || File.exist?(ARGV[0]) == false || File.size?(ARGV[0]) == nil || ARGV[1] == nil)
  puts "Usage : ruby 209Sondage.rb [file] [number]."
  Process.exit(false)
end

$nb = ARGV[1]
file = File.new(ARGV[0])
file = file.read(file.size)
file =  file.split
$values = Array.new

file.each do |value|
  $values << value.to_f
end

$first = $values[0]
$values.delete_at(0)
$eff = 0
i = 0

def population
    puts "Population: %s" % ARGV[0]

end

def nb_individu
  puts "Nombre d'individu: %d" % $first
end

def moyenne
  i = 0
  x = 0

  while i < $values.size do
    x += ($values[i])
    i += 1
  end
  puts "Moyenne m: %.3f" % (x / i)
end

def ecartype
  
  ary = $values
  mean = ary.inject(:+).to_f / ary.size  
  res = Math.sqrt(ary.inject(0){|sum,val| sum + (val - mean)**2} / ary.size)

  puts "Ecart Type s: %.3f" % (res) 
  $ecart_type = res
end

def echantillonnage
  puts "Echantillons de taille :%d" % $nb
end

def fact(n) 
  if n == 0 
    1 
  else n * fact(n-1) 
  end 
end

def nb_echantillon

  res = (fact($first) / (fact($nb.to_f) * fact($first - $nb.to_f )));

  puts "Nombre d'echantillons : %d" % res
  $nb_ech = res
end

def moyennen
  i = 0
  x = 0

  while i < $values.size do
    x += ($values[i])
    i += 1
  end
  $glob = (x / i)
  puts "Moyenne: %.3f" % $glob
end

def ecartype_echantillon
  ary = $values
  mean = ary.inject(:+).to_f / ary.size  
  $res = Math.sqrt(($ecart_type ** 2) / $nb.to_f * (($first - $nb.to_f) / ($first - 1)))  

  puts "Ecart-type: %.3f" % $res
end

def ecartype_echantillon_calc
  
  puts "Ecart-type calcule d'apres s: %.3f" % $res
end

puts "\n"
puts "209Sondage :\n-----------"
population
nb_individu
moyenne
ecartype
puts "\n"

echantillonnage
nb_echantillon
moyennen
ecartype_echantillon
ecartype_echantillon_calc
puts "\n"
