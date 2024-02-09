#include<ctime>
#include"stopwatch.h"
void Stopwatch::start(){
  this->starttime=clock();

}
double Stopwatch::stop(){
  clock_t end = clock();
  double duration_in_seconds= static_cast<double> (end-this->starttime)/CLOCKS_PER_SEC;
  return duration_in_seconds;
}
