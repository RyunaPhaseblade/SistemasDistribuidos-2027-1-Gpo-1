import requests
from flask import Flask, jsonify, request

app = Flask(__name__)

@app.post("/pedidos")
def crear():
    datos = request.get_json()
    # Los demás servicios se localizan por su nombre en la red de Docker
    u = requests.get(f"http://usuarios:5000/usuarios/{datos['usuario']}", timeout=2)
    if u.status_code != 200:
        return jsonify(error="Usuario no valido"), 400
    
    p = requests.get(f"http://catalogo:5000/productos/{datos['producto']}", timeout=2)
    if p.status_code != 200:
        return jsonify(error="Producto no valido"), 400
    
    cliente = u.json()
    producto = p.json()
    
    return jsonify(cliente=cliente["nombre"],
                   producto=producto["nombre"],
                   cantidad=datos["cantidad"],
                   total=producto["precio"] * datos["cantidad"]), 201

app.run(host="0.0.0.0", port=5000)