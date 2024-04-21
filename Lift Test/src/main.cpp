#include <avr/io.h>
#include <util/delay.h>
#include "main.h"

#define DLY 100
#define FLOOR1CALL ~PIND & (1 << 3)
#define FLOOR2CALL ~PIND & (1 << 5)
#define FLOOR3CALL ~PIND & (1 << 7)
#define FLOOR4CALL ~PINB & (1 << 3)
#define SENSOR1 ~PIND & (1 << 2)
#define SENSOR2 ~PIND & (1 << 4)
#define SENSOR3 ~PIND & (1 << 6)
#define SENSOR4 ~PINB & (1 << 2)

int liftUP();
int liftUPstop();
int liftDOWN();
int liftDOWNstop();
int floor1Go();
int floor2Go();
int floor3Go();
int floor4Go();

int main(void)
{

  DDRB = 0b0000011;
  PORTB = 0b0001100;
  DDRD = 0b00000000;
  PORTD = 0b11111100;

  while (1)
  {
    if (FLOOR1CALL)
    {
      _delay_ms(DLY); // btn debounce
      while (FLOOR1CALL)
      {
        floor1Go();
      }
    }
    else if (FLOOR2CALL)
    {
      _delay_ms(DLY); // btn debounce
      while (FLOOR2CALL)
      {
        floor2Go();
      }
    }
    else if (FLOOR3CALL)
    {
      _delay_ms(DLY); // btn debounce
      while (FLOOR3CALL)
      {
        floor3Go();
      }
    }
    else if (FLOOR4CALL)
    {
      _delay_ms(DLY); // btn debounce
      while (FLOOR4CALL)
      {
        floor4Go();
      }
    }
  }
}

// put function definitions here:
int liftUP()
{
  PORTB |= (1 << 0);
  _delay_ms(DLY);
  
  return 0;
}

int liftUPstop()
{
  PORTB &= ~(1 << 0);
  _delay_ms(DLY);
  return 0;
}

int liftDOWN()
{
  PORTB |= (1 << 1);
  _delay_ms(DLY);
  
  return 0;
}

int liftDOWNstop()
{
  PORTB &= ~(1 << 1);
  _delay_ms(DLY);
  return 0;
}

int floor1Go()
{
  if (!(SENSOR1))
  {
    while (!(SENSOR1))
    {
      liftDOWN();
      _delay_ms(DLY);
      if (SENSOR1)
        liftDOWNstop();
    }
  }
  return 0;
}

int floor2Go()
{
  if (SENSOR3 || SENSOR4)
  {
    while (!(SENSOR2))
    {
      liftDOWN();
      _delay_ms(DLY);
      if (SENSOR2)
        liftDOWNstop();
    }
  }
  else if (SENSOR1)
  {
    while (!(SENSOR2))
    {
      liftUP();
      _delay_ms(DLY);
      if (SENSOR2)
        liftUPstop();
    }
  }

  return 0;
}

int floor3Go()
{
  if (SENSOR1 || SENSOR2)
  {
    while (!(SENSOR3))
    {
      _delay_ms(DLY);
      liftUP();
      if (SENSOR3)
        liftUPstop();
    }
  }
  else if (SENSOR4)
  {
    while (!(SENSOR3))
    {
      liftDOWN();
      _delay_ms(DLY);
      if (SENSOR3)
        liftDOWNstop();
    }
  }
  return 0;
}

int floor4Go()
{
  if (SENSOR1 || SENSOR2 || SENSOR3)
  {
    while (!(SENSOR4))
    {
      _delay_ms(DLY);
      liftUP();
      if (SENSOR4)
        liftUPstop();
    }
  }

  return 0;
}

