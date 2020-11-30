#ifndef SECONDVERSION_H
#define SECONDVERSION_H

class SecondVersion{
    public:

    SecondVersion( void );
    ~SecondVersion();
    void setIncrementCounter( void );
    int getIncrementedCounter( void );
    void setBeginTime( void );
    long int getBeginTime( void );
    void setEndTime( void );
    long int getEndTime( void );
    void setElapsedTime( void );
    long int getElapsedTime( void );
    void threadProducer( void );
    void threadConsumer( void );
    int doingSender( void );
    int doingReceiver( void );
    
    
    private:
    int counter;
    long int beginTime, endTime, elapsedTime;
};
#endif
