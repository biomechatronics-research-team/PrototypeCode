import serial
from datetime import datetime
import serial.tools.list_ports

ports = list(serial.tools.list_ports.comports())
for p in ports:
    print(p)

myPort = input()

ser = serial.Serial(myPort, baudrate=9600)

while 1:
    arduinoData = ser.readline().decode('ascii')
    dateTimeObj = datetime.now()
    print("Position is %s at %s " % (arduinoData, dateTimeObj), "\n")
