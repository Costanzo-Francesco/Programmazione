# Pagina 25 Esercizio 6

import math

raggio = float(input("Inserisci il raggio del cilindro: "))
altezza = float(input("Inserisci l'altezza del cilindro: "))

volume = round(math.pi * raggio**2 * altezza, 2)
print(f"Il volume del cilindro è {volume} cm^3")