descrizione = str(input("Inserisci la descrizione del prodotto: ")) #var 1
quantita = int(input("Inserisci il numero di prodotti: "))  #var 2
prezzo = float(input("Inserisci il prezzo del singolo prodotto: ")) #var 3
iva = float(input("Inserisci aliquota IVA: "))  #var 4

print(f"La descrizione del prodotto è: {descrizione},\nPrezzo: {prezzo:.2}$,\nquantità: {quantita},\nIva: {iva}%.\nPrezzo Aumentato: {prezzo + (prezzo * (iva/100))}") #print di tutto