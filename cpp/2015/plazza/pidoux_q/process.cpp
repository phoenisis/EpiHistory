#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>
#include "process.hh"

Process::Process(void *(*task)(void *))
{
  this->task = task;
}

Process::~Process()
{}

void Process::begin(void *arg)
{
  pid_t	pid = fork();

  this->pid = pid;
  if (pid != 0)
    this->task(arg);
}

void Process::plop()
{
  if (this->pid != 0)
    wait(NULL); // a remplacer par waitpid()
}
