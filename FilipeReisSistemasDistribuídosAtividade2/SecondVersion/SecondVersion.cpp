#include <iostream>
#include <unistd.h>
#include <vector>
#include <ctime>
#include "SecondVersion.h"
#include <boost/interprocess/ipc/message_queue.hpp>

using namespace std;
using namespace boost::interprocess;
const int COUNTERLIMIT = 10;

SecondVersion::SecondVersion( void ) {
    counter = 0;
    beginTime = 0;
    endTime = 0;
    elapsedTime = 0;
}

SecondVersion::~SecondVersion() {
    counter = 0;
    beginTime = 0;
    endTime = 0;
    elapsedTime = 0;
}

void SecondVersion::setIncrementCounter( void ) {
    this->counter += 1;
}

int SecondVersion::getIncrementedCounter( void ) {
    return this->counter;
}

void SecondVersion::setBeginTime( void ) {
    this->beginTime = time(0);
}

long int SecondVersion::getBeginTime( void ) {
    return this->beginTime;
}

void SecondVersion::setEndTime( void ) {
    this->endTime = time(0);
}

long int SecondVersion::getEndTime( void ) {
    return this->endTime;
}

void SecondVersion::setElapsedTime( void ) {
    this->elapsedTime = this->getEndTime() - this->getBeginTime();
}

long int SecondVersion::getElapsedTime( void ) {
    return this->elapsedTime;
}

void SecondVersion::threadProducer( void ) {
    this->setIncrementCounter();
}

void SecondVersion::threadConsumer( void ) {
    cout << "The counter value is: " << this->getIncrementedCounter() << " and the elapsed time is: ";
    cout << this->getElapsedTime() << " second(s)" << endl;
}

int SecondVersion::doingSender( void ) {
   try{
        //Erase previous message queue
        message_queue::remove("message_queue");

        //Create a message_queue.
        message_queue mq
         (create_only               //only create
         ,"message_queue"           //name
         ,COUNTERLIMIT              //max message number
         ,sizeof(int)               //max message size
         );
    
        this->setBeginTime();
        while( this->getIncrementedCounter() < COUNTERLIMIT ) {
            sleep(1);
            this->threadProducer();
            mq.send(&this->counter, sizeof(this->counter), 0);
        }
        this->setEndTime();
        this->setElapsedTime();
    } catch( interprocess_exception &ex ) {
        cout << ex.what() << endl;
        return 1;
    }
}

int SecondVersion::doingReceiver( void ) {
    try{
        //Open a message queue.
        message_queue mq
            (open_only        //only open
            ,"message_queue"  //name
            );

        unsigned int priority;
        message_queue::size_type recvd_size;

        //Receive numbers
        this->setBeginTime();
        for( int i = 0; i < COUNTERLIMIT; i++ ) {
            int number;
            sleep(1);
           
            mq.receive(&number, sizeof(number), recvd_size, priority);
            this->counter = number;
            this->setEndTime();
            this->setElapsedTime();
            if( number != i || recvd_size != sizeof(number) ) {
                return 1;
            }
            this->threadConsumer();
        }
        this->setEndTime();
        this->setElapsedTime();
    }
    catch(interprocess_exception &ex){
        message_queue::remove("message_queue");
        cout << ex.what() << endl;
        return 1;
    }
    message_queue::remove("message_queue");
}
