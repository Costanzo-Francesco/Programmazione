votiCandidato1 = int(input("Inserisci i voti del primo candidato: "))
votiCandidato2 = int(input("Inserisci i voti del secondo candidato: "))
totVoti = votiCandidato1 + votiCandidato2
print(f"La percentuale dei voti del primo candidato è: {(votiCandidato1 / totVoti) * 100}%.\nLa percentuale dei voti del secondo candidato è:  {(votiCandidato2 / totVoti) * 100}%.")
if votiCandidato1 > votiCandidato2 :
    print(f"Ha vinto il candidato 1 con il {(votiCandidato1 / totVoti) * 100}%.")
elif votiCandidato2 > votiCandidato1:
    print(f"Ha vinto il candidato 2 con il {(votiCandidato2 / totVoti) * 100}%.")
else:
    print("Nessuno ha vinto, è un pareggio.")
