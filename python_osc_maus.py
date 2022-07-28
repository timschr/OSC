from pythonosc import dispatcher
from pythonosc import osc_server
from math import pi
from pynput.mouse import Controller


YOUR_IP_ADDRESS = "ENTER_YOUR_IP_ADDRESS"

sensitivity = 3 # The higher the number, the more sensitive the mouse is

mouse = Controller()

def imu_to_mouse(imu_reading,y,z,x):
    # move the mouse according to the imu_reading
    mouse.move(-(x * sensitivity), -(y*sensitivity))

if __name__ == "__main__":

    #create a dispatcher
    dispatcher = dispatcher.Dispatcher()

    #map the dispatcher to the address "/imu"
    dispatcher.map("/imu", imu_to_mouse)
    dispatcher.map("/imu", print)

    #create a server
    server = osc_server.ThreadingOSCUDPServer(
        (YOUR_IP_ADDRESS, 5005), dispatcher)

    #serve forever
    print("Serving on {}".format(server.server_address))
    server.serve_forever()
  
    

    





