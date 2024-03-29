#include "kernel.h"

Strong os;

void hello(){printf("%s\n","hello world" );}
void howudoing()  {printf("%s\n","how u doing" );}
void bye()  {printf("%s\n","bye world" );}

int main()
{
  os.boot(HIGH);
  int times=100;


  Task::func hellofunc = &hello;
  Task func_hello (hellofunc);
  os.scheduleJob(func_hello);

  Task::func howudoingfunc = &howudoing;
  Task func_howudoing (howudoingfunc);
  os.scheduleJob(func_howudoing);

  Task::func byefunc = &bye;
  Task func_bye (byefunc);
  os.scheduleJob(func_bye);



  while (times>0)
  {
    os.tick();
    times--;
  }
}
