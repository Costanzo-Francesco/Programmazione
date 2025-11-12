
puts "Inserisci età"
anni =  gets.chomp.to_i

while anni < 18
    puts "Minorenne"
    anni =  gets.chomp.to_i
end

puts "Maggiorenne"