const int HIGH=2,MED=1,LOW=0;//speed of delays for each iteration


class Task{
public:
  int id;
  typedef void (*func)();
  func job;
  int counter;
  int type;
  Task(func _job,int _type=1)
  {
    job=_job;
    type=_type;
    //tasks+=this;
  }
  Task()
  {

  }
};
Task *tasks=new Task[0];
int c=-1;
int total=0;

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
    if (c>=total){
      c=0;
    }else{
      c++;
    }
    //printf("running task %i\n",tasks[c].id);
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
    Task *temp=new Task[lastid];
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
  Strong()
  {

  }
};
