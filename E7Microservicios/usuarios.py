from flask import Flask, jsonify

app = Flask(__name__)
USUARIOS = {1: "Ana", 2: "Luis", 3: "Sofia"}

@app.get("/usuarios/<int:uid>")
def obtener(uid):
    if uid not in USUARIOS:
        return jsonify(error="Usuario no encontrado"), 404
    return jsonify(id=uid, nombre=USUARIOS[uid])

app.run(host="0.0.0.0", port=5000)