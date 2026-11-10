from collections import Counter
from concurrent.futures import ThreadPoolExecutor
import json
import sys
import time
import urllib.error
import urllib.request

URL = "https://contar-palabras.leonardolr1313.workers.dev/"
N = int(sys.argv[1]) if len(sys.argv) > 1 else 4

def contar(trozo):
    peticion = urllib.request.Request(
        URL, data=trozo.encode(), headers={"User-Agent": "practica7"}
    )
    try:
        with urllib.request.urlopen(peticion) as r:
            return json.load(r)["conteo"]
    except urllib.error.HTTPError as e:
        return e.code  # Captura respuestas con código HTTP de error (ej. 500, 524)
    except Exception:
        return 500     # Captura cierres bruscos SSL, URLError, timeouts y cortes de red

lineas = open("quijote.txt", encoding="utf-8").read().splitlines()

# Reparto: N trozos de lineas consecutivas
trozos = [
    "\n".join(lineas[k * len(lineas) // N : (k + 1) * len(lineas) // N])
    for k in range(N)
]

inicio = time.time()
with ThreadPoolExecutor(max_workers=N) as ex:
    parciales = list(ex.map(contar, trozos))

print(f"{N} funciones en {time.time() - inicio:.2f} s")

fallos = [p for p in parciales if isinstance(p, int)]
if fallos:
    print(f"{len(fallos)} de {N} funciones fallaron, codigos: {set(fallos)}")

# Reduccion: se suman los conteos parciales
total = Counter()
for p in parciales:
    if isinstance(p, dict):
        total.update(p)

print(f"Palabras: {sum(total.values())}, distintas: {len(total)}")
for palabra, n in total.most_common(5):
    print(f"  {palabra}: {n}")
