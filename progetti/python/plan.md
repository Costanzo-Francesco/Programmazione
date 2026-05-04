# Piano di lavoro: AI‑scripted Snake in Python

## 1. Obiettivo
Creare un gioco Snake in cui:
1. Un giocatore umano può controllare la testa della serpentina tramite tastiera.
2. Un modello AI è responsabile di generare lo script Python (compilazione, gestione della logica, rendering, ecc.) in modo che il gioco sia pronto per l’esecuzione.

---

## 2. Requisiti
| Tipo | Requisito | Note |
|------|-----------|------|
| Funzionale | Controllo in tempo reale del serpente con i tasti `← ↑ → ↓` | Debe essere responsivo (< 100 ms) |
| Funzionale | Generazione di script Python dall’AI | Codice deve essere eseguibile con Python 3.10+ |
| Non‑funzionale | Performance | FPS ≥ 30 (in modalità console) |
| Non‑funzionale | Manutenibilità | Struttura modulare, documentazione inline |
| Sicurezza | Evitare codice dannoso | Filtraggio e sandboxing dei blocchi generati |

---

## 3. Struttura del progetto

```
snake_ai/
├── src/
│   ├── __init__.py
│   ├── main.py            # entry‑point
│   ├── game/
│   │   ├── __init__.py
│   │   ├── board.py       # logica della griglia
│   │   ├── snake.py       # modello del serpente
│   │   ├── food.py        # generazione del cibo
│   │   └── renderer.py    # visualizzazione (console/Pygame)
│   ├── ai/
│   │   ├── __init__.py
│   │   ├── generator.py   # interfaccia AI per generare script
│   │   └── policies.py    # eventuali policy pre‑definite
│   └── utils/
│       ├── __init__.py
│       └── input_handler.py
├── tests/
│   ├── test_game.py
│   └── test_ai.py
├── requirements.txt
└── README.md
```

---

## 4. Design dettagliato

### 4.1 Loop di gioco
```python
while running:
    handle_input()
    update_game_state()
    render()
```

### 4.2 Input
- **Keyboard**: `curses` (console) oppure `pygame.key.get_pressed()` (Pygame)
- **AI‑generated script**: l’AI deve generare una funzione `handle_input()` che legga i tasti e aggiorni la direzione del serpente.

### 4.3 Logica del serpente
- Lista di tuple `(x, y)` per segmenti.
- `move()` aggiunge un nuovo head in base alla direzione e rimuove l’ultimo segment (se non è mangiato).

### 4.4 Cibo
- Posizione casuale non occupata da serpentini.
- Quando il serpente mangia, la lunghezza aumenta di 1.

### 4.5 Collisioni
- Collisione con pareti → game over.
- Collisione con se stesso → game over.

### 4.6 Rendering
- **Console**: `curses` per disegnare griglia e oggetti.
- **Pygame** (opzionale): grafica 2D, sprites.

---

## 5. Integrazione AI

### 5.1 Ruolo dell’AI
- **Generator**: prende in input una descrizione del comportamento richiesto (es. “Snake game with keyboard control”) e restituisce uno script Python completo (`main.py`).
- **Validatore**: controlla che lo script non contenga codice pericoloso (usare `ast` per l'analisi statica).
- **Ottimizzatore**: può suggerire miglioramenti (commenti, docstring, refactoring).

### 5.2 Pipeline di generazione
1. **Prompt** → *modello LLM* (es. GPT‑4) produce **bozza di codice**.
2. **Parsing** → `ast.parse` verifica sintassi.
3. **Sandbox** → esecuzione limitata in ambiente isolato per test rapido.
4. **Test unitari** → `pytest` con mock di input per verificare correttezza logica.
5. **Deployment** → script finalizzato scritto in `src/main.py`.

### 5.3 Formato del prompt (esempio)

```
Scrivi un gioco Snake in Python con la seguente struttura:
- Il serpente è controllato con i tasti → ↑ ← ↓ →
- Il cibo appare in posizioni casuali.
- Game over quando il serpente collide con le pareti o con se stesso.
- Usa la libreria curses per la grafica in console.
Organizza il codice in moduli: main.py, game/board.py, game/snake.py, game/food.py, game/renderer.py.