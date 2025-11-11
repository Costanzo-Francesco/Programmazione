puts "Benvenuto ragazzo! sei pronto a scegliere il tuo primo pokemon? \n Vediamo un po' mi sono rimasti charmander, squirtle e bulbasaur"

pokemon = gets.chomp.to_s

case pokemon
when pokemon = "charmander" 
    puts "Hai un cuore ardente e una forza indomabile."
when pokemon = "squirtle" 
    puts "Saggio e calmo, ma capace di tempesta."
when pokemon = "bulbasaur"
    puts "Il fruscio guiderà il tuo animo"
else
    puts "Non credo di averlo qui..."
end

puts "Buona fortuna ragazzo!"