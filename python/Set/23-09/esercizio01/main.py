num = float(input("Inserisci dei numeri, quando inserisci '0' si blocca: ")) #Prendo il numero
while num != 0: #ciclo
    num = float(input(f"{num:.2f}, prossimo numero: ")) #prendo i prossimi numeri
print("Stop") #fine