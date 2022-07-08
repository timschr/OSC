from pythonosc import dispatcher
from pythonosc import osc_server
from math import pi
from pynput.mouse import Button, Controller

mouse = Controller()
sensitivity = 3
def imu_to_mouse(imu_reading,y,z,x):
    #if (x,y) > (0.5,0.5):
        mouse.move(-(x * sensitivity), -(y*sensitivity))

if __name__ == "__main__":
  #create a dispatcher
    dispatcher = dispatcher.Dispatcher()
    #map the dispatcher to the address "/imu"
    dispatcher.map("/imu", imu_to_mouse)
    dispatcher.map("/imu", print)
    #create a server
    server = osc_server.ThreadingOSCUDPServer(
        ("192.168.178.21", 5005), dispatcher)
    #serve forever
    print("Serving on {}".format(server.server_address))
    server.serve_forever()




