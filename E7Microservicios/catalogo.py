import socket, time
from flask import Flask, jsonify

app = Flask(__name__)
PRODUCTOS = {1: ("Teclado", 350.0), 2: ("Mouse", 180.0), 3: ("Monitor", 2800.0)}

@app.get("/productos/<int:pid>")
def obtener(pid):
    time.sleep(0.2) # Simula una consulta lenta a la base de datos
    if pid not in PRODUCTOS:
        return jsonify(error="Producto no encontrado"), 404
    nombre, precio = PRODUCTOS[pid]
    # replica: nombre del contenedor que atendió la petición
    return jsonify(id=pid, nombre=nombre, precio=precio, replica=socket.gethostname())

# threaded=False: cada réplica atiende una petición a la vez
app.run(host="0.0.0.0", port=5000, threaded=False)