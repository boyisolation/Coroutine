#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<ucontext.h>

void fun(void)
{
  printf("fun()\n");
}

int main(void)
{
  int i=1;
  char *stack=(char*)malloc(sizeof(char)*8192);
  ucontext_t ctx_main,ctx_fun;

  getcontext(&ctx_main);
  getcontext(&ctx_fun);//先获取 再部分改造
  printf("i=%d\n",i++);
  sleep(1);

  ctx_fun.uc_stack.ss_sp=stack;
  ctx_fun.uc_stack.ss_size=8192;
  ctx_fun.uc_stack.ss_flags=0;
  //ctx_fun.uc_link=NULL;
  ctx_fun.uc_link=&ctx_main;

  makecontext(&ctx_fun,fun,0);//ctx_fun上下文对应的函数是fun

  setcontext(&ctx_fun);

  printf("main exit\n");
}
