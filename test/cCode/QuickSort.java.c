// This is automatically generated by the Tiger compiler.
// Do NOT modify!

#define NULL ((void*)0)

#include <string.h>
// structures
struct QuickSort
{
  struct QuickSort_vtable *vptr;
  int isObjOrArray;
  int length;
  void *forwarding;
};
struct QS
{
  struct QS_vtable *vptr;
  int isObjOrArray;
  int length;
  void *forwarding;
  int*   number;
  int size;
};

// vtables structures
struct QuickSort_vtable
{
  char *QuickSort_gc_map;
};

struct QS_vtable
{
  char *QS_gc_map;
  int (*Start)();
  int (*Sort)();
  int (*Print)();
  int (*Init)();
};


// vtables declared
struct QuickSort_vtable QuickSort_vtable_ ;
struct QS_vtable QS_vtable_ ;

// methods
struct QS_Start_gc_frame{
  void *prev;
  char *arguments_gc_map;
  void *arguments_base_address;
  int locals_gc_map;
  struct QS * x_1;
  struct QS * x_2;
  struct QS * x_3;
  struct QS * x_4;
};
char *QS_Start_arguments_gc_map="10";
char *QS_Start_locals_gc_map="01111";
void *prev;
int QS_Start(struct QS * this, int sz)
{
  struct QS_Start_gc_frame frame;

  memset(&frame,0,sizeof(frame));
  frame.prev = prev;
  prev = &frame;
  frame.arguments_gc_map = QS_Start_arguments_gc_map;
  frame.arguments_base_address =&this;
  frame.locals_gc_map = 4;

  int aux01;

  aux01 = (frame.x_1=this, frame.x_1->vptr->Init(frame.x_1, sz));
  aux01 = (frame.x_2=this, frame.x_2->vptr->Print(frame.x_2));
  System_out_println (9999);
  aux01 = this->size - 1;
  aux01 = (frame.x_3=this, frame.x_3->vptr->Sort(frame.x_3, 0, aux01));
  aux01 = (frame.x_4=this, frame.x_4->vptr->Print(frame.x_4));
  prev=frame.prev;
  return 0;
}

struct QS_Sort_gc_frame{
  void *prev;
  char *arguments_gc_map;
  void *arguments_base_address;
  int locals_gc_map;
  struct QS * x_5;
  struct QS * x_6;
};
char *QS_Sort_arguments_gc_map="100";
char *QS_Sort_locals_gc_map="0000000011";
void *prev;
int QS_Sort(struct QS * this, int left, int right)
{
  struct QS_Sort_gc_frame frame;

  memset(&frame,0,sizeof(frame));
  frame.prev = prev;
  prev = &frame;
  frame.arguments_gc_map = QS_Sort_arguments_gc_map;
  frame.arguments_base_address =&this;
  frame.locals_gc_map = 2;

  int v;
  int i;
  int j;
  int nt;
  int t;
  int cont01;
  int cont02;
  int aux03;

  t = 0;
  if (left < right){
    v = this->number[right];
    i = left - 1;
    j = right;
    cont01 = 1;
    while (cont01)
    {
      cont02 = 1;
      while (cont02)
      {
        i = i+1;
        aux03 = this->number[i];
        if (!(aux03 < v)){
          cont02 = 0;

        }else{
          cont02 = 1;
        }
      }
      cont02 = 1;
      while (cont02)
      {
        j = j - 1;
        aux03 = this->number[j];
        if (!(v < aux03)){
          cont02 = 0;

        }else{
          cont02 = 1;
        }
      }
      t = this->number[i];
      this->number[i] = this->number[j];
      this->number[j] = t;
      if (j < i+1){
        cont01 = 0;

      }else{
        cont01 = 1;
      }
    }
    this->number[j] = this->number[i];
    this->number[i] = this->number[right];
    this->number[right] = t;
    nt = (frame.x_5=this, frame.x_5->vptr->Sort(frame.x_5, left, i - 1));
    nt = (frame.x_6=this, frame.x_6->vptr->Sort(frame.x_6, i+1, right));

  }else{
    nt = 0;
  }
  prev=frame.prev;
  return 0;
}

struct QS_Print_gc_frame{
  void *prev;
  char *arguments_gc_map;
  void *arguments_base_address;
  int locals_gc_map;
};
char *QS_Print_arguments_gc_map="1";
char *QS_Print_locals_gc_map="0";
void *prev;
int QS_Print(struct QS * this)
{
  struct QS_Print_gc_frame frame;

  memset(&frame,0,sizeof(frame));
  frame.prev = prev;
  prev = &frame;
  frame.arguments_gc_map = QS_Print_arguments_gc_map;
  frame.arguments_base_address =&this;
  frame.locals_gc_map = 0;

  int j;

  j = 0;
  while (j < this->size)
  {
    System_out_println (this->number[j]);
    j = j+1;
  }
  prev=frame.prev;
  return 0;
}

struct QS_Init_gc_frame{
  void *prev;
  char *arguments_gc_map;
  void *arguments_base_address;
  int locals_gc_map;
};
char *QS_Init_arguments_gc_map="10";
char *QS_Init_locals_gc_map="";
void *prev;
int QS_Init(struct QS * this, int sz)
{
  struct QS_Init_gc_frame frame;

  memset(&frame,0,sizeof(frame));
  frame.prev = prev;
  prev = &frame;
  frame.arguments_gc_map = QS_Init_arguments_gc_map;
  frame.arguments_base_address =&this;
  frame.locals_gc_map = 0;


  this->size = sz;
  this->number = (int *)Tiger_new_array(sz);
  this->number[0] = 20;
  this->number[1] = 7;
  this->number[2] = 12;
  this->number[3] = 18;
  this->number[4] = 2;
  this->number[5] = 11;
  this->number[6] = 6;
  this->number[7] = 9;
  this->number[8] = 19;
  this->number[9] = 5;
  prev=frame.prev;
  return 0;
}


// vtables
struct QuickSort_vtable QuickSort_vtable_ = 
{
  "",
};

struct QS_vtable QS_vtable_ = 
{
  "10",
  QS_Start,
  QS_Sort,
  QS_Print,
  QS_Init,
};


// main method
struct main_gc_frame{
  void *prev;
  char *arguments_gc_map;
  void *arguments_base_address;
  int locals_gc_map;
  struct QS * x_0;
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

  System_out_println ((frame.x_0=((struct QS*)(Tiger_new (&QS_vtable_, sizeof(struct QS)))), frame.x_0->vptr->Start(frame.x_0, 10)));

  prev=frame.prev;
}




