// This is automatically generated by the Tiger compiler.
// Do NOT modify!

// Control-flow Graph

// structures
struct TreeVisitor
{
  struct TreeVisitor_vtable *vptr;
};
struct TV
{
  struct TV_vtable *vptr;
};
struct Tree
{
  struct Tree_vtable *vptr;
  struct Tree * left;
  struct Tree * right;
  int key;
  int has_left;
  int has_right;
  struct Tree * my_null;
};
struct Visitor
{
  struct Visitor_vtable *vptr;
  struct Tree * l;
  struct Tree * r;
};
struct MyVisitor
{
  struct MyVisitor_vtable *vptr;
  struct Tree * l;
  struct Tree * r;
};
// vtables structures
struct TreeVisitor_vtable
{
};

struct TV_vtable
{
  int (*Start)();
};

struct Tree_vtable
{
  int (*Init)();
  int (*SetRight)();
  int (*SetLeft)();
  struct Tree * (*GetRight)();
  struct Tree * (*GetLeft)();
  int (*GetKey)();
  int (*SetKey)();
  int (*GetHas_Right)();
  int (*GetHas_Left)();
  int (*SetHas_Left)();
  int (*SetHas_Right)();
  int (*Compare)();
  int (*Insert)();
  int (*Delete)();
  int (*Remove)();
  int (*RemoveRight)();
  int (*RemoveLeft)();
  int (*Search)();
  int (*Print)();
  int (*RecPrint)();
  int (*accept)();
};

struct Visitor_vtable
{
  int (*visit)();
};

struct MyVisitor_vtable
{
  int (*visit)();
};


// vtables declared
struct TreeVisitor_vtable TreeVisitor_vtable_ ;
struct TV_vtable TV_vtable_ ;
struct Tree_vtable Tree_vtable_ ;
struct Visitor_vtable Visitor_vtable_ ;
struct MyVisitor_vtable MyVisitor_vtable_ ;

// methods
int TV_Start(struct TV * this)
{
  struct Tree * root;
  int ntb;
  int nti;
  struct MyVisitor * v;
  struct Tree * x_1;
  struct Tree * x_2;
  struct Tree * x_3;
  struct Tree * x_4;
  struct Tree * x_5;
  struct Tree * x_6;
  struct Tree * x_7;
  struct Tree * x_8;
  struct Tree * x_9;
  struct Tree * x_10;
  struct Tree * x_11;
  struct Tree * x_12;
  struct Tree * x_13;
  struct Tree * x_14;
  struct Tree * x_15;
  struct Tree * x_16;
  struct Tree * x_17;
  struct Tree * x_18;
  struct Tree * x_19;
  struct Tree * x_92;
  int x_93;
  int x_94;
  int x_95;
  int x_96;
  int x_97;
  int x_98;
  int x_99;
  int x_100;
  int x_101;
  int x_102;
  struct MyVisitor * x_103;
  int x_104;
  int x_105;
  int x_106;
  int x_107;
  int x_108;
  int x_109;
  int x_110;
  int x_111;
  int x_112;

L_0:
  x_92 = ((struct Tree*)(Tiger_new (&Tree_vtable_, sizeof(struct Tree))));
  root = x_92;
  x_93 = root->vptr->Init(root, 16);
  ntb = x_93;
  x_94 = root->vptr->Print(root);
  ntb = x_94;
  System_out_println (100000000);
  x_95 = root->vptr->Insert(root, 8);
  ntb = x_95;
  x_96 = root->vptr->Insert(root, 24);
  ntb = x_96;
  x_97 = root->vptr->Insert(root, 4);
  ntb = x_97;
  x_98 = root->vptr->Insert(root, 12);
  ntb = x_98;
  x_99 = root->vptr->Insert(root, 20);
  ntb = x_99;
  x_100 = root->vptr->Insert(root, 28);
  ntb = x_100;
  x_101 = root->vptr->Insert(root, 14);
  ntb = x_101;
  x_102 = root->vptr->Print(root);
  ntb = x_102;
  System_out_println (100000000);
  x_103 = ((struct MyVisitor*)(Tiger_new (&MyVisitor_vtable_, sizeof(struct MyVisitor))));
  v = x_103;
  System_out_println (50000000);
  x_104 = root->vptr->accept(root, v);
  nti = x_104;
  System_out_println (100000000);
  x_105 = root->vptr->Search(root, 24);
  System_out_println (x_105);
  x_106 = root->vptr->Search(root, 12);
  System_out_println (x_106);
  x_107 = root->vptr->Search(root, 16);
  System_out_println (x_107);
  x_108 = root->vptr->Search(root, 50);
  System_out_println (x_108);
  x_109 = root->vptr->Search(root, 12);
  System_out_println (x_109);
  x_110 = root->vptr->Delete(root, 12);
  ntb = x_110;
  x_111 = root->vptr->Print(root);
  ntb = x_111;
  x_112 = root->vptr->Search(root, 12);
  System_out_println (x_112);
  return 0;
}
int Tree_Init(struct Tree * this, int v_key)
{

L_1:
  this->key = v_key;
  this->has_left = 0;
  this->has_right = 0;
  return 1;
}
int Tree_SetRight(struct Tree * this, struct Tree * rn)
{

L_2:
  this->right = rn;
  return 1;
}
int Tree_SetLeft(struct Tree * this, struct Tree * ln)
{

L_3:
  this->left = ln;
  return 1;
}
struct Tree * Tree_GetRight(struct Tree * this)
{

L_4:
  return this->right;
}
struct Tree * Tree_GetLeft(struct Tree * this)
{

L_5:
  return this->left;
}
int Tree_GetKey(struct Tree * this)
{

L_6:
  return this->key;
}
int Tree_SetKey(struct Tree * this, int v_key)
{

L_7:
  this->key = v_key;
  return 1;
}
int Tree_GetHas_Right(struct Tree * this)
{

L_8:
  return this->has_right;
}
int Tree_GetHas_Left(struct Tree * this)
{

L_9:
  return this->has_left;
}
int Tree_SetHas_Left(struct Tree * this, int val)
{

L_10:
  this->has_left = val;
  return 1;
}
int Tree_SetHas_Right(struct Tree * this, int val)
{

L_11:
  this->has_right = val;
  return 1;
}
int Tree_Compare(struct Tree * this, int num1, int num2)
{
  int ntb;
  int nti;
  int x_113;
  int x_114;
  int x_115;
  int x_116;

L_12:
  ntb = 0;
  x_113 = num2 + 1;
  nti = x_113;
  x_114 = num1 < num2;
  if (x_114)
    goto L_13;
  else
    goto L_14;
L_14:
  x_116 = num1 < nti;
  x_115 = !(x_116);
  if (x_115)
    goto L_16;
  else
    goto L_17;
L_17:
  ntb = 1;
  goto L_18;
L_16:
  ntb = 0;
  goto L_18;
L_18:
  goto L_15;
L_13:
  ntb = 0;
  goto L_15;
L_15:
  return ntb;
}
int Tree_Insert(struct Tree * this, int v_key)
{
  struct Tree * new_node;
  int ntb;
  struct Tree * current_node;
  int cont;
  int key_aux;
  struct Tree * x_20;
  struct Tree * x_21;
  struct Tree * x_22;
  struct Tree * x_23;
  struct Tree * x_24;
  struct Tree * x_25;
  struct Tree * x_26;
  struct Tree * x_27;
  struct Tree * x_28;
  struct Tree * x_29;
  struct Tree * x_117;
  int x_118;
  int x_119;
  int x_120;
  int x_121;
  int x_122;
  int x_123;
  struct Tree * x_124;
  int x_125;
  int x_126;
  int x_127;
  struct Tree * x_128;

L_19:
  x_117 = ((struct Tree*)(Tiger_new (&Tree_vtable_, sizeof(struct Tree))));
  new_node = x_117;
  x_118 = new_node->vptr->Init(new_node, v_key);
  ntb = x_118;
  current_node = this;
  cont = 1;
  goto L_20;
L_20:
  if (cont)
    goto L_21;
  else
    goto L_22;
L_21:
  x_119 = current_node->vptr->GetKey(current_node);
  key_aux = x_119;
  x_120 = v_key < key_aux;
  if (x_120)
    goto L_23;
  else
    goto L_24;
L_24:
  x_121 = current_node->vptr->GetHas_Right(current_node);
  if (x_121)
    goto L_26;
  else
    goto L_27;
L_27:
  cont = 0;
  x_122 = current_node->vptr->SetHas_Right(current_node, 1);
  ntb = x_122;
  x_123 = current_node->vptr->SetRight(current_node, new_node);
  ntb = x_123;

  goto L_28;
L_26:
  x_124 = current_node->vptr->GetRight(current_node);
  current_node = x_124;
  goto L_28;
L_28:

  goto L_25;
L_23:
  x_125 = current_node->vptr->GetHas_Left(current_node);
  if (x_125)
    goto L_29;
  else
    goto L_30;
L_30:
  cont = 0;
  x_126 = current_node->vptr->SetHas_Left(current_node, 1);
  ntb = x_126;
  x_127 = current_node->vptr->SetLeft(current_node, new_node);
  ntb = x_127;

  goto L_31;
L_29:
  x_128 = current_node->vptr->GetLeft(current_node);
  current_node = x_128;
  goto L_31;
L_31:

  goto L_25;
L_25:

  goto L_20;
L_22:
  return 1;
}
int Tree_Delete(struct Tree * this, int v_key)
{
  struct Tree * current_node;
  struct Tree * parent_node;
  int cont;
  int found;
  int ntb;
  int is_root;
  int key_aux;
  struct Tree * x_30;
  struct Tree * x_31;
  struct Tree * x_32;
  struct Tree * x_33;
  struct Tree * x_34;
  struct Tree * x_35;
  struct Tree * x_36;
  struct Tree * x_37;
  struct Tree * x_38;
  int x_129;
  int x_130;
  int x_131;
  int x_132;
  int x_133;
  int x_134;
  int x_135;
  int x_136;
  int x_137;
  int x_138;
  int x_139;
  struct Tree * x_140;
  int x_141;
  struct Tree * x_142;

L_32:
  current_node = this;
  parent_node = this;
  cont = 1;
  found = 0;
  is_root = 1;
  goto L_33;
L_33:
  if (cont)
    goto L_34;
  else
    goto L_35;
L_34:
  x_129 = current_node->vptr->GetKey(current_node);
  key_aux = x_129;
  x_130 = v_key < key_aux;
  if (x_130)
    goto L_36;
  else
    goto L_37;
L_37:
  x_131 = key_aux < v_key;
  if (x_131)
    goto L_39;
  else
    goto L_40;
L_40:
  if (is_root)
    goto L_42;
  else
    goto L_43;
L_43:
  x_132 = this->vptr->Remove(this, parent_node, current_node);
  ntb = x_132;
  goto L_44;
L_42:
  x_135 = current_node->vptr->GetHas_Right(current_node);
  x_134 = !(x_135);
  x_137 = current_node->vptr->GetHas_Left(current_node);
  x_136 = !(x_137);
  x_133 = x_134 && x_136;
  if (x_133)
    goto L_45;
  else
    goto L_46;
L_46:
  x_138 = this->vptr->Remove(this, parent_node, current_node);
  ntb = x_138;
  goto L_47;
L_45:
  ntb = 1;
  goto L_47;
L_47:
  goto L_44;
L_44:
  found = 1;
  cont = 0;

  goto L_41;
L_39:
  x_139 = current_node->vptr->GetHas_Right(current_node);
  if (x_139)
    goto L_48;
  else
    goto L_49;
L_49:
  cont = 0;
  goto L_50;
L_48:
  parent_node = current_node;
  x_140 = current_node->vptr->GetRight(current_node);
  current_node = x_140;

  goto L_50;
L_50:
  goto L_41;
L_41:
  goto L_38;
L_36:
  x_141 = current_node->vptr->GetHas_Left(current_node);
  if (x_141)
    goto L_51;
  else
    goto L_52;
L_52:
  cont = 0;
  goto L_53;
L_51:
  parent_node = current_node;
  x_142 = current_node->vptr->GetLeft(current_node);
  current_node = x_142;

  goto L_53;
L_53:
  goto L_38;
L_38:
  is_root = 0;

  goto L_33;
L_35:
  return found;
}
int Tree_Remove(struct Tree * this, struct Tree * p_node, struct Tree * c_node)
{
  int ntb;
  int auxkey1;
  int auxkey2;
  struct Tree * x_39;
  struct Tree * x_40;
  struct Tree * x_41;
  struct Tree * x_42;
  struct Tree * x_43;
  struct Tree * x_44;
  struct Tree * x_45;
  struct Tree * x_46;
  struct Tree * x_47;
  struct Tree * x_48;
  struct Tree * x_49;
  struct Tree * x_50;
  int x_143;
  int x_144;
  int x_145;
  int x_146;
  struct Tree * x_147;
  int x_148;
  int x_149;
  int x_150;
  int x_151;
  int x_152;
  int x_153;
  int x_154;

L_54:
  x_143 = c_node->vptr->GetHas_Left(c_node);
  if (x_143)
    goto L_55;
  else
    goto L_56;
L_56:
  x_144 = c_node->vptr->GetHas_Right(c_node);
  if (x_144)
    goto L_58;
  else
    goto L_59;
L_59:
  x_145 = c_node->vptr->GetKey(c_node);
  auxkey1 = x_145;
  x_147 = p_node->vptr->GetLeft(p_node);
  x_146 = x_147->vptr->GetKey(x_147);
  auxkey2 = x_146;
  x_148 = this->vptr->Compare(this, auxkey1, auxkey2);
  if (x_148)
    goto L_61;
  else
    goto L_62;
L_62:
  x_149 = p_node->vptr->SetRight(p_node, this->my_null);
  ntb = x_149;
  x_150 = p_node->vptr->SetHas_Right(p_node, 0);
  ntb = x_150;

  goto L_63;
L_61:
  x_151 = p_node->vptr->SetLeft(p_node, this->my_null);
  ntb = x_151;
  x_152 = p_node->vptr->SetHas_Left(p_node, 0);
  ntb = x_152;

  goto L_63;
L_63:

  goto L_60;
L_58:
  x_153 = this->vptr->RemoveRight(this, p_node, c_node);
  ntb = x_153;
  goto L_60;
L_60:
  goto L_57;
L_55:
  x_154 = this->vptr->RemoveLeft(this, p_node, c_node);
  ntb = x_154;
  goto L_57;
L_57:
  return 1;
}
int Tree_RemoveRight(struct Tree * this, struct Tree * p_node, struct Tree * c_node)
{
  int ntb;
  struct Tree * x_51;
  struct Tree * x_52;
  struct Tree * x_53;
  struct Tree * x_54;
  struct Tree * x_55;
  struct Tree * x_56;
  struct Tree * x_57;
  int x_155;
  int x_156;
  int x_157;
  struct Tree * x_158;
  struct Tree * x_159;
  int x_160;
  int x_161;

L_64:
  goto L_65;
L_65:
  x_155 = c_node->vptr->GetHas_Right(c_node);
  if (x_155)
    goto L_66;
  else
    goto L_67;
L_66:
  x_158 = c_node->vptr->GetRight(c_node);
  x_157 = x_158->vptr->GetKey(x_158);
  x_156 = c_node->vptr->SetKey(c_node, x_157);
  ntb = x_156;
  p_node = c_node;
  x_159 = c_node->vptr->GetRight(c_node);
  c_node = x_159;

  goto L_65;
L_67:
  x_160 = p_node->vptr->SetRight(p_node, this->my_null);
  ntb = x_160;
  x_161 = p_node->vptr->SetHas_Right(p_node, 0);
  ntb = x_161;
  return 1;
}
int Tree_RemoveLeft(struct Tree * this, struct Tree * p_node, struct Tree * c_node)
{
  int ntb;
  struct Tree * x_58;
  struct Tree * x_59;
  struct Tree * x_60;
  struct Tree * x_61;
  struct Tree * x_62;
  struct Tree * x_63;
  struct Tree * x_64;
  int x_162;
  int x_163;
  int x_164;
  struct Tree * x_165;
  struct Tree * x_166;
  int x_167;
  int x_168;

L_68:
  goto L_69;
L_69:
  x_162 = c_node->vptr->GetHas_Left(c_node);
  if (x_162)
    goto L_70;
  else
    goto L_71;
L_70:
  x_165 = c_node->vptr->GetLeft(c_node);
  x_164 = x_165->vptr->GetKey(x_165);
  x_163 = c_node->vptr->SetKey(c_node, x_164);
  ntb = x_163;
  p_node = c_node;
  x_166 = c_node->vptr->GetLeft(c_node);
  c_node = x_166;

  goto L_69;
L_71:
  x_167 = p_node->vptr->SetLeft(p_node, this->my_null);
  ntb = x_167;
  x_168 = p_node->vptr->SetHas_Left(p_node, 0);
  ntb = x_168;
  return 1;
}
int Tree_Search(struct Tree * this, int v_key)
{
  struct Tree * current_node;
  int ifound;
  int cont;
  int key_aux;
  struct Tree * x_65;
  struct Tree * x_66;
  struct Tree * x_67;
  struct Tree * x_68;
  struct Tree * x_69;
  int x_169;
  int x_170;
  int x_171;
  int x_172;
  struct Tree * x_173;
  int x_174;
  struct Tree * x_175;

L_72:
  current_node = this;
  cont = 1;
  ifound = 0;
  goto L_73;
L_73:
  if (cont)
    goto L_74;
  else
    goto L_75;
L_74:
  x_169 = current_node->vptr->GetKey(current_node);
  key_aux = x_169;
  x_170 = v_key < key_aux;
  if (x_170)
    goto L_76;
  else
    goto L_77;
L_77:
  x_171 = key_aux < v_key;
  if (x_171)
    goto L_79;
  else
    goto L_80;
L_80:
  ifound = 1;
  cont = 0;

  goto L_81;
L_79:
  x_172 = current_node->vptr->GetHas_Right(current_node);
  if (x_172)
    goto L_82;
  else
    goto L_83;
L_83:
  cont = 0;
  goto L_84;
L_82:
  x_173 = current_node->vptr->GetRight(current_node);
  current_node = x_173;
  goto L_84;
L_84:
  goto L_81;
L_81:
  goto L_78;
L_76:
  x_174 = current_node->vptr->GetHas_Left(current_node);
  if (x_174)
    goto L_85;
  else
    goto L_86;
L_86:
  cont = 0;
  goto L_87;
L_85:
  x_175 = current_node->vptr->GetLeft(current_node);
  current_node = x_175;
  goto L_87;
L_87:
  goto L_78;
L_78:

  goto L_73;
L_75:
  return ifound;
}
int Tree_Print(struct Tree * this)
{
  int ntb;
  struct Tree * current_node;
  struct Tree * x_70;
  int x_176;

L_88:
  current_node = this;
  x_176 = this->vptr->RecPrint(this, current_node);
  ntb = x_176;
  return 1;
}
int Tree_RecPrint(struct Tree * this, struct Tree * node)
{
  int ntb;
  struct Tree * x_71;
  struct Tree * x_72;
  struct Tree * x_73;
  struct Tree * x_74;
  struct Tree * x_75;
  struct Tree * x_76;
  struct Tree * x_77;
  int x_177;
  int x_178;
  struct Tree * x_179;
  int x_180;
  int x_181;
  int x_182;
  struct Tree * x_183;

L_89:
  x_177 = node->vptr->GetHas_Left(node);
  if (x_177)
    goto L_90;
  else
    goto L_91;
L_91:
  ntb = 1;
  goto L_92;
L_90:
  x_179 = node->vptr->GetLeft(node);
  x_178 = this->vptr->RecPrint(this, x_179);
  ntb = x_178;

  goto L_92;
L_92:
  x_180 = node->vptr->GetKey(node);
  System_out_println (x_180);
  x_181 = node->vptr->GetHas_Right(node);
  if (x_181)
    goto L_93;
  else
    goto L_94;
L_94:
  ntb = 1;
  goto L_95;
L_93:
  x_183 = node->vptr->GetRight(node);
  x_182 = this->vptr->RecPrint(this, x_183);
  ntb = x_182;

  goto L_95;
L_95:
  return 1;
}
int Tree_accept(struct Tree * this, struct Visitor * v)
{
  int nti;
  struct Visitor * x_78;
  int x_184;

L_96:
  System_out_println (333);
  x_184 = v->vptr->visit(v, this);
  nti = x_184;
  return 0;
}
int Visitor_visit(struct Visitor * this, struct Tree * n)
{
  int nti;
  struct Tree * x_79;
  struct Tree * x_80;
  struct Tree * x_81;
  struct Tree * x_82;
  struct Tree * x_83;
  struct Tree * x_84;
  int x_185;
  struct Tree * x_186;
  int x_187;
  int x_188;
  struct Tree * x_189;
  int x_190;

L_97:
  x_185 = n->vptr->GetHas_Right(n);
  if (x_185)
    goto L_98;
  else
    goto L_99;
L_99:
  nti = 0;
  goto L_100;
L_98:
  x_186 = n->vptr->GetRight(n);
  this->r = x_186;
  x_187 = r->vptr->accept(r, this);
  nti = x_187;

  goto L_100;
L_100:
  x_188 = n->vptr->GetHas_Left(n);
  if (x_188)
    goto L_101;
  else
    goto L_102;
L_102:
  nti = 0;
  goto L_103;
L_101:
  x_189 = n->vptr->GetLeft(n);
  this->l = x_189;
  x_190 = l->vptr->accept(l, this);
  nti = x_190;

  goto L_103;
L_103:
  return 0;
}
int MyVisitor_visit(struct MyVisitor * this, struct Tree * n)
{
  int nti;
  struct Tree * x_85;
  struct Tree * x_86;
  struct Tree * x_87;
  struct Tree * x_88;
  struct Tree * x_89;
  struct Tree * x_90;
  struct Tree * x_91;
  int x_191;
  struct Tree * x_192;
  int x_193;
  int x_194;
  int x_195;
  struct Tree * x_196;
  int x_197;

L_104:
  x_191 = n->vptr->GetHas_Right(n);
  if (x_191)
    goto L_105;
  else
    goto L_106;
L_106:
  nti = 0;
  goto L_107;
L_105:
  x_192 = n->vptr->GetRight(n);
  this->r = x_192;
  x_193 = r->vptr->accept(r, this);
  nti = x_193;

  goto L_107;
L_107:
  x_194 = n->vptr->GetKey(n);
  System_out_println (x_194);
  x_195 = n->vptr->GetHas_Left(n);
  if (x_195)
    goto L_108;
  else
    goto L_109;
L_109:
  nti = 0;
  goto L_110;
L_108:
  x_196 = n->vptr->GetLeft(n);
  this->l = x_196;
  x_197 = l->vptr->accept(l, this);
  nti = x_197;

  goto L_110;
L_110:
  return 0;
}

// vtables
struct TreeVisitor_vtable TreeVisitor_vtable_ = 
{
};

struct TV_vtable TV_vtable_ = 
{
  TV_Start,
};

struct Tree_vtable Tree_vtable_ = 
{
  Tree_Init,
  Tree_SetRight,
  Tree_SetLeft,
  Tree_GetRight,
  Tree_GetLeft,
  Tree_GetKey,
  Tree_SetKey,
  Tree_GetHas_Right,
  Tree_GetHas_Left,
  Tree_SetHas_Left,
  Tree_SetHas_Right,
  Tree_Compare,
  Tree_Insert,
  Tree_Delete,
  Tree_Remove,
  Tree_RemoveRight,
  Tree_RemoveLeft,
  Tree_Search,
  Tree_Print,
  Tree_RecPrint,
  Tree_accept,
};

struct Visitor_vtable Visitor_vtable_ = 
{
  Visitor_visit,
};

struct MyVisitor_vtable MyVisitor_vtable_ = 
{
  MyVisitor_visit,
};


// main method
int Tiger_main ()
{
  struct TV * x_0;
  int x_198;
  struct TV * x_199;

L_111:
  x_199 = ((struct TV*)(Tiger_new (&TV_vtable_, sizeof(struct TV))));
  x_198 = x_199->vptr->Start(x_199);
  System_out_println (x_198);
  return 0;
}




void *prev;
