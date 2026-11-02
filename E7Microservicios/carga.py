import json, sys, time, urllib.request
from concurrent.futures import ThreadPoolExecutor
from collections import Counter

N = int(sys.argv[1]) if len(sys.argv) > 1 else 20

def pedir():
    with urllib.request.urlopen("http://gateway/productos/1") as r:
        return json.load(r)["replica"]

inicio = time.time()
with ThreadPoolExecutor(max_workers=N) as ex:
    replicas = list(ex.map(pedir, range(N)))

print(f"{N} peticiones en {time.time() - inicio:.2f} s")
for replica, n in Counter(replicas).items():
    print(f"  {replica}: {n} peticiones")