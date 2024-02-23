// include guards
#ifndef VUMETER_IMPL_H
#define VUMETER_IMPL_H

#include "miosix.h"
//#include <vector> // allows to create vector of classes

// not needed here, just for reference
typedef Gpio<GPIOA_BASE, 13> led1;
typedef Gpio<GPIOA_BASE, 12> led2;
typedef Gpio<GPIOA_BASE, 11> led3;
typedef Gpio<GPIOA_BASE, 10> led4;
typedef Gpio<GPIOA_BASE, 9> led5;
typedef Gpio<GPIOA_BASE, 8> led6;

// inside main, initialization 
/*Vumeter vumeter(led1::getPin(),led2::getPin(),led3::getPin(),
                     led4::getPin(),led5::getPin(),led6::getPin());*/

// a namespace for all the related constants
namespace VUCONST{
    const uint8_t NUM_LEDS = 6;
    const int MAX_LEVEL = 1024;
    const int MIN_LEVEL = 0;
}


//vector<Gpio> leds; // a vector size can be changed dinamically, array = fixed

class Vumeter // fixed @6 leds
{
public:
    // constructor (init) + adjust levels + clear all

    /**
     * Constructor, initializes the vumeter
     * \param Rled1 a Gpio class specifying the GPIO connected to the Rled1
     * \param Rled2 a Gpio class specifying the GPIO connected to the Rled2
     * \param Yled1 a Gpio class specifying the GPIO connected to the Yled1
     * \param Yled2 a Gpio class specifying the GPIO connected to the Yled2
     * \param Gled1 a Gpio class specifying the GPIO connected to the Gled1
     * \param Gled2 a Gpio class specifying the GPIO connected to the Gled2
     */
    Vumeter(GpioPin Rled1, GpioPin Rled2, GpioPin Yled1, GpioPin Yled2, GpioPin Gled1, GpioPin Gled2);
    
    /**
     * turn off all the leds
     */
    void clear();

private:
    // destructor
    GpioPin R1, R2, Y1, Y2, G1, G2; // all the pins needed for the class

}

// here the definition of the contructor
Vumeter::Vumeter(GpioPin Rled1, GpioPin Rled2, GpioPin Yled1, GpioPin Yled2, GpioPin Gled1, GpioPin Gled2) 
: R1(Rled1), R2(Rled2), Y1(Yled1), Y2(Yled2), G1(Gled1), G2(Gled2) //assign passed parameters to class variables
{
    R1.mode(Mode::OUTPUT);
    R2.mode(Mode::OUTPUT);
    Y1.mode(Mode::OUTPUT);
    Y2.mode(Mode::OUTPUT);
    G1.mode(Mode::OUTPUT);
    G2.mode(Mode::OUTPUT);
}

//definition of clear()
void Vumeter::clear(){
    R1.low();
    R2.low();
    Y1.low();
    Y2.low();
    G1.low();
    G2.low();
}


#endif //VUMETER_IMPL_H