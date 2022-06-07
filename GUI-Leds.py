import serial
import threading
import time
import PySimpleGUI as sg

conectado = False
porta = 'COM3'
velocidadeBaud = 9600

mensagensRecebidas = 1
desligarArduinoThread = False

try:
    SerialArduino = serial.Serial(porta, velocidadeBaud, timeout=0.2)
except:
    print("Verificar porta serial ou religar arduino")






print("Preparando Arduino")
time.sleep(2)
print("Arduino Pronto")
sizeof = 30
sizein = 3
def func(message):
    print("{}".format(message))
    if(message == message):
        SerialArduino.write('{}\n'.format(message).encode())
#sg.theme('Dark blue')
layout = [[
            sg.Button('Ligar led Azul', key=lambda: func('ligar led azul'),size= (sizeof,sizein)),
            sg.Button('Desligar led Azul', key=lambda: func('desligar led azul'),size= (sizeof,sizein))],[
            sg.Button('Ligar led Amarelo', key=lambda: func('ligar led amarelo'),size= (sizeof,sizein)),
            sg.Button('Desligar led Amarelo', key=lambda: func('desligar led amarelo'),size= (sizeof,sizein))],[
            sg.Button('Ligar led Branco', key=lambda: func('ligar led branco'),size= (sizeof,sizein)),
            sg.Button('Desligar led Branco', key=lambda: func('desligar led branco'),size= (sizeof,sizein))],[
            sg.Button('Ligar led RGB', key=lambda: func('ligar led rgb'),size= (sizeof,sizein)),
            sg.Button('Desligar led RGB', key=lambda: func('desligar led rgb'),size= (sizeof,sizein))],[
            sg.Button('Ligar todos os leds', key=lambda: func('ligar todos os leds'),size= (sizeof,sizein)),
            sg.Button('Desligar todos os leds', key=lambda: func('desligar todos os leds'),size= (sizeof,sizein))]
        ]
window = sg.Window('AI arduino', layout)
while (True):
    try:

        event, values = window.read()
        if callable(event):
            event()
        if(event == sg.WIN_CLOSED):
            desligarArduinoThread = True
            SerialArduino.close()
            break


    except KeyboardInterrupt:
        print("Apertou Ctrl+C")
        desligarArduinoThread = True
        SerialArduino.close()
        break
window.close()
