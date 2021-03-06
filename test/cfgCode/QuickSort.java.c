// This is automatically generated by the Tiger compiler.
// Do NOT modify!

// Control-flow Graph

// structures
struct QuickSort
{
  struct QuickSort_vtable *vptr;
};
struct QS
{
  struct QS_vtable *vptr;
  int*  number;
  int size;
};
// vtables structures
struct QuickSort_vtable
{
};

struct QS_vtable
{
  int (*Start)();
  int (*Sort)();
  int (*Print)();
  int (*Init)();
};


// vtables declared
struct QuickSort_vtable QuickSort_vtable_ ;
struct QS_vtable QS_vtable_ ;

// methods
int QS_Start(struct QS * this, int sz)
{
  int aux01;
  struct QS * x_1;
  struct QS * x_2;
  struct QS * x_3;
  struct QS * x_4;
  int x_7;
  int x_8;
  int x_9;
  int x_10;
  int x_11;

L_0:
  x_7 = this->vptr->Init(this, sz);
  aux01 = x_7;
  x_8 = this->vptr->Print(this);
  aux01 = x_8;
  System_out_println (9999);
  x_9 = this->size - 1;
  aux01 = x_9;
  x_10 = this->vptr->Sort(this, 0, aux01);
  aux01 = x_10;
  x_11 = this->vptr->Print(this);
  aux01 = x_11;
  return 0;
}
int QS_Sort(struct QS * this, int left, int right)
{
  int v;
  int i;
  int j;
  int nt;
  int t;
  int cont01;
  int cont02;
  int aux03;
  struct QS * x_5;
  struct QS * x_6;
  int x_12;
  int x_13;
  int x_14;
  int x_15;
  int x_16;
  int x_17;
  int x_18;
  int x_19;
  int x_20;
  int x_21;
  int x_22;
  int x_23;
  int x_24;
  int x_25;
  int x_26;
  int x_27;
  int x_28;
  int x_29;
  int x_30;
  int x_31;
  int x_32;

L_1:
  t = 0;
  x_12 = left < right;
  if (x_12)
    goto L_2;
  else
    goto L_3;
L_3:
  nt = 0;
  goto L_4;
L_2:
  x_13 = this->number[right];
  v = x_13;
  x_14 = left - 1;
  i = x_14;
  j = right;
  cont01 = 1;
  goto L_5;
L_5:
  if (cont01)
    goto L_6;
  else
    goto L_7;
L_6:
  cont02 = 1;
  goto L_8;
L_8:
  if (cont02)
    goto L_9;
  else
    goto L_10;
L_9:
  x_15 = i + 1;
  i = x_15;
  x_16 = this->number[i];
  aux03 = x_16;
  x_18 = aux03 < v;
  x_17 = !(x_18);
  if (x_17)
    goto L_11;
  else
    goto L_12;
L_12:
  cont02 = 1;
  goto L_13;
L_11:
  cont02 = 0;
  goto L_13;
L_13:

  goto L_8;
L_10:
  cont02 = 1;
  goto L_14;
L_14:
  if (cont02)
    goto L_15;
  else
    goto L_16;
L_15:
  x_19 = j - 1;
  j = x_19;
  x_20 = this->number[j];
  aux03 = x_20;
  x_22 = v < aux03;
  x_21 = !(x_22);
  if (x_21)
    goto L_17;
  else
    goto L_18;
L_18:
  cont02 = 1;
  goto L_19;
L_17:
  cont02 = 0;
  goto L_19;
L_19:

  goto L_14;
L_16:
  x_23 = this->number[i];
  t = x_23;
  x_24 = this->number[j];
  this->number[i] = x_24;
  this->number[j] = t;
  x_26 = i + 1;
  x_25 = j < x_26;
  if (x_25)
    goto L_20;
  else
    goto L_21;
L_21:
  cont01 = 1;
  goto L_22;
L_20:
  cont01 = 0;
  goto L_22;
L_22:

  goto L_5;
L_7:
  x_27 = this->number[i];
  this->number[j] = x_27;
  x_28 = this->number[right];
  this->number[i] = x_28;
  this->number[right] = t;
  x_30 = i - 1;
  x_29 = this->vptr->Sort(this, left, x_30);
  nt = x_29;
  x_32 = i + 1;
  x_31 = this->vptr->Sort(this, x_32, right);
  nt = x_31;

  goto L_4;
L_4:
  return 0;
}
int QS_Print(struct QS * this)
{
  int j;
  int x_33;
  int x_34;
  int x_35;

L_23:
  j = 0;
  goto L_24;
L_24:
  x_33 = j < this->size;
  if (x_33)
    goto L_25;
  else
    goto L_26;
L_25:
  x_34 = this->number[j];
  System_out_println (x_34);
  x_35 = j + 1;
  j = x_35;

  goto L_24;
L_26:
  return 0;
}
int QS_Init(struct QS * this, int sz)
{
  int*  x_36;

L_27:
  this->size = sz;
  x_36 = (int *)Tiger_new_array(sz);
  this->number = x_36;
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
  return 0;
}

// vtables
struct QuickSort_vtable QuickSort_vtable_ = 
{
};

struct QS_vtable QS_vtable_ = 
{
  QS_Start,
  QS_Sort,
  QS_Print,
  QS_Init,
};


// main method
int Tiger_main ()
{
  struct QS * x_0;
  int x_37;
  struct QS * x_38;

L_28:
  x_38 = ((struct QS*)(Tiger_new (&QS_vtable_, sizeof(struct QS))));
  x_37 = x_38->vptr->Start(x_38, 10);
  System_out_println (x_37);
  return 0;
}




void *prev;
