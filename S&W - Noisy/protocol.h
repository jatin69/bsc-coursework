#ifndef PROTOCOL_H_INCLUDED
#define PROTOCOL_H_INCLUDED

/* max size of data is 1024 bits -> 1 byte */
#define MAX_PKT 1024

/* Event type can have 4 values : frame arrival , error, timeout , no event
   It is the standard way of declaring a 'enum' .
*/
enum event_type {frame_arrival, err, chksum_err, timeout, no_event} ;

/* A Frame can be one of the two : data frame , acknowledgement frame
   As given in Book - declaring of a 'enum' .
*/
typedef enum {data, ack } frame_kind ;

/* sequence number - seq_nr */
typedef unsigned int seq_nr;

/* a structure packet - with char data */
typedef struct
{
    char data[MAX_PKT];
} packet;

/* a structure frame - with frame kind, info, sequence no, acknowledgement no,  */
typedef struct
{
    frame_kind kind;
    packet info;
    seq_nr seq;
    seq_nr ack;
    int error_in_frame;
} frame;

#endif // PROTOCOL_H_INCLUDED
