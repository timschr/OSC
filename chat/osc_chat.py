from pythonosc import dispatcher
from pythonosc import osc_server

def print_msg(msg):
    print(msg)

if __name__ == "__main__":
  #create a dispatcher
    dispatcher = dispatcher.Dispatcher()
    #map the dispatcher to the address "/imu"
    #dispatcher.map("/chat", print_msg)
    dispatcher.map("/chat", print)
    #create a server
    server = osc_server.ThreadingOSCUDPServer(
        ("192.168.178.21", 5005), dispatcher)
    #serve forever
    print("Serving on {}".format(server.server_address))
    server.serve_forever()
    # write a osc chat program
    