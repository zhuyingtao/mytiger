// This is automatically generated by the Tiger compiler.
// Do NOT modify!

#define NULL ((void*)0)

#include <string.h>
// structures
struct DeadCode
{
  struct DeadCode_vtable *vptr;
  int isObjOrArray;
  int length;
  void *forwarding;
};
struct Doit
{
  struct Doit_vtable *vptr;
  int isObjOrArray;
  int length;
  void *forwarding;
};

// vtables structures
struct DeadCode_vtable
{
  char *DeadCode_gc_map;
};

struct Doit_vtable
{
  char *Doit_gc_map;
  int (*doit)();
};


// vtables declared
struct DeadCode_vtable DeadCode_vtable_ ;
struct Doit_vtable Doit_vtable_ ;

// methods
struct Doit_doit_gc_frame{
  void *prev;
  char *arguments_gc_map;
  void *arguments_base_address;
  int locals_gc_map;
};
char *Doit_doit_arguments_gc_map="1";
char *Doit_doit_locals_gc_map="";
void *prev;
int Doit_doit(struct Doit * this)
{
  struct Doit_doit_gc_frame frame;

  memset(&frame,0,sizeof(frame));
  frame.prev = prev;
  prev = &frame;
  frame.arguments_gc_map = Doit_doit_arguments_gc_map;
  frame.arguments_base_address =&this;
  frame.locals_gc_map = 0;


  if ((frame.x_0=((struct Doit*)(Tiger_new (&Doit_vtable_, sizeof(struct Doit)))), frame.x_0->vptr->doit(frame.x_0))){
    System_out_println (1);

  }else{
    System_out_println (1);
  }
  prev=frame.prev;
  return 0;
}


// vtables
struct DeadCode_vtable DeadCode_vtable_ = 
{
  "",
};

struct Doit_vtable Doit_vtable_ = 
{
  "",
  Doit_doit,
};


// main method
struct main_gc_frame{
  void *prev;
  char *arguments_gc_map;
  void *arguments_base_address;
  int locals_gc_map;
  struct Doit * x_0;
};
void *prev;
int Tiger_main ()
{
  struct  main_gc_frame frame;

  frame.prev = prev;
  prev = &frame;
  frame.arguments_gc_map = NULL;
  frame.arguments_base_address = 0;
  frame.locals_gc_map = 1;

  System_out_println ((frame.x_0=((struct Doit*)(Tiger_new (&Doit_vtable_, sizeof(struct Doit)))), frame.x_0->vptr->doit(frame.x_0)));

  prev=frame.prev;
}




