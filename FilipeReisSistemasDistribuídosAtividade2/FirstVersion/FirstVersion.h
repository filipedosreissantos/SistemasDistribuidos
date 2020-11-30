#ifndef FIRSTVERSION_H
#define FIRSTVERSION_H

class FirstVersion{
    public:

    FirstVersion( void );
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
    void doing( void );
    ~FirstVersion();

    private:
    int counter;
    long int beginTime, endTime, elapsedTime;
};
#endif
