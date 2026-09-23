numeroStudenti = int(input("Inserisci il numero di studenti: "))
somma = 0
for i in range(numeroStudenti):
    voto = float(input(f"Inserisci il voto dello studente numero {i + 1}: "))
    while voto < 18 or voto > 30:
        voto = float(input(f"Errore voti solo da 18 a 30, reinserisci il voto dello studente numero {i + 1}: "))

    somma += voto
print(f"La media dei voti degli studenti è: {somma / numeroStudenti} punti")