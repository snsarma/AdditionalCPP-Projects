/**
 * Time.h
 * For use with 4003-703-01, Homework 2
 * Winter 2012
 * Department of Computer Science
 * Rochester Institute of Technology
 * Author: Travis Brown
 */
#ifndef __TIME_H__
#define __TIME_H__

#include <string>

/**
 * This class manages time and the additional and subtraction of time values.
 */
class Time
{
   public:
      /** 
       * Default constructor. Time is set to 0 
       */
      Time();

      /**
       * Time constructor that takes a string that represents time in the
       * format hh:mm
       * @param time Time in the format hh:mm
       */
      Time( std::string time );

      /**
       * Time constructor that takes elapsed number of seconds since the epoch
       * @param seconds the number of seconds since the epoch
       */
      Time( int seconds );

      /**
       * Add one time to another. The original is modified with the updated
       * value and returned
       * @param t Time to add to self
       * @return current time plus the new time
       */
      Time add( Time t );

      /**
       * Subtract one time from another. The original is modified with the
       * updated value and returned
       * @param t Time to subtract from self
       * @return current time minus the new time
       */
      Time subtract( Time t );

      /**
       * Set the time to a string specified by hh:mm since the epoch
       * @param time new time value in the format hh:mm since the epoch
       */
      void setTime( std::string time );

      /**
       * Return a string version of the time in the format hh:mm
       * @return string representation of the time in hh:mm since the epoch
       */
      std::string str() const;

   private:
      /**
       * Number of seconds since the epoch
       */
      int seconds;

};

#endif // __TIME_H_HH
