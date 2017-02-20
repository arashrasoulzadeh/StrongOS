const int HIGH=2,MED=1,LOW=0;//speed of delays for each iteration


class Task{
public:
  int id,counter,type;
  typedef void (*func)();
  func job;
  Task(func _job,int _type=1)
  {
    job=_job;
    type=_type;
  }
  Task(){}
};
Task *tasks=new Task[0];
int c=-1,total=-1;

class Strong{
public:
  int lastid=-1;
  /*
    boot operating system
    parms = SPEED(int)
  */
  void boot(int SPEED)
  {

  }
  /*
    process next command
  */
  void tick()
  {
    c>=total ? c=0:c++;
    //printf("running task %i\n",c);
    Task *t= &tasks[c];
    //if (t>0)
      t->job();
  }
  /*
    process next command
  */
  void scheduleJob(Task job)
  {
    lastid++;
    Task *temp=new Task[255];
    for (int i=0;i<lastid-1;i++)
    {
      temp[i]=tasks[i];
    }
    tasks=temp;
    tasks[lastid]=job;
    tasks[lastid].id=lastid;
    total++;
    delete [] temp;
  }
  Strong(){}
};
