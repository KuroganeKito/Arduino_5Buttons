import serial
import time
import keyboard
arduino = serial.Serial(port='COM5', baudrate=115200, timeout=.1)

def read_read():
    arduino.write(bytes("0", 'utf-8'))
    time.sleep(0.05)
    data = arduino.readline()
    return data

while True:
    value = str(read_read())
    print(value)
    for x in value:
        if x == "1":
            keyboard.send(x)
        elif x == "2":
            keyboard.send(x)
        elif x == "3":
            keyboard.send(x)
        elif x == "4":
            keyboard.send(x)
        elif x == "5":
            keyboard.send(x)