#include <iostream>
#include <pthread.h>
using namespace std;

void *thread_func(void *arg)
{
  int *val = (int *) arg;
  for(int i = 0; i < 10; i++)
    (*val)++;
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
  int *ret = NULL;
  pthread_join(thread_id, (void **) &ret);
  cout << *ret << endl;
  return 0;
}
