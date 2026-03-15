import cv2
import numpy as np
from ultralytics import YOLO
import socket
import serial

model = YOLO("best.pt")

ser = serial.Serial("COM5",9600)

HOST = "192.168.4.1"
PORT = 80

while True:

    s = socket.socket()
    s.connect((HOST,PORT))

    data = b''

    while True:
        packet = s.recv(4096)
        if not packet:
            break
        data += packet

    s.close()

    frame = cv2.imdecode(np.frombuffer(data,np.uint8),1)

    results = model(frame)

    command = "N"

    for r in results:
        for box in r.boxes:

            x1,y1,x2,y2 = map(int,box.xyxy[0])
            cx = (x1+x2)//2

            if cx < 200:
                command = "L"

            elif cx > 440:
                command = "R"

            else:
                command = "C"

    ser.write((command+"\n").encode())

    cv2.imshow("frame",frame)

    if cv2.waitKey(1)==27:
        break
