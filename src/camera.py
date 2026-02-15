import cv2
import sys
import time
import os


if sys.platform == "win32":
    import msvcrt
    msvcrt.setmode(sys.stdout.fileno(), os.O_BINARY)

cap = cv2.VideoCapture(0)
if not cap.isOpened():
    sys.stderr.write("Cannot open camera")
    sys.exit(1)

cap.set(cv2.CAP_PROP_FRAME_WIDTH, 320)
cap.set(cv2.CAP_PROP_FRAME_HEIGHT, 240)
width = 320
height = 240
channels = 3


fps = 60
frame_time = 1.0 / fps

while True:
    start = time.time()
    ret, frame = cap.read()

    #Flips frame horisontally
    frame = cv2.flip(frame,1)
    
    # 1. Check if the frame exists BEFORE processing it
    if not ret or frame is None:
        sys.stderr.write("Failed to get frame\n")
        break
        
    # 2. Resize and convert to bytes
    frame = cv2.resize(frame, (width, height))
    data = frame.tobytes()
    
    # 3. Write and flush the BINARY buffer specifically
    sys.stdout.buffer.write(data)
    sys.stdout.buffer.flush() 
    
    # Timing logic
    elapsed = time.time() - start
    sleep_time = frame_time - elapsed
    if sleep_time > 0:
        time.sleep(sleep_time)
