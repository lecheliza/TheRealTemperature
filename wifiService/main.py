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
    t1 = data['feeds'][0]['field1']
    print(t1)
    TS.close()
    TS2 = urllib.request.urlopen(
        "https://api.thingspeak.com/channels/1608807/feeds.json?api_key=GA4Y4O7RWEY31YFX&results=2")
    response2 = TS2.read()
    data2 = json.loads(response2)
    t2 = data2['feeds'][0]['field1']
    print(t2)
    TS2.close()
    arduino.write(bytes(t1 + ' ' + t2, 'utf-8'))
    time.sleep(15)
