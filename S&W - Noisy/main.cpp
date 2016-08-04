/**
Check Sum error not treated

*/


#include <iostream>
using namespace std;
#include <cstring>

/* For using ::   srand(time(NULL));   */
#include <stdlib.h>
#include <time.h>

/* Contains the definition of packet, frame, etc.*/
#include "protocol.h"

/***************************** #define's *****************************/

/* sequence number is of 1 bit - can have values 0 and 1 */
#define MAX_SEQ 1

/* incrementing sequence number in circular manner */
#define inc(k) if(k<MAX_SEQ) k++; else k=0;

/* number of seconds to wait before timeout */
#define TIMEOUT 5

/* total number of packets to send */
#define TOT_PACKETS 7


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

void sender3();
void receiver3();

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

    cout<<"\n*********** STOP and WAIT for NOISY Channel Simulation *********\n";
    cout<<"\n\nCONNECTED . . . . \n\n";
    while(!DISCONNECT)
    {
        sender3();
        delay(300);
        receiver3();
    }
    cout<<"\n\nDISCONNECTED . . . .  \n\n";

    return 0;
}

/*************************** Function definitions ***************************/

/* Sender function - sends a frame and waits for acknowledgement */
void sender3()
{
    static int next_frame_to_send=0;
    static frame s;
    packet buffer;
    event_type event;
    static bool isFirstTime=true;

    if(isFirstTime)
    {
        // code for first time
        from_network_layer(buffer);
        s.info = buffer;
        s.seq = next_frame_to_send;
        cout<<"SENDER : Info = "<<s.info.data<<"\t\tSeq No = "<<s.seq;
        turn = 'r';
        to_physical_layer(s);
        isFirstTime=false;
    }
    wait_for_event_sender(event);

    if(turn=='s')
    {
        if(event==frame_arrival)
        {
            from_network_layer(buffer);
            inc(next_frame_to_send);
            s.info = buffer;
            s.seq = next_frame_to_send;
            cout<<"SENDER : Info = "<<s.info.data<<"\t\tSeq No = "<<s.seq;
            turn = 'r';
            to_physical_layer(s);
        }
        if(event==timeout)
        {
            cout<<"SENDER : Resending Frame\t\t";
            turn = 'r';
            to_physical_layer(s);
        }
    }
}

/* Receiver function - receives a frame and sends the acknowledgement */
void receiver3()
{
    static unsigned int frame_expected=0;
    frame r,s;
    event_type event;

    wait_for_event_reciever(event);

    if(turn=='r')
    {
        if(event==frame_arrival)
        {
            from_physical_layer(r);
            if(r.seq==frame_expected)
            {
                to_network_layer(r.info);
                inc(frame_expected);
            }
            else
            {
                // acknowledgement received case
                cout<<"\tRECIEVER : Acknowledgement Resent\n";
            }
            turn = 's';
            to_physical_layer(s);
        }
        if(event==err)
        {
            cout<<"\tRECIEVER : Garbled Frame\n";
            turn = 's';       // if frame is not received correctly, sender should resend the frame
        }
        if(event==chksum_err)
        {
            cout<<"\tRECIEVER : Checksum error\n";
            turn = 's';       // if frame is not received correctly, sender should resend the frame
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
    buffer.error_in_frame= rand()%5;
    /*  0 means error
        1 means check sum error
        2 , 3, 4 means no error
    */
    globalFrame= buffer;
}

/* Deliver information from an inbound frame to the network layer. */
void to_network_layer(packet &buffer)
{
    cout<<"\tRECIEVER : Packet with data "<<buffer.data<<" recieved , Ack Sent\n";

    i++;
    if(i>TOT_PACKETS)          //if all packets recieved then disconnect
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
    static int timer=0;
    if(turn=='s')
    {
        timer++;
        if(timer==TIMEOUT)
        {
            e = timeout;
            cout<<"\nSENDER : Ack not received  =>   TIMEOUT\n";
            timer = 0;
        }
        else if(globalFrame.error_in_frame==0)
        {
            e = err;
        }
        else if(globalFrame.error_in_frame==1)
        {
            e = chksum_err;
        }
        else
        {
            timer = 0;
            e = frame_arrival;
        }
    }
}

/* RECEIEVR calls - Wait for an event to happen; return its type in event. */
void wait_for_event_reciever(event_type &e)
{
    if(turn=='r')
    {
        if(globalFrame.error_in_frame==0)
        {
            e = err;
        }
        else if(globalFrame.error_in_frame==1)
        {
            e = chksum_err;
        }
        else
        {
            e = frame_arrival;
        }
    }
}
