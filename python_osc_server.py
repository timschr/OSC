from pythonosc import dispatcher
from pythonosc import osc_server

YOUR_IP_ADDRESS = "ENTER_YOUR_IP_ADDRESS"

if __name__ == "__main__":

    #create a dispatcher
    dispatcher = dispatcher.Dispatcher()

    #map the dispatcher to the address "/imu"
    dispatcher.map("/chat", print)

    #create a server
    server = osc_server.ThreadingOSCUDPServer(
        (YOUR_IP_ADDRESS, 5005), dispatcher)

    #serve forever
    print("Serving on {}".format(server.server_address))
    server.serve_forever()
    