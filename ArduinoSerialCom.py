import serial
from datetime import datetime

ser = serial.Serial('/dev/cu.usbserial-DN03AUZ6', baudrate=9600)

while 1:
    arduinoData = ser.readline().decode('ascii')
    dateTimeObj = datetime.now()
    print("Position is %s at %s " % (arduinoData, dateTimeObj), "\n")






