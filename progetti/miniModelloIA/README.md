# Mini Rete Neurale in C — Parità a 3 bit

Una rete neurale minimale implementata da zero in C, senza librerie esterne.  
Il micro modello calcola il **bit di parità pari** su 3 bit di input.

---

## Struttura della rete

```
Input (3 nodi)
    │
    ├──► Neurone hidden 0 ──┐
    │                        ├──► Neurone output ──► sigmoid ──► bit di parità
    └──► Neurone hidden 1 ──┘
```

- **Input layer:** 3 valori (0 o 1)
- **Hidden layer:** 2 neuroni con attivazione sigmoid
- **Output layer:** 1 neurone con attivazione sigmoid
- **Funzione di attivazione:** sigmoid `σ(z) = 1 / (1 + e^-z)`
- **Soglia di decisione:** output > 0.25 → parità 1, altrimenti 0

---

## File del progetto

```
.
├── main.c         # Rete neurale (forward pass + inferenza)
└── weight.txt     # Pesi e bias della rete (letti/scritti a runtime)
```

---

## Formato weight.txt

I pesi sono salvati in ordine riga per riga:

```
# Neurone hidden 0
w0
w1
w2
bias
# Neurone hidden 1
w0
w1
w2
bias
# Neurone output
w0
w1
bias
```

weight.txt:
```
-7.041438
-7.041430
-7.041404
10.453669
1.413550
1.413541
1.413517
-2.014847
-8.317084
-14.068682
9.103774
```

---

## Utilizzo

```bash
./main <bit0> <bit1> <bit2>
```

Esempi:
```bash
./main 0 0 0
# OUTPUT FINALE: 0.295610
# Bit di parita': 1   ✓ (zero 1 → parità pari)

./main 1 1 0
# OUTPUT FINALE: 0.298379
# Bit di parita': 1   ✓ (due 1 → parità pari)

./main 1 0 0
# OUTPUT FINALE: 0.019287
# Bit di parita': 0   ✓ (uno 1 → parità dispari)
```


### Tabella di verità — parità pari

| Input | N. di 1 | Parità | Target |
|-------|---------|--------|--------|
| 0 0 0 | 0 | pari | 1 |
| 0 0 1 | 1 | dispari | 0 |
| 0 1 0 | 1 | dispari | 0 |
| 0 1 1 | 2 | pari | 1 |
| 1 0 0 | 1 | dispari | 0 |
| 1 0 1 | 2 | pari | 1 |
| 1 1 0 | 2 | pari | 1 |
| 1 1 1 | 3 | dispari | 0 |

---

## Come funziona il training

**Forward pass:**
```
z = w·x + bias
a = sigmoid(z)
```

**Loss (Mean Squared Error):**
```
L = (output - target)²
```

**Backpropagation:**
```
δ_out     = (a_out - target) · a_out · (1 - a_out)
δ_hidden  = δ_out · w_out · a_h · (1 - a_h)
```

**Aggiornamento pesi:**
```
w ← w - lr · δ · input
b ← b - lr · δ
```

## Note tecniche

- I pesi vengono inizializzati manualmente nel `weight.txt` prima del primo training
- Con input `0 0 0` solo i **bias** si aggiornano durante il training (i gradienti dei pesi sono zero perché `input[j] = 0`)
- La sigmoid non raggiunge mai esattamente 0 o 1 — la soglia a `0.25` è stata scelta sperimentalmente
- La parità XOR a 3 bit è un problema **non linearmente separabile**: 2 neuroni hidden potrebbero non bastare per convergere completamente; aumentare a 4 migliora la stabilità

---

## Dipendenze

- `gcc` (o qualsiasi compilatore C99+)
- `libm` (matematica standard — flag `-lm`)
- Nessuna libreria esterna


## README.md scritto con Sonnet 4.6 basso, con alcune correzioni.