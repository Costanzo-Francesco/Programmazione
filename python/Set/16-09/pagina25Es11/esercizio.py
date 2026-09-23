# Pagina 25 esercizio 11

N_VOTI = 3
tot = 0
print("Inserisci 3 voti per il calcolo della media")
for i in range(N_VOTI):
    tot += float(input(f"Inserisci voto {i + 1}: "))

print(f"La media è {tot / N_VOTI :.2}")