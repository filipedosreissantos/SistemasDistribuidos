/*First Version*/
//Compiling the first Version
g++ FirstVersion.h FirstVersion.cpp mainFirstVersion.cpp -o mainFirstVersion

//After compiled
./mainFirstVersion

---------------------------------------------------------------------------------------------------------

/*Second Version*/
//Compiling the first process
g++ SecondVersion.h SecondVersion.cpp mainSender.cpp -o mainSender -lpthread -lrt

//After compiled
./mainSender

//Compiling the second process
g++ SecondVersion.h SecondVersion.cpp mainReceiver.cpp -o mainReceiver -lpthread -lrt

//After compiled
./mainReceiver