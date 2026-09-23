a = float(input("Inserisci il primo numero: ")) #Prendo i dati
b = float(input("Inserisci il secondo numero: "))
if a * b > 10:   #Condizione 1
    if a > b:   #Gestione casistiche
        print(f"La differenza dei due è {a-b:.2f}")
    else :
        print(f"La differenza dei due è {b-a:.2f}")
else:
    print(f"La somma dei due è {a+b:.2f}")