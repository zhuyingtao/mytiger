; This is automatically generated by the Tiger compiler.
; Do NOT modify!

.class public LS
.super java/lang/Object

.field public number [I
.field public size I
.method public <init>()V
    aload 0
    invokespecial java/lang/Object/<init>()V
    return
.end method


.method public Start(I)I
.limit stack 4096
.limit locals 5
    aload 0
    iload 1
    invokevirtual LS/Init(I)I
    istore 2
    aload 0
    invokevirtual LS/Print()I
    istore 3
    ldc 9999
    getstatic java/lang/System/out Ljava/io/PrintStream;
    swap
    invokevirtual java/io/PrintStream/println(I)V
    aload 0
    ldc 8
    invokevirtual LS/Search(I)I
    getstatic java/lang/System/out Ljava/io/PrintStream;
    swap
    invokevirtual java/io/PrintStream/println(I)V
    aload 0
    ldc 12
    invokevirtual LS/Search(I)I
    getstatic java/lang/System/out Ljava/io/PrintStream;
    swap
    invokevirtual java/io/PrintStream/println(I)V
    aload 0
    ldc 17
    invokevirtual LS/Search(I)I
    getstatic java/lang/System/out Ljava/io/PrintStream;
    swap
    invokevirtual java/io/PrintStream/println(I)V
    aload 0
    ldc 50
    invokevirtual LS/Search(I)I
    getstatic java/lang/System/out Ljava/io/PrintStream;
    swap
    invokevirtual java/io/PrintStream/println(I)V
    ldc 55
    ireturn
.end method
.method public Print()I
.limit stack 4096
.limit locals 3
    ldc 1
    istore 1
L_1:
    iload 1
    aload 0
    getfield LS/size I
    if_icmplt L_2
L_3:
    ldc 0
    goto L_4
L_2:
    ldc 1
L_4:
    ifeq L_0
    aload 0
    getfield LS/number [I
    iload 1
    iaload
    getstatic java/lang/System/out Ljava/io/PrintStream;
    swap
    invokevirtual java/io/PrintStream/println(I)V
    iload 1
    ldc 1
    iadd
    istore 1
    goto L_1
L_0:
    ldc 0
    ireturn
.end method
.method public Search(I)I
.limit stack 4096
.limit locals 9
    ldc 1
    istore 2
    ldc 0
    istore 3
    ldc 0
    istore 4
L_6:
    iload 2
    aload 0
    getfield LS/size I
    if_icmplt L_7
L_8:
    ldc 0
    goto L_9
L_7:
    ldc 1
L_9:
    ifeq L_5
    aload 0
    getfield LS/number [I
    iload 2
    iaload
    istore 5
    iload 1
    ldc 1
    iadd
    istore 6
    iload 5
    iload 1
    if_icmplt L_12
L_13:
    ldc 0
    goto L_14
L_12:
    ldc 1
L_14:
    ifeq L_10
    ldc 0
    istore 7
    goto L_11
L_10:
    iload 5
    iload 6
    if_icmplt L_17
L_18:
    ldc 0
    goto L_19
L_17:
    ldc 1
L_19:
    ldc 1
    ixor
    ifeq L_15
    ldc 0
    istore 7
    goto L_16
L_15:
    ldc 1
    istore 3
    ldc 1
    istore 4
    aload 0
    getfield LS/size I
    istore 2
L_16:
L_11:
    iload 2
    ldc 1
    iadd
    istore 2
    goto L_6
L_5:
    iload 4
    ireturn
.end method
.method public Init(I)I
.limit stack 4096
.limit locals 7
    aload 0
    iload 1
    putfield LS/size I
    aload 0
    iload 1
    newarray int
    putfield LS/number [I
    ldc 1
    istore 2
    aload 0
    getfield LS/size I
    ldc 1
    iadd
    istore 3
L_21:
    iload 2
    aload 0
    getfield LS/size I
    if_icmplt L_22
L_23:
    ldc 0
    goto L_24
L_22:
    ldc 1
L_24:
    ifeq L_20
    ldc 2
    iload 2
    imul
    istore 4
    iload 3
    ldc 3
    isub
    istore 5
    aload 0
    getfield LS/number [I
    iload 2
    iload 4
    iload 5
    iadd
    iastore
    iload 2
    ldc 1
    iadd
    istore 2
    iload 3
    ldc 1
    isub
    istore 3
    goto L_21
L_20:
    ldc 0
    ireturn
.end method
