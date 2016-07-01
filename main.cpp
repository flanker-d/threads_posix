#include <iostream>
#include <pthread.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>
using namespace std;

void *thread_func(void *arg)
{
  int *val = (int *) arg;
  for(int i = 0; i < 10; i++)
  {
    usleep(3000000);
    (*val)++;
    cout << "wait ... " << i << endl;
  }
  return val;
}

int main(int argc, char *argv[])
{
  pthread_t thread_id;
  int val = 0;
  int res = pthread_create(&thread_id, NULL, thread_func, &val);
  if(res < 0)
  {
    cerr << "thread create fail" << endl;
    return -1;
  }
  pid_t pid = getpid();
  FILE *fp = fopen("/home/box/main.pid", "w");
  if(fp != NULL)
  {
    fprintf(fp, "%d", (int) pid);
    fclose(fp);
  }
  int *ret = NULL;
  pthread_join(thread_id, (void **) &ret);
  cout << *ret << endl;
  return 0;
}
