from collections import Counter
import re
import time

texto = open("quijote.txt", encoding="utf-8").read()

inicio = time.time()
total = Counter(re.findall(r"[^\W\d_]+", texto.lower()))

print(f"Local en {time.time() - inicio:.2f} s")
print(f"Palabras: {sum(total.values())}, distintas: {len(total)}")
for palabra, n in total.most_common(5):
    print(f"  {palabra}: {n}")
