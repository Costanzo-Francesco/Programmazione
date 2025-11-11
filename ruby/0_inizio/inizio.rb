puts "Inserisci due numeri per ottenerne la somma" # puts si usa come printf ma senza ()

numero1 = gets.chomp.to_i                          

print "Inserisci il secondo numero: "
numero2 = gets.chomp.to_i

somma = numero1 + numero2

puts "La somma di #{numero1} e #{numero2} è #{somma}."


#gets  serve per registrare la variabile

#chomp serve per togliere il carattere “a capo” (\n) alla fine della stringa.

#to_i  Serve per convertire una stringa in un numero intero.
