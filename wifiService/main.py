import serial
import time
import urllib.request
import json

arduino = serial.Serial(port='COM4', baudrate=9600, timeout=.1)
read_api_key = "REG5C56EQ2XIF2NL"
channel_id = '1601670'

while True:
    TS = urllib.request.urlopen(
        "https://api.thingspeak.com/channels/1601670/feeds.json?api_key=REG5C56EQ2XIF2NL&results=2")
    response = TS.read()
    data = json.loads(response)
    print(data['feeds'])
    for value in data['feeds']:
        arduino.write(bytes(value['field1'], 'utf-8'))
        time.sleep(15)

    TS.close()
