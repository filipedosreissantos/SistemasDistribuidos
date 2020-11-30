#include <iostream>
#include <unistd.h>
#include <ctime>
#include "FirstVersion.h"
using namespace std;
const int COUNTERLIMIT = 10;

FirstVersion::FirstVersion( void ) {
    counter = 0;
    beginTime = 0;
    endTime = 0;
    elapsedTime = 0;
}

FirstVersion::~FirstVersion() {
    counter = 0;
    beginTime = 0;
    endTime = 0;
    elapsedTime = 0; 
}

void FirstVersion::setIncrementCounter( void ) {
    this->counter += 1;
}

int FirstVersion::getIncrementedCounter( void ) {
    return this->counter;
}

void FirstVersion::setBeginTime( void ) {
    this->beginTime = time(0);
}

long int FirstVersion::getBeginTime( void ) {
    return this->beginTime;
}

void FirstVersion::setEndTime( void ) {
    this->endTime = time(0);
}

long int FirstVersion::getEndTime( void ) {
    return this->endTime;
}

void FirstVersion::setElapsedTime( void ) {
    this->elapsedTime = this->getEndTime() - this->getBeginTime();
}

long int FirstVersion::getElapsedTime( void ) {
    return this->elapsedTime;
}

void FirstVersion::threadProducer( void ) {
    this->setIncrementCounter();
}

void FirstVersion::threadConsumer( void ) {
    cout << "The counter value is: " << this->getIncrementedCounter() << " and the elapsed time is: ";
    cout << this->getElapsedTime() << " second(s)" << endl;
}

void FirstVersion::doing( void ) {

    this->setBeginTime();
    while( this->getIncrementedCounter() < COUNTERLIMIT ) {
        sleep(1);
        this->threadProducer();

        this->setEndTime();
        this->setElapsedTime();
        this->getElapsedTime();
        this->threadConsumer();
    }

    this->setEndTime();
    this->setElapsedTime();
    this->getElapsedTime();
    cout << "After all execution we have as follow:" << endl;
    this->threadConsumer();

}
