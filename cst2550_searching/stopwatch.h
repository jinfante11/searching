#ifndef _STOPWATCH_H
#define _STOPWATCH_H

#include<ctime>
class Stopwatch{

 private:
  clock_t starttime;
 public:
  void start();
  double stop();

};

#endif
