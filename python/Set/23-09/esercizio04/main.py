cont = 1 #contatore
totStipendi = 0
stipendio = float(input(f"Inserisci stipendio {cont}, -1 per terminare: ")) #Primo stipendio
totStipendi += float(stipendio)
while stipendio != -1:  #ciclo
    stipendio = float(input(f"Inserisci stipendio {cont}, -1 per terminare: "))
    if stipendio != -1: #condizione per evitare l'unione di -1 al totale e aggiunta di numero al contatore
        totStipendi += stipendio
        cont += 1

print(f"La media è: {totStipendi / cont}")