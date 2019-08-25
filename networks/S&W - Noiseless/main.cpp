#include <iostream>
using namespace std;
#include <cstring>

/* For using ::   srand(time(NULL));   */
#include <stdlib.h>
#include <time.h>

/* Contains the definition of packet, frame, etc.*/
#include "protocol.h"

/* total number of packets to send */
#define TOT_PACKETS 5


/*************************** Global variables ***************************/

/* starting data to be sent by sender*/
int i=1;

/* can have values {s, r} for sender's turn and receiver's turn respectively */
char turn;
/* Disconnect set to '0'  to start the loop */
int DISCONNECT=0;
/* Global frame treated as buffer*/
frame globalFrame;

/*************************** Function prototypes ***************************/

void sender2();
void receiver2();

void from_network_layer(packet&);
void to_network_layer(packet&);

void from_physical_layer(frame&);
void to_physical_layer(frame&);

void wait_for_event_sender(event_type&);
void wait_for_event_reciever(event_type&);

/*************************** Main function  ***************************/

/* for delay effect */
void delay(unsigned int mseconds)
{
    clock_t goal = mseconds + clock();
    while (goal > clock());
}

int main()
{
    /* random no' generator , generating new random no's . Used as int x=rand()%4; */
    srand(time(NULL));

    cout<<"\n*********** STOP and WAIT for NOISELESS Channel Simulation *********\n";
    cout<<"\n\nCONNECTED . . . . \n\n";
    while(!DISCONNECT)
    {
        sender2();
        delay(300);
        receiver2();
    }
    cout<<"\n\nDISCONNECTED . . . .  \n\n";

    return 0;
}

/*************************** Function definitions ***************************/

/* Sender function - sends a frame and waits for acknowledgement */
void sender2()
{
    static frame s;
    packet buffer;
    event_type event;
    static bool isFirstTime=true;

    if(isFirstTime)
    {
        // code for first time
        from_network_layer(buffer);
        s.info = buffer;
        cout<<"SENDER : Info = "<<s.info.data<<"\t\t         ";
        turn = 'r';
        to_physical_layer(s);
        isFirstTime=false;
    }
    wait_for_event_sender(event);

    if(turn=='s')
    {
       // event will always be .. frame_arrival
         if(event==frame_arrival){
           from_network_layer(buffer);
            s.info = buffer;
            cout<<"SENDER : Info = "<<s.info.data<<"\t\t         ";
        turn = 'r';
            to_physical_layer(s);
        }
}}

/* Receiver function - receives a frame and sends the acknowledgement */
void receiver2()
{
    frame r,s;
    event_type event;

    wait_for_event_reciever(event);

    if(turn=='r')
    {
        // event will always be .. frame_arrival
        if(event==frame_arrival){
            from_physical_layer(r);
                to_network_layer(r.info);
            turn = 's';
            to_physical_layer(s);
        }
    }
    }



/* Fetch a packet from the network layer for transmission on the channel */
void from_network_layer(packet &buffer)
{
    strcpy(buffer.data,"My Data");
}

/* Pass the frame to the physical layer for transmission. */
void to_physical_layer(frame &buffer)
{
    globalFrame= buffer;
}

/* Deliver information from an inbound frame to the network layer. */
void to_network_layer(packet &buffer)
{
    cout<<"\tRECIEVER : Packet with data "<<buffer.data<<" recieved , Ack Sent\n";

    i++;
    if(i>TOT_PACKETS)          //if all packets received then disconnect
    {
        DISCONNECT = 1;
    }

}

/* Go get an inbound frame from the physical layer and copy it to r. */
void from_physical_layer(frame &buffer)
{
    buffer=globalFrame;
}

/* SENDER calls - Wait for an event to happen; return its type in event. */
void wait_for_event_sender(event_type &e)
{
    if(turn=='s')
    {
            e = frame_arrival;
        }
}

/* RECEIEVR calls - Wait for an event to happen; return its type in event. */
void wait_for_event_reciever(event_type &e)
{
    if(turn=='r')
    {
        e = frame_arrival;
    }
}
