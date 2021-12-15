import serial
import time
import urllib.request
import json

arduino = serial.Serial(port='COM4', baudrate=9600, timeout=.1)
read_api_key = "REG5C56EQ2XIF2NL"
channel_id = '1601670'

while True:
    time.sleep(15)
    TS = urllib.request.urlopen(
        "https://api.thingspeak.com/channels/1601670/feeds.json?api_key=REG5C56EQ2XIF2NL&results=2")
    response = TS.read()
    data = json.loads(response)
    print(data['feeds'])
    for value in data['feeds']:
        arduino.write(bytes(value['field1'], 'utf-8'))
    TS.close()
    TS = urllib.request.urlopen(
        "https://api.thingspeak.com/channels/1608807/feeds.json?api_key=GA4Y4O7RWEY31YFX&results=2")
    response = TS.read()
    data = json.loads(response)
    print(data['feeds'])
    for value in data['feeds']:
        arduino.write(bytes(value['field1'], 'utf-8'))

