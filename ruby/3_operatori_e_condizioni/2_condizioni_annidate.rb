energia = 50
protezione = 20

if energia > 0
  if protezione > 30
    puts "Sei pronto per combattere!"
  else
    puts "Troppo fragile per duellare!"
  end
else
  puts "Hai bisogno di una pozione!"
end
