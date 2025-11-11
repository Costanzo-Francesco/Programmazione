puts "Come ti chiami?"

nome = gets.chomp   # gets : prende input con \n. chomp : rimuove l'invio.

puts "Quanti anni hai?"

eta = gets.chomp.to_i

puts "Benvenuto #{nome}. Hai #{eta} anni"