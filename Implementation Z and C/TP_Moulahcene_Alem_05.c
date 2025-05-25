/*
_____ ____ ____       _    _     ____  ____  ____
|_   _|  _ \___ \    / \  | |   / ___||  _ \|  _ \
 | | | |_) |__) |   / _ \ | |   \___ \| | | | | | |
 | | |  __// __/   / ___ \| |___ ___) | |_| | |_| |
 |_| |_|  |_____| /_/   \_\_____|____/|____/|____/
*/

/**--------------------------------------------------------**/
/**       C o n v e r s i o n   Z vers C (Standard)        **/
/**             Realisee par Pr D.E ZEGOUR                 **/
/**             E S I - Alger                              **/
/**             Copywrite 2014                             **/
/**--------------------------------------------------------**/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <conio.h>
#include <windows.h>

typedef int bool;
typedef char *string255;
typedef char *string2;
#define True 1
#define False 0
#define BLK "\e[0;30m"
#define RED "\e[0;31m"
#define GRN "\e[0;32m"
#define YEL "\e[0;33m"
#define BLU "\e[0;34m"
#define MAG "\e[0;35m"
#define CYN "\e[0;36m"
#define WHT "\e[0;37m"
#define BBLK "\e[1;30m"
#define BRED "\e[1;31m"
#define BGRN "\e[1;32m"
#define BYEL "\e[1;33m"
#define BBLU "\e[1;34m"
#define BMAG "\e[1;35m"
#define BCYN "\e[1;36m"
#define BWHT "\e[1;37m"
#define UBLK "\e[4;30m"
#define URED "\e[4;31m"
#define UGRN "\e[4;32m"
#define UYEL "\e[4;33m"
#define UBLU "\e[4;34m"
#define UMAG "\e[4;35m"
#define UCYN "\e[4;36m"
#define UWHT "\e[4;37m"
#define BLKB "\e[40m"
#define REDB "\e[41m"
#define GRNB "\e[42m"
#define YELB "\e[43m"
#define BLUB "\e[44m"
#define MAGB "\e[45m"
#define CYNB "\e[46m"
#define WHTB "\e[47m"
#define BLKHB "\e[0;100m"
#define REDHB "\e[0;101m"
#define GRNHB "\e[0;102m"
#define YELHB "\e[0;103m"
#define BLUHB "\e[0;104m"
#define MAGHB "\e[0;105m"
#define CYNHB "\e[0;106m"
#define WHTHB "\e[0;107m"
#define HBLK "\e[0;90m"
#define HRED "\e[0;91m"
#define HGRN "\e[0;92m"
#define HYEL "\e[0;93m"
#define HBLU "\e[0;94m"
#define HMAG "\e[0;95m"
#define HCYN "\e[0;96m"
#define HWHT "\e[0;97m"
#define BHBLK "\e[1;90m"
#define BHRED "\e[1;91m"
#define BHGRN "\e[1;92m"
#define BHYEL "\e[1;93m"
#define BHBLU "\e[1;94m"
#define BHMAG "\e[1;95m"
#define BHCYN "\e[1;96m"
#define BHWHT "\e[1;97m"
#define reset "\e[0m"
#define Creset "\e[0m"
#define COLOR_reset "\e[0m"
typedef string255 Typeelem_As;
typedef struct Noeud_As *Pointeur_As;
struct Noeud_As
{
  Typeelem_As Val;
  Pointeur_As Fg;
  Pointeur_As Fd;
  Pointeur_As Pere;
};
Typeelem_As Info_As(Pointeur_As P)
{
  return P->Val;
}
Pointeur_As Fg_As(Pointeur_As P)
{
  return P->Fg;
}
Pointeur_As Fd_As(Pointeur_As P)
{
  return P->Fd;
}
Pointeur_As Pere_As(Pointeur_As P)
{
  return P->Pere;
}
void Aff_info_As(Pointeur_As P, Typeelem_As Val)
{
  strcpy(P->Val, Val);
}
void Aff_fg_As(Pointeur_As P, Pointeur_As Q)
{
  P->Fg = Q;
}
void Aff_fd_As(Pointeur_As P, Pointeur_As Q)
{
  P->Fd = Q;
}
void Aff_pere_As(Pointeur_As P, Pointeur_As Q)
{
  P->Pere = Q;
}
void Creernoeud_As(Pointeur_As *P)
{
  *P = (struct Noeud_As *)malloc(sizeof(struct Noeud_As));
  (*P)->Val = malloc(255 * sizeof(string255));
  (*P)->Fg = NULL;
  (*P)->Fd = NULL;
  (*P)->Pere = NULL;
}
void Liberernoeud_As(Pointeur_As P)
{
  free(P);
}
typedef string255 Typeelem_Ls;
typedef struct Maillon_Ls *Pointeur_Ls;
struct Maillon_Ls
{
  Typeelem_Ls Val;
  Pointeur_Ls Suiv;
};
void Allouer_Ls(Pointeur_Ls *P)
{
  *P = (struct Maillon_Ls *)malloc(sizeof(struct Maillon_Ls));
  (*P)->Val = malloc(255 * sizeof(string255));
  (*P)->Suiv = NULL;
}
void Aff_val_Ls(Pointeur_Ls P, Typeelem_Ls Val)
{
  strcpy(P->Val, Val);
}
void Aff_adr_Ls(Pointeur_Ls P, Pointeur_Ls Q)
{
  P->Suiv = Q;
}
Pointeur_Ls Suivant_Ls(Pointeur_Ls P)
{
  return (P->Suiv);
}
Typeelem_Ls Valeur_Ls(Pointeur_Ls P)
{
  return (P->Val);
}
void Liberer_Ls(Pointeur_Ls P)
{
  free(P);
}
struct _Noeud
{
  FILE *Var_fich;
  char *Nom_fich;
  int Sauv_pos;
  struct _Noeud *Suiv;
};
typedef struct _Noeud *_Ptr_Noeud;
_Ptr_Noeud _Pile_ouverts = NULL;
_Ptr_Noeud _Ouvert(char *Fp)
{
  _Ptr_Noeud P;
  bool Trouv;
  P = _Pile_ouverts;
  Trouv = False;
  while ((P != NULL) && !Trouv)
    if (strcmp(P->Nom_fich, Fp) == 0)
      Trouv = True;
    else
      P = P->Suiv;
  return P;
}
void _Empiler_ouvert(char *Fp, FILE *Fl)
{
  _Ptr_Noeud P;
  P = (_Ptr_Noeud)malloc(sizeof(struct _Noeud));
  P->Nom_fich = Fp;
  P->Var_fich = Fl;
  P->Suiv = _Pile_ouverts;
  _Pile_ouverts = P;
}
char *_Depiler_ouvert(FILE *Fl)
{
  char *Fp = malloc(100);
  _Ptr_Noeud P, Prec;
  P = _Pile_ouverts;
  Prec = NULL;
  while (P->Var_fich != Fl)
  {
    Prec = P;
    P = P->Suiv;
  }
  strcpy(Fp, P->Nom_fich);
  if (Prec != NULL)
    Prec->Suiv = P->Suiv;
  else
    _Pile_ouverts = P->Suiv;
  free(P);
  return Fp;
}
typedef char _Tx[255];
typedef string255 Typechamp1_ss;
typedef _Tx Typechamp1_ss_Buf;
typedef string255 Typechamp2_ss;
typedef _Tx Typechamp2_ss_Buf;
typedef struct
{
  Typechamp1_ss_Buf Champ1;
  Typechamp2_ss_Buf Champ2;
} Typestruct1_ss_Buf;
typedef struct
{
  Typechamp1_ss Champ1;
  Typechamp2_ss Champ2;
} Typestruct1_ss_;
typedef Typestruct1_ss_ *Typestruct1_ss;
typedef Typestruct1_ss Typestr_Tss;
typedef Typestruct1_ss_ Type_Tss;
Typechamp1_ss Struct1_Tss(Typestruct1_ss Buf)
{
  return Buf->Champ1;
}
Typechamp2_ss Struct2_Tss(Typestruct1_ss Buf)
{
  return Buf->Champ2;
}
void Aff_struct1_Tss(Typestruct1_ss Buf, Typechamp1_ss Val)
{
  strcpy(Buf->Champ1, Val);
}
void Aff_struct2_Tss(Typestruct1_ss Buf, Typechamp2_ss Val)
{
  strcpy(Buf->Champ2, Val);
}
void Ouvrir_ss(FILE **ss, char *Fp, char *Mode)
{
  _Ptr_Noeud P = _Ouvert(Fp);
  if (P != NULL)
  {
    P->Sauv_pos = ftell(P->Var_fich);
    fclose(P->Var_fich);
  }
  if (strcmp(Mode, "A") == 0)
    *ss = fopen(Fp, "r+b");
  else
    *ss = fopen(Fp, "w+b");
  _Empiler_ouvert(Fp, *ss);
}
void Fermer_ss(FILE *ss)
{
  char *Fp = malloc(100);
  _Ptr_Noeud P;
  strcpy(Fp, _Depiler_ouvert(ss));
  fclose(ss);
  P = _Ouvert(Fp);
  if (P != NULL)
  {
    ss = fopen(P->Nom_fich, "r+b");
    fseek(ss, P->Sauv_pos, 0);
  }
}
void Ecrireseq_ss(FILE *ss, Typestruct1_ss Buf)
{
  Typestruct1_ss_Buf Buffer;
  int I, J;
  for (J = 0; J <= strlen(Buf->Champ1); ++J)
    Buffer.Champ1[J] = Buf->Champ1[J];
  for (J = 0; J <= strlen(Buf->Champ2); ++J)
    Buffer.Champ2[J] = Buf->Champ2[J];
  fwrite(&Buffer, sizeof(Typestruct1_ss_Buf), 1, ss);
}
void Ecriredir_ss(FILE *ss, Typestruct1_ss Buf, int N)
{
  Typestruct1_ss_Buf Buffer;
  int I, J;
  for (J = 0; J <= strlen(Buf->Champ1); ++J)
    Buffer.Champ1[J] = Buf->Champ1[J];
  for (J = 0; J <= strlen(Buf->Champ2); ++J)
    Buffer.Champ2[J] = Buf->Champ2[J];
  fseek(ss, (long)(N - 1) * sizeof(Typestruct1_ss_Buf), 0);
  fwrite(&Buffer, sizeof(Typestruct1_ss_Buf), 1, ss);
}
void Lireseq_ss(FILE *ss, Typestruct1_ss Buf)
{
  Typestruct1_ss_Buf Buffer;
  int I, J;
  if (fread(&Buffer, sizeof(Typestruct1_ss_Buf), 1, ss) != 0)
  {
    for (J = 0; J <= strlen(Buffer.Champ1); ++J)
      Buf->Champ1[J] = Buffer.Champ1[J];
    for (J = 0; J <= strlen(Buffer.Champ2); ++J)
      Buf->Champ2[J] = Buffer.Champ2[J];
  }
}
void Liredir_ss(FILE *ss, Typestruct1_ss Buf, int N)
{
  Typestruct1_ss_Buf Buffer;
  int I, J;
  fseek(ss, (long)(N - 1) * sizeof(Typestruct1_ss_Buf), 0);
  fread(&Buffer, sizeof(Typestruct1_ss_Buf), 1, ss);
  for (J = 0; J <= strlen(Buffer.Champ1); ++J)
    Buf->Champ1[J] = Buffer.Champ1[J];
  for (J = 0; J <= strlen(Buffer.Champ2); ++J)
    Buf->Champ2[J] = Buffer.Champ2[J];
}
void Rajouter_ss(FILE *ss, Typestruct1_ss Buf)
{
  Typestruct1_ss_Buf Buffer;
  int I, J;
  for (J = 0; J <= strlen(Buf->Champ1); ++J)
    Buffer.Champ1[J] = Buf->Champ1[J];
  for (J = 0; J <= strlen(Buf->Champ2); ++J)
    Buffer.Champ2[J] = Buf->Champ2[J];
  fseek(ss, 0, 2);
  fwrite(&Buffer, sizeof(Typestruct1_ss_Buf), 1, ss);
}
bool Finfich_ss(FILE *ss)
{
  long K = ftell(ss);
  fseek(ss, 0, 2);
  long K2 = ftell(ss);
  if (K == K2)
  {
    fseek(ss, K, 0);
    return 1;
  }
  else
  {
    fseek(ss, K, 0);
    return 0;
  }
}
int Alloc_bloc_ss(FILE *ss)
{
  long K;
  fseek(ss, 0, 2);
  K = ftell(ss);
  K = K / sizeof(Typestruct1_ss_Buf);
  K++;
  return (K);
}
Pointeur_As Bst0 = NULL;
Pointeur_As Bst1 = NULL;
Pointeur_As Bst2 = NULL;
Pointeur_As Bst3 = NULL;
int Choix;
string255 Search_word;
string255 Mot1;
string255 Mot2;
Pointeur_As Search_result = NULL;
Pointeur_Ls Serach_result_list = NULL;
char *Aleachaine(int N)
{
  int k;
  char *Chaine = malloc(N + 1);
  char Chr1[26] = "abcdefghijklmnopqrstuvwxyz";
  char Chr2[26] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
  for (k = 0; k < N; k++)
    switch (rand() % 2)
    {
    case 0:
      *(Chaine + k) = Chr1[rand() % 26];
      break;
    case 1:
      *(Chaine + k) = Chr2[rand() % 26];
      break;
    }
  Chaine[k] = '\0';
  return (Chaine);
}
int Longchaine(string255 Ch)
{
  return strlen(Ch);
}
char *Caract(string255 Ch, int I)
{
  char *s = malloc(2);
  s[0] = Ch[I - 1];
  s[1] = '\0';
  return s;
}
void Init_struct_Tss(Typestr_Tss S, Type_Tss S_)
{
  S->Champ1 = S_.Champ1;
  S->Champ2 = S_.Champ2;
}
void Gen_words();
void Make_bsts();
void Add_node(Pointeur_As *Unarbre_ref, string255 *Mot, int *Mode);
void Show_bst(Pointeur_As *Unarbre);
void Rot_left(Pointeur_As *Nodetorotate_ref);
void Rot_right(Pointeur_As *Nodetorotate_ref);
void Move_to_root(Pointeur_As *Unarbre_ref, string255 *Motcible);
void Move_to_middle(Pointeur_As *Unarbre_ref, string255 *Motcible);
Pointeur_As Find_in_bst(Pointeur_As *Tree, string255 *Wordtofind);
Pointeur_As Find_word(string255 *Words);
void Range_find(Pointeur_As *Node, string255 *W1, string255 *W2, Pointeur_Ls *Result_list);
void Range_on_custom_bsts(string255 *W1, string255 *W2, Pointeur_Ls *Combined_results);
int Get_depth(Pointeur_As *Tree);
int Count_char(Pointeur_As *Tree, string2 *Lettre);
void Show_stats();
Pointeur_As Find_in_bst_with_path_length(Pointeur_As *Tree, string255 *Wordtofind, int *Pathlength_ref);
Pointeur_As Find_word_with_path_length(string255 *Words, int *Pathlength_ref);
void Calculate_avg_search_paths();
int Count_words_by_char_category(Pointeur_As *Tree, int *Categorytype, string2 *C1, string2 *C2, string2 *C3);
void Show_recommendation_stats();
void clearScreen()
{
  system("cls");
}
void pressKeyToContinue()
{
  printf("\n%sPress any key to continue...%s", BYEL, reset);
  getch();
}
void Gen_words()
{
  FILE *F;
  Typestruct1_ss S;
  int I;
  Type_Tss S_S;
  S = malloc(sizeof(Typestruct1_ss));
  S->Champ1 = malloc(255 * sizeof(char));
  S->Champ2 = malloc(255 * sizeof(char));
  Ouvrir_ss(&F, "F2.z", "N");
  for (I = 1; I <= 101; ++I)
  {
    S_S.Champ1 = malloc(255 * sizeof(char));
    strcpy(S_S.Champ1, Aleachaine(5));
    S_S.Champ2 = malloc(255 * sizeof(char));
    strcpy(S_S.Champ2, Aleachaine(5));
    Init_struct_Tss(S, S_S);
    Ecrireseq_ss(F, S);
  };
  Fermer_ss(F);
  printf(" %s", "File F2.z created with 100 words (as structures).");
}
void Make_bsts()
{
  FILE *F;
  Typestruct1_ss S;
  string2 C;
  string255 Currentword;
  string2 Charruley;
  string2 Charrulez;
  string2 Charrule_a;
  int _Px1;
  int _Px2;
  int _Px3;
  int _Px4;
  S = malloc(sizeof(Typestruct1_ss));
  S->Champ1 = malloc(255 * sizeof(char));
  S->Champ2 = malloc(255 * sizeof(char));
  C = malloc(2 * sizeof(char));
  Currentword = malloc(255 * sizeof(char));
  Charruley = malloc(2 * sizeof(char));
  Charrulez = malloc(2 * sizeof(char));
  Charrule_a = malloc(2 * sizeof(char));
  strcpy(Charruley, "Y");
  strcpy(Charrulez, "Z");
  strcpy(Charrule_a, "a");
  Ouvrir_ss(&F, "F2.z", "A");
  while (!Finfich_ss(F))
  {
    Lireseq_ss(F, S);
    strcpy(Currentword, Struct1_Tss(S));
    if (Longchaine(Currentword) > 0)
    {
      strcpy(C, Caract(Currentword, 1));
      _Px1 = 0;
      Add_node(&Bst0, &Currentword, &_Px1);
      if (((strcmp(C, Charruley) == 0) || (strcmp(C, Charrulez) == 0) || (strcmp(C, Charrule_a) == 0)))
      {
        _Px2 = 1;
        Add_node(&Bst1, &Currentword, &_Px2);
        _Px3 = 2;
        Add_node(&Bst2, &Currentword, &_Px3);
      }
      else
      {
        _Px4 = 1;
        Add_node(&Bst3, &Currentword, &_Px4);
      }
    }
  };
  Fermer_ss(F);
}
void Add_node(Pointeur_As *Unarbre_ref, string255 *Mot, int *Mode)
{
  Pointeur_As Left_child_temp = NULL;
  Pointeur_As Right_child_temp = NULL;
  if (*Unarbre_ref == NULL)
  {
    Creernoeud_As(&*Unarbre_ref);
    Aff_info_As(*Unarbre_ref, *Mot);
    Aff_fg_As(*Unarbre_ref, NULL);
    Aff_fd_As(*Unarbre_ref, NULL);
  }
  else
  {
    if (strcmp(*Mot, Info_As(*Unarbre_ref)) < 0)
    {
      Left_child_temp = Fg_As(*Unarbre_ref);
      Add_node(&Left_child_temp, &*Mot, &*Mode);
      Aff_fg_As(*Unarbre_ref, Left_child_temp);
    }
    else
    {
      if (strcmp(*Mot, Info_As(*Unarbre_ref)) > 0)
      {
        Right_child_temp = Fd_As(*Unarbre_ref);
        Add_node(&Right_child_temp, &*Mot, &*Mode);
        Aff_fd_As(*Unarbre_ref, Right_child_temp);
      }
    };
    if ((*Unarbre_ref != NULL) && (strcmp(Info_As(*Unarbre_ref), *Mot) == 0))
    {
      if (*Mode == 1)
      {
        Move_to_root(&*Unarbre_ref, &*Mot);
      }
      else
      {
        if (*Mode == 2)
        {
          Move_to_middle(&*Unarbre_ref, &*Mot);
        };
      };
    }
  }
}
void Show_bst(Pointeur_As *Unarbre)
{
  Pointeur_As _Px1 = NULL;
  Pointeur_As _Px2 = NULL;
  if (*Unarbre != NULL)
  {
    _Px1 = Fg_As(*Unarbre);
    Show_bst(&_Px1);
    printf(" %s", Info_As(*Unarbre));
    _Px2 = Fd_As(*Unarbre);
    Show_bst(&_Px2);
  }
}
void Rot_left(Pointeur_As *Nodetorotate_ref)
{
  Pointeur_As Q_temp = NULL;
  if (((*Nodetorotate_ref != NULL) && (Fd_As(*Nodetorotate_ref) != NULL)))
  {
    Q_temp = Fd_As(*Nodetorotate_ref);
    Aff_fd_As(*Nodetorotate_ref, Fg_As(Q_temp));
    Aff_fg_As(Q_temp, *Nodetorotate_ref);
    *Nodetorotate_ref = Q_temp;
  }
}
void Rot_right(Pointeur_As *Nodetorotate_ref)
{
  Pointeur_As Q_temp = NULL;
  if (((*Nodetorotate_ref != NULL) && (Fg_As(*Nodetorotate_ref) != NULL)))
  {
    Q_temp = Fg_As(*Nodetorotate_ref);
    Aff_fg_As(*Nodetorotate_ref, Fd_As(Q_temp));
    Aff_fd_As(Q_temp, *Nodetorotate_ref);
    *Nodetorotate_ref = Q_temp;
  }
}
void Move_to_root(Pointeur_As *Unarbre_ref, string255 *Motcible)
{
  Pointeur_As Child_node = NULL;
  if (*Unarbre_ref != NULL)
  {
    if (strcmp(Info_As(*Unarbre_ref), *Motcible) != 0)
    {
      if (strcmp(*Motcible, Info_As(*Unarbre_ref)) < 0)
      {
        Child_node = Fg_As(*Unarbre_ref);
        if (Child_node != NULL)
        {
          Move_to_root(&Child_node, &*Motcible);
          Aff_fg_As(*Unarbre_ref, Child_node);
          if (strcmp(Info_As(Fg_As(*Unarbre_ref)), *Motcible) == 0)
          {
            Rot_right(&*Unarbre_ref);
          };
        };
      }
      else
      {
        if (strcmp(*Motcible, Info_As(*Unarbre_ref)) > 0)
        {
          Child_node = Fd_As(*Unarbre_ref);
          if (Child_node != NULL)
          {
            Move_to_root(&Child_node, &*Motcible);
            Aff_fd_As(*Unarbre_ref, Child_node);
            if (strcmp(Info_As(Fd_As(*Unarbre_ref)), *Motcible) == 0)
            {
              Rot_left(&*Unarbre_ref);
            };
          };
        };
      };
    };
  }
}
void Move_to_middle(Pointeur_As *Unarbre_ref, string255 *Motcible)
{
  Pointeur_As Child_node = NULL;
  Pointeur_As Grand_child_node = NULL;
  if ((*Unarbre_ref != NULL) && (strcmp(Info_As(*Unarbre_ref), *Motcible) != 0))
  {
    if (strcmp(*Motcible, Info_As(*Unarbre_ref)) < 0)
    {
      Child_node = Fg_As(*Unarbre_ref);
      if (Child_node != NULL)
      {
        if (strcmp(Info_As(Child_node), *Motcible) == 0)
        {
          Rot_right(&*Unarbre_ref);
        }
        else
        {
          if (strcmp(*Motcible, Info_As(Child_node)) < 0)
          {
            Grand_child_node = Fg_As(Child_node);
            if ((Grand_child_node != NULL) && (strcmp(Info_As(Grand_child_node), *Motcible) == 0))
            {
              Rot_right(&Child_node);
              Aff_fg_As(*Unarbre_ref, Child_node);
              Rot_right(&*Unarbre_ref);
            };
          }
          else
          {
            if (strcmp(*Motcible, Info_As(Child_node)) > 0)
            {
              Grand_child_node = Fd_As(Child_node);
              if ((Grand_child_node != NULL) && (strcmp(Info_As(Grand_child_node), *Motcible) == 0))
              {
                Rot_left(&Child_node);
                Aff_fg_As(*Unarbre_ref, Child_node);
                Rot_right(&*Unarbre_ref);
              };
            };
          };
        }
      }
      else
      {
        if (strcmp(*Motcible, Info_As(*Unarbre_ref)) > 0)
        {
          Child_node = Fd_As(*Unarbre_ref);
          if (Child_node != NULL)
          {
            if (strcmp(Info_As(Child_node), *Motcible) == 0)
            {
              Rot_left(&*Unarbre_ref);
            }
            else
            {
              if (strcmp(*Motcible, Info_As(Child_node)) > 0)
              {
                Grand_child_node = Fd_As(Child_node);
                if ((Grand_child_node != NULL) && (strcmp(Info_As(Grand_child_node), *Motcible) == 0))
                {
                  Rot_left(&Child_node);
                  Aff_fd_As(*Unarbre_ref, Child_node);
                  Rot_left(&*Unarbre_ref);
                };
              }
              else
              {
                if (strcmp(*Motcible, Info_As(Child_node)) < 0)
                {
                  Grand_child_node = Fg_As(Child_node);
                  if ((Grand_child_node != NULL) && (strcmp(Info_As(Grand_child_node), *Motcible) == 0))
                  {
                    Rot_right(&Child_node);
                    Aff_fd_As(*Unarbre_ref, Child_node);
                    Rot_left(&*Unarbre_ref);
                  };
                };
              };
            };
          };
        };
      };
    };
  };
}
Pointeur_As Find_in_bst(Pointeur_As *Tree, string255 *Wordtofind)
{
  Pointeur_As Find_in_bst2 = NULL;
  Pointeur_As Currentnode = NULL;
  Currentnode = *Tree;
  while ((Currentnode != NULL) && (strcmp(Info_As(Currentnode), *Wordtofind) != 0))
  {
    if (strcmp(*Wordtofind, Info_As(Currentnode)) < 0)
    {
      Currentnode = Fg_As(Currentnode);
    }
    else
    {
      Currentnode = Fd_As(Currentnode);
    };
  };
  Find_in_bst2 = Currentnode;
  return Find_in_bst2;
}
Pointeur_As Find_word(string255 *Words)
{
  Pointeur_As Find_word2 = NULL;
  string2 Firstchar;
  Pointeur_As Foundnode = NULL;
  string2 Rulechary;
  string2 Rulecharz;
  string2 Rulechar_a;
  Firstchar = malloc(2 * sizeof(char));
  Rulechary = malloc(2 * sizeof(char));
  Rulecharz = malloc(2 * sizeof(char));
  Rulechar_a = malloc(2 * sizeof(char));
  Foundnode = NULL;
  strcpy(Rulechary, "Y");
  strcpy(Rulecharz, "Z");
  strcpy(Rulechar_a, "a");
  if (Longchaine(*Words) > 0)
  {
    strcpy(Firstchar, Caract(*Words, 1));
    if (((strcmp(Firstchar, Rulechary) == 0) || (strcmp(Firstchar, Rulecharz) == 0) || (strcmp(Firstchar, Rulechar_a) == 0)))
    {
      Foundnode = Find_in_bst(&Bst1, &*Words);
    }
    else
    {
      if (((strcmp(Firstchar, Rulechary) > 0) || (strcmp(Firstchar, Rulecharz) > 0) || (strcmp(Firstchar, Rulechar_a) > 0)))
      {
        Foundnode = Find_in_bst(&Bst2, &*Words);
      }
      else
      {
        Foundnode = Find_in_bst(&Bst3, &*Words);
      };
    };
  }
  else
  {
    ;
  };
  Find_word2 = Foundnode;
  return Find_word2;
}
void Range_find(Pointeur_As *Node, string255 *W1, string255 *W2, Pointeur_Ls *Result_list)
{
  Pointeur_Ls Temp_node = NULL;
  Pointeur_Ls Temp_list = NULL;
  Pointeur_As _Px1 = NULL;
  Pointeur_As _Px2 = NULL;
  if (*Node != NULL)
  {
    if (strcmp(Info_As(*Node), *W1) >= 0)
    {
      _Px1 = Fg_As(*Node);
      Range_find(&_Px1, &*W1, &*W2, &*Result_list);
    };
    if (((strcmp(Info_As(*Node), *W1) >= 0) && (strcmp(Info_As(*Node), *W2) <= 0)))
    {
      Allouer_Ls(&Temp_node);
      Aff_val_Ls(Temp_node, Info_As(*Node));
      Aff_adr_Ls(Temp_node, NULL);
      if (*Result_list == NULL)
      {
        *Result_list = Temp_node;
      }
      else
      {
        Temp_list = *Result_list;
        while (Suivant_Ls(Temp_list) != NULL)
        {
          Temp_list = Suivant_Ls(Temp_list);
        };
        Aff_adr_Ls(Temp_list, Temp_node);
      };
    };
    if (strcmp(Info_As(*Node), *W2) <= 0)
    {
      _Px2 = Fd_As(*Node);
      Range_find(&_Px2, &*W1, &*W2, &*Result_list);
    }
  };
}
void Range_on_custom_bsts(string255 *W1, string255 *W2, Pointeur_Ls *Combined_results)
{
  Pointeur_Ls Temp_list_bst1_bst2 = NULL;
  Pointeur_Ls Temp_list_bst3 = NULL;
  Pointeur_Ls Temp_list_trav = NULL;
  Pointeur_Ls New_node = NULL;
  Pointeur_Ls Temp_list_end = NULL;
  *Combined_results = NULL;
  Temp_list_bst1_bst2 = NULL;
  Temp_list_bst3 = NULL;
  Range_find(&Bst1, &*W1, &*W2, &Temp_list_bst1_bst2);
  Range_find(&Bst3, &*W1, &*W2, &Temp_list_bst3);
  Temp_list_trav = Temp_list_bst1_bst2;
  Temp_list_end = NULL;
  while (Temp_list_trav != NULL)
  {
    Allouer_Ls(&New_node);
    Aff_val_Ls(New_node, Valeur_Ls(Temp_list_trav));
    Aff_adr_Ls(New_node, NULL);
    if (*Combined_results == NULL)
    {
      *Combined_results = New_node;
      Temp_list_end = *Combined_results;
    }
    else
    {
      Aff_adr_Ls(Temp_list_end, New_node);
      Temp_list_end = Suivant_Ls(Temp_list_end);
    };
    Temp_list_trav = Suivant_Ls(Temp_list_trav);
  };
  Temp_list_trav = Temp_list_bst3;
  while (Temp_list_trav != NULL)
  {
    Allouer_Ls(&New_node);
    Aff_val_Ls(New_node, Valeur_Ls(Temp_list_trav));
    Aff_adr_Ls(New_node, NULL);
    if (*Combined_results == NULL)
    {
      *Combined_results = New_node;
      Temp_list_end = *Combined_results;
    }
    else
    {
      Aff_adr_Ls(Temp_list_end, New_node);
      Temp_list_end = Suivant_Ls(Temp_list_end);
    };
    Temp_list_trav = Suivant_Ls(Temp_list_trav);
  };
}
int Get_depth(Pointeur_As *Tree)
{
  int Get_depth2;
  int Leftdepth;
  int Rightdepth;
  Pointeur_As _Px1 = NULL;
  Pointeur_As _Px2 = NULL;
  if (*Tree == NULL)
  {
    Get_depth2 = 0;
  }
  else
  {
    _Px1 = Fg_As(*Tree);
    Leftdepth = Get_depth(&_Px1);
    _Px2 = Fd_As(*Tree);
    Rightdepth = Get_depth(&_Px2);
    if (Leftdepth > Rightdepth)
    {
      Get_depth2 = Leftdepth + 1;
    }
    else
    {
      Get_depth2 = Rightdepth + 1;
    };
  };
  return Get_depth2;
}
int Count_char(Pointeur_As *Tree, string2 *Lettre)
{
  int Count_char2;
  int Count;
  Pointeur_As _Px1 = NULL;
  Pointeur_As _Px2 = NULL;
  if (*Tree == NULL)
  {
    Count_char2 = 0;
  }
  else
  {
    Count = 0;
    if (Longchaine(Info_As(*Tree)) > 0)
    {
      if (strcmp(Caract(Info_As(*Tree), 1), *Lettre) == 0)
      {
        Count = 1;
      };
    };
    _Px1 = Fg_As(*Tree);
    _Px2 = Fd_As(*Tree);
    Count_char2 = Count + Count_char(&_Px1, &*Lettre) + Count_char(&_Px2, &*Lettre);
  };
  return Count_char2;
}
void Show_stats()
{
  int D0;
  int D1;
  int D2;
  int D3;
  int County0;
  int Countz0;
  int Counta0;
  int County1;
  int Countz1;
  int Counta1;
  int County2;
  int Countz2;
  int Counta2;
  int County3;
  int Countz3;
  int Counta3;
  string2 Chary;
  string2 Charz;
  string2 Char_a;
  Chary = malloc(2 * sizeof(char));
  Charz = malloc(2 * sizeof(char));
  Char_a = malloc(2 * sizeof(char));
  strcpy(Chary, "Y");
  strcpy(Charz, "Z");
  strcpy(Char_a, "a");
  D0 = Get_depth(&Bst0);
  D1 = Get_depth(&Bst1);
  D2 = Get_depth(&Bst2);
  D3 = Get_depth(&Bst3);
  County0 = Count_char(&Bst0, &Chary);
  Countz0 = Count_char(&Bst0, &Charz);
  Counta0 = Count_char(&Bst0, &Char_a);
  County1 = Count_char(&Bst1, &Chary);
  Countz1 = Count_char(&Bst1, &Charz);
  Counta1 = Count_char(&Bst1, &Char_a);
  County2 = Count_char(&Bst2, &Chary);
  Countz2 = Count_char(&Bst2, &Charz);
  Counta2 = Count_char(&Bst2, &Char_a);
  County3 = Count_char(&Bst3, &Chary);
  Countz3 = Count_char(&Bst3, &Charz);
  Counta3 = Count_char(&Bst3, &Char_a);
  printf(" %s", "=== Tree Statistics ===%s\n", reset);
  printf("%sRule Characters: '%s', '%s', '%s'%s\n\n", BYEL, Chary, Charz, Char_a, reset);
  printf("%sBST0 (Standard):%s\n", BGRN, reset);
  printf("  Depth: %s%d%s\n", HCYN, D0, reset);
  printf("  Counts: Y=%s%d%s, Z=%s%d%s, a=%s%d%s\n\n",
         HRED, County0, reset, HGRN, Countz0, reset, HBLU, Counta0, reset);
  printf("%sBST1 (Root Rotation):%s\n", BGRN, reset);
  printf("  Depth: %s%d%s\n", HCYN, D1, reset);
  printf("  Counts: Y=%s%d%s, Z=%s%d%s, a=%s%d%s\n\n",
         HRED, County1, reset, HGRN, Countz1, reset, HBLU, Counta1, reset);
  printf("%sBST2 (Middle Rotation):%s\n", BGRN, reset);
  printf("  Depth: %s%d%s\n", HCYN, D2, reset);
  printf("  Counts: Y=%s%d%s, Z=%s%d%s, a=%s%d%s\n\n",
         HRED, County2, reset, HGRN, Countz2, reset, HBLU, Counta2, reset);
  printf("%sBST3 (Other Words):%s\n", BGRN, reset);
  printf("  Depth: %s%d%s\n", HCYN, D3, reset);
  printf("  Counts: Y=%s%d%s, Z=%s%d%s, a=%s%d%s\n",
         HRED, County3, reset, HGRN, Countz3, reset, HBLU, Counta3, reset);
}
Pointeur_As Find_in_bst_with_path_length(Pointeur_As *Tree, string255 *Wordtofind, int *Pathlength_ref)
{
  Pointeur_As Find_in_bst_with_path_length2 = NULL;
  Pointeur_As Currentnode = NULL;
  int Localpathlength;
  Pointeur_As Foundnoderesult = NULL;
  Currentnode = *Tree;
  Localpathlength = 0;
  Foundnoderesult = NULL;
  *Pathlength_ref = 0;
  while ((Currentnode != NULL) && (Foundnoderesult == NULL))
  {
    Localpathlength = Localpathlength + 1;
    if (strcmp(Info_As(Currentnode), *Wordtofind) == 0)
    {
      Foundnoderesult = Currentnode;
    }
    else
    {
      if (strcmp(*Wordtofind, Info_As(Currentnode)) < 0)
      {
        Currentnode = Fg_As(Currentnode);
      }
      else
      {
        Currentnode = Fd_As(Currentnode);
      };
    };
  };
  *Pathlength_ref = Localpathlength;
  Find_in_bst_with_path_length2 = Foundnoderesult;
  return Find_in_bst_with_path_length2;
}
Pointeur_As Find_word_with_path_length(string255 *Words, int *Pathlength_ref)
{
  Pointeur_As Find_word_with_path_length2 = NULL;
  string2 Firstchar;
  Pointeur_As Foundnoderesult = NULL;
  string2 Rulechary;
  string2 Rulecharz;
  string2 Rulechar_a;
  Firstchar = malloc(2 * sizeof(char));
  Rulechary = malloc(2 * sizeof(char));
  Rulecharz = malloc(2 * sizeof(char));
  Rulechar_a = malloc(2 * sizeof(char));
  Foundnoderesult = NULL;
  *Pathlength_ref = 0;
  strcpy(Rulechary, "Y");
  strcpy(Rulecharz, "Z");
  strcpy(Rulechar_a, "a");
  if (Longchaine(*Words) > 0)
  {
    strcpy(Firstchar, Caract(*Words, 1));
    if (((strcmp(Firstchar, Rulechary) == 0) || (strcmp(Firstchar, Rulecharz) == 0) || (strcmp(Firstchar, Rulechar_a) == 0)))
    {
      Foundnoderesult = Find_in_bst_with_path_length(&Bst1, &*Words, &*Pathlength_ref);
    }
    else
    {
      if (((strcmp(Firstchar, Rulechary) > 0) || (strcmp(Firstchar, Rulecharz) > 0) || (strcmp(Firstchar, Rulechar_a) > 0)))
      {
        Foundnoderesult = Find_in_bst_with_path_length(&Bst2, &*Words, &*Pathlength_ref);
      }
      else
      {
        Foundnoderesult = Find_in_bst_with_path_length(&Bst3, &*Words, &*Pathlength_ref);
      };
    };
  }
  else
  {
    ;
  };
  Find_word_with_path_length2 = Foundnoderesult;
  return Find_word_with_path_length2;
}
void Calculate_avg_search_paths()
{
  FILE *F_data;
  Typestruct1_ss S_buffer;
  string255 Currentword;
  int Pathlen;
  Pointeur_As Foundnodetemp = NULL;
  int I;
  int Totalpath_bst0_succ = 0;
  int Totalpath_custom_succ = 0;
  int Count_succ = 0;
  int Totalpath_bst0_unsucc = 0;
  int Totalpath_custom_unsucc = 0;
  int Count_unsucc = 0;
  int Avg_bst0_succ;
  int Avg_custom_succ;
  int Avg_bst0_unsucc;
  int Avg_custom_unsucc;
  Type_Tss S_S_buffer;
  S_buffer = malloc(sizeof(Typestruct1_ss));
  S_buffer->Champ1 = malloc(255 * sizeof(char));
  S_buffer->Champ2 = malloc(255 * sizeof(char));
  Currentword = malloc(255 * sizeof(char));
  printf("\n%s+==================================+%s\n", HCYN, reset);
  printf("%s|%s           CALCULATING SEARCH PATH LENGTHS                %s|%s\n", HCYN, BHBLK, HCYN, reset);
  printf("%s+==================================+%s\n\n", HCYN, reset);
  printf("%sProcessing successful searches...%s\n", BHYEL, reset);
  Ouvrir_ss(&F_data, "F2.z", "A");
  while (!Finfich_ss(F_data))
  {
    Lireseq_ss(F_data, S_buffer);
    strcpy(Currentword, Struct1_Tss(S_buffer));
    if (Longchaine(Currentword) > 0)
    {
      Count_succ++;
      Foundnodetemp = Find_in_bst_with_path_length(&Bst0, &Currentword, &Pathlen);
      Totalpath_bst0_succ += Pathlen;
      Foundnodetemp = Find_word_with_path_length(&Currentword, &Pathlen);
      Totalpath_custom_succ += Pathlen;
    }
  }
  Fermer_ss(F_data);
  printf("%sProcessing unsuccessful searches...%s\n", BHYEL, reset);
  Ouvrir_ss(&F_data, "F_Unsuccessful.z", "N");
  for (I = 1; I <= 101; ++I)
  {
    S_S_buffer.Champ1 = malloc(255 * sizeof(char));
    strcpy(S_S_buffer.Champ1, Aleachaine(7));
    S_S_buffer.Champ2 = malloc(255 * sizeof(char));
    strcpy(S_S_buffer.Champ2, Aleachaine(7));
    Init_struct_Tss(S_buffer, S_S_buffer);
    Ecrireseq_ss(F_data, S_buffer);
  }
  Fermer_ss(F_data);
  Ouvrir_ss(&F_data, "F_Unsuccessful.z", "A");
  while (!Finfich_ss(F_data))
  {
    Lireseq_ss(F_data, S_buffer);
    strcpy(Currentword, Struct1_Tss(S_buffer));
    if (Longchaine(Currentword) > 0)
    {
      Count_unsucc++;
      Foundnodetemp = Find_in_bst_with_path_length(&Bst0, &Currentword, &Pathlen);
      Totalpath_bst0_unsucc += Pathlen;
      Foundnodetemp = Find_word_with_path_length(&Currentword, &Pathlen);
      Totalpath_custom_unsucc += Pathlen;
    }
  }
  Fermer_ss(F_data);
  if (Count_succ > 0)
  {
    Avg_bst0_succ = Totalpath_bst0_succ;
    Avg_custom_succ = Totalpath_custom_succ;
  }
  else
  {
    Avg_bst0_succ = 0;
    Avg_custom_succ = 0;
  }
  if (Count_unsucc > 0)
  {
    Avg_bst0_unsucc = Totalpath_bst0_unsucc;
    Avg_custom_unsucc = Totalpath_custom_unsucc;
  }
  else
  {
    Avg_bst0_unsucc = 0;
    Avg_custom_unsucc = 0;
  }
  printf("\n%s+=============================================================+%s\n", HCYN, reset);
  printf("%s|%s           AVERAGE SEARCH PATH LENGTH RESULTS            %s|%s\n", HCYN, BHBLK, HCYN, reset);
  printf("\n%s+=============================================================+%s\n", HCYN, reset);
  printf("%s|%s Successful Searches (%s%d%s words from F2.z):%s\n", HCYN, BHGRN, BHYEL, Count_succ, BHGRN, reset);
  printf("%s|%s   BST0 (Standard): %s%d%s\n", HCYN, BWHT, BHYEL, Avg_bst0_succ, reset);
  printf("%s|%s   Custom (BST1/2/3): %s%d%s\n", HCYN, BWHT, BHYEL, Avg_custom_succ, reset);
  printf("%s|%s Unsuccessful Searches (%s%d%s newly generated words):%s\n", HCYN, BHRED, BHYEL, Count_unsucc, BHRED, reset);
  printf("%s|%s   BST0 (Standard): %s%d%s\n", HCYN, BWHT, BHYEL, Avg_bst0_unsucc, reset);
  printf("%s|%s   Custom (BST1/2/3): %s%d%s\n", HCYN, BWHT, BHYEL, Avg_custom_unsucc, reset);
  printf("\n%s+=============================================================+%s\n", HCYN, reset);
}
int Count_words_by_char_category(Pointeur_As *Tree, int *Categorytype, string2 *C1, string2 *C2, string2 *C3)
{
  int Count_words_by_char_category2;
  int Localcount;
  string2 Currentchar;
  bool Isincategory1;
  Pointeur_As _Px1 = NULL;
  Pointeur_As _Px2 = NULL;
  Currentchar = malloc(2 * sizeof(char));
  if (*Tree == NULL)
  {
    Count_words_by_char_category2 = 0;
  }
  else
  {
    Localcount = 0;
    if (Longchaine(Info_As(*Tree)) > 0)
    {
      strcpy(Currentchar, Caract(Info_As(*Tree), 1));
      Isincategory1 = (strcmp(Currentchar, *C1) == 0) || (strcmp(Currentchar, *C2) == 0) || (strcmp(Currentchar, *C3) == 0);
      if (*Categorytype == 1)
      {
        if (Isincategory1)
        {
          Localcount = 1;
        };
      }
      else
      {
        if (*Categorytype == 2)
        {
          if (((strcmp(Currentchar, *C1) > 0) || (strcmp(Currentchar, *C2) > 0) || (strcmp(Currentchar, *C3) > 0)) && (!Isincategory1))
          {
            Localcount = 1;
          };
        }
        else
        {
          if (*Categorytype == 3)
          {
            if ((strcmp(Currentchar, *C1) < 0) && (strcmp(Currentchar, *C2) < 0) && (strcmp(Currentchar, *C3) < 0))
            {
              Localcount = 1;
            };
          };
        };
      };
      _Px1 = Fg_As(*Tree);
      _Px2 = Fd_As(*Tree);
      Count_words_by_char_category2 = Localcount + Count_words_by_char_category(&_Px1, &*Categorytype, &*C1, &*C2, &*C3) + Count_words_by_char_category(&_Px2, &*Categorytype, &*C1, &*C2, &*C3);
    };
  };
  return Count_words_by_char_category2;
}
void Show_recommendation_stats()
{
  string2 Statchar_x = malloc(2 * sizeof(char));
  string2 Statchar_y = malloc(2 * sizeof(char));
  string2 Statchar_z = malloc(2 * sizeof(char));
  string255 Treename = malloc(255 * sizeof(char));
  Pointeur_As Currenttree = NULL;
  int I;
  int _Px1, _Px2, _Px3;
  strcpy(Statchar_x, "X");
  strcpy(Statchar_y, "Y");
  strcpy(Statchar_z, "z");
  printf("\n%s+=============================================================+%s\n", HCYN, reset);
  printf("%s|%s           WORD STATISTICS BY CHARACTER CATEGORY         %s|%s\n", HCYN, BHBLK, HCYN, reset);
  printf("%s+=============================================================+%s\n", HCYN, reset);
  printf("%s|%s Reference Characters: %s'%s', '%s', '%s'%s\n", HCYN, BHYEL, BHGRN, Statchar_x, Statchar_y, Statchar_z, reset);
  for (I = 0; I <= 3; ++I)
  {
    if (I == 0)
    {
      Currenttree = Bst0;
      strcpy(Treename, "BST0 (Standard)");
    }
    else if (I == 1)
    {
      Currenttree = Bst1;
      strcpy(Treename, "BST1 (Root Rotation)");
    }
    else if (I == 2)
    {
      Currenttree = Bst2;
      strcpy(Treename, "BST2 (Middle Rotation)");
    }
    else
    {
      Currenttree = Bst3;
      strcpy(Treename, "BST3 (Other Words)");
    }
    _Px1 = 1;
    int Counts_exact = Count_words_by_char_category(&Currenttree, &_Px1, &Statchar_x, &Statchar_y, &Statchar_z);
    _Px2 = 2;
    int Counts_greater = Count_words_by_char_category(&Currenttree, &_Px2, &Statchar_x, &Statchar_y, &Statchar_z);
    _Px3 = 3;
    int Counts_less = Count_words_by_char_category(&Currenttree, &_Px3, &Statchar_x, &Statchar_y, &Statchar_z);
    printf("%s|%s\n", HCYN, reset);
    printf("%s|%s %s:%s\n", HCYN, BHGRN, Treename, reset);
    printf("%s|%s   Words starting with reference chars: %s%d%s\n", HCYN, BWHT, BHYEL, Counts_exact, reset);
    printf("%s|%s   Words with chars > reference: %s%d%s\n", HCYN, BWHT, BHYEL, Counts_greater, reset);
    printf("%s|%s   Words with chars < reference: %s%d%s\n", HCYN, BWHT, BHYEL, Counts_less, reset);
  }
  printf("%s+===========================================================+%s\n", HCYN, reset);
}
void tp2()
{
  printf("\n\n\n");
    printf("                 OOOOOOOOOOOOOOOOOO               OOOOOOOOOOOOOOOOOO      "CYN"  YYYYYYYYYYYYYYYY                  \n"reset);
    printf("             OOOOOOOOOOOOOOOOOOOOOOOOOO       OOOOOOOOOOOOOOOOOOOOOOOOOO  "CYN"  YYYYYYYYYYYYYYYY                  \n"reset);
    printf("            OOOOOOOOOOOOOOOOOOOOOOOOOOOOO   OOOOOOOOOOOOOOOOOOOOOOOOOOOOO  "CYN" YYYYYYYYYYYYYYYY                  \n"reset);
    printf("           OOOOOOOOOOOOOO  OOOOOOOOOOOOOO   OOOOOOOOOOOOOO  OOOOOOOOOOOOO  "CYN" YYYYYYYYYYYYYYYY                  \n"reset);
    printf("           OOOOOOOOOOOOOO  OOOOOOOOOOOOOO   OOOOOOOOOOOOOO  OOOOOOOOOOOOO "CYN"  YYYYYYYYYYYYYYYY                  \n"reset);
    printf("           OOOOOOOOOOOOOO  OOOOOOOOOOOOOO   OOOOOOOOOOOOOO  OOOOOOOOOOOOO  "CYN"  YYYY       YYYYYY                \n"reset);
    printf("           OOOOOOOOOOOOOO  OOOOOOOOOOOOOO   OOOOOOOOOOOOOO  OOOOOOOOOOOOO   "CYN"  YYYYYYYYYYYYYYYYYYYYY           \n"reset);
    printf("            OOOOOOOOOOOOO  OOOOOOOOOOOOOO   OOOOOOOOOOOOOO  OOOOOOOOOOOOO                                      \n"reset);
    printf("           OOOOOOOOOOOOOO  OOOOOOOOOOOOOO   OOOOOOOOOOOOOO  OOOOOOOOOOOOO    OOOOOOOOOOOOO                    \n");
    printf("           OOOOOOOOOOOOOO  OOOOOOOOOOOOOO   OOOOOOOOOOOOOO  OOOOOOOOOOOOO    OOOOOOOOOOOOO                    \n");
    printf("           OOOOOOOOOOOOOO  OOOOOOOOOOOOOO   OOOOOOOOOOOOOO  OOOOOOOOOOOOO    OOOOOOOOOOOOO                     \n");
    printf("           OOOOOOOOOOOOOO  OOOOOOOOOOOOOO   OOOOOOOOOOOOOO                   OOOOOOOOOOOOO                    \n");
    printf("           OOOOOOOOOOOOOOOOOOOOOOOOOOOOOO   OOOOOOOOOOOOOOOOOOOOOOOOOOOOO    OOOOOOOOOOOOO                    \n");
    printf("           OOOOOOOOOOOOOOOOOOOOOOOOOOOOOO   OOOOOOOOOOOOOOOOOOOOOOOOOOOOO    OOOOOOOOOOOOO                    \n");
    printf("           OOOOOOOOOOOOOOOOOOOOOOOOOOOOOO   OOOOOOOOOOOOOOOOOOOOOOOOOOOOO    OOOOOOOOOOOOO                    \n");
    printf("           OOOOOOOOOOOOOO                                   OOOOOOOOOOOOO    OOOOOOOOOOOOO                    \n");
    printf("           OOOOOOOOOOOOOO  OOOOOOOOOOOOOO   OOOOOOOOOOOOOO  OOOOOOOOOOOOO    OOOOOOOOOOOOO                    \n");
    printf("           OOOOOOOOOOOOOO  OOOOOOOOOOOOOO   OOOOOOOOOOOOOO  OOOOOOOOOOOOO    OOOOOOOOOOOOO                    \n");
    printf("           OOOOOOOOOOOOOO  OOOOOOOOOOOOOO   OOOOOOOOOOOOOO  OOOOOOOOOOOOO    OOOOOOOOOOOOO                    \n");
    printf("           OOOOOOOOOOOOOO  OOOOOOOOOOOOOO   OOOOOOOOOOOOOO  OOOOOOOOOOOOO    OOOOOOOOOOOOO                    \n");
    printf("           OOOOOOOOOOOOOO  OOOOOOOOOOOOOO   OOOOOOOOOOOOOO  OOOOOOOOOOOOO    OOOOOOOOOOOOO                    \n");
    printf("           OOOOOOOOOOOOOO  OOOOOOOOOOOOOO   OOOOOOOOOOOOOO  OOOOOOOOOOOOO    OOOOOOOOOOOOO                    \n");
    printf("            OOOOOOOOOOOOOOOOOOOOOOOOOOOO     OOOOOOOOOOOOOOOOOOOOOOOOOOOO    OOOOOOOOOOOOO                    \n");
    printf("             OOOOOOOOOOOOOOOOOOOOOOOOOO       OOOOOOOOOOOOOOOOOOOOOOOOOO     OOOOOOOOOOOOO                    \n");
    Sleep(3000); 
    system("cls"); 

     
     printf("\t\t\t\t          "YEL"        Algerian Democratic Republic                  \n"reset);
     printf("\t\t\t\t     "YEL"   Ministry of Higher Education and Scientific Research\n\n\n"reset);
     printf("\t\t\t\t    "GRN" _______________________________________________________\n"reset);
     printf("\t\t\t\t   "GRN" |      "CYN"  _______     _______     _                    "GRN"  |\n"reset);
     printf("\t\t\t\t    "GRN"|      "CYN" |  _____|   |  _____|   | | "YEL" %ccole nationale  "GRN"  |\n"reset, 130);
     printf("\t\t\t\t  "GRN"  |      "CYN" | |_____    | |_____    | |                    "GRN" |\n"reset);
     printf("\t\t\t\t  "GRN"  |      "CYN" |  _____|   |_____  |   | | "YEL" sup%crieure       "GRN"  |\n"reset, 130);
     printf("\t\t\t\t   "GRN" |      "CYN" | |_____     _____| |   | |                    "GRN" |\n"reset);
     printf("\t\t\t\t   "GRN" |      "CYN" |_______|   |_______|   |_| "YEL" d'informatique    "GRN" |\n"reset);
     printf("\t\t\t\t   "GRN" |_______________________________________________________|\n\n\n"reset);
     Sleep(3000); 
     system("cls"); 
 
     
     printf("\t\t\t\t\t"YEL"CPI - First Year - University Year 2024/2025 \n\n\n"reset);
     printf("\t\t\t\t "GRN"___________________________________________________________________\n"reset);
     printf("\t\t\t\t"GRN"|                                                                   |\n"reset);
     printf("\t\t\t\t"GRN"| "reset"BY          :           MOULAHCENE ABDELMOUNAIM                 "GRN"  |\n"reset);
     printf("\t\t\t\t"GRN"|  "reset"                       ALEM MOHAMED ADEL                      "GRN"   |\n"reset);
     printf("\t\t\t\t"GRN"|                                                                   |\n"reset);
     printf("\t\t\t\t"GRN"|   "reset"        SECTION : B           GROUPE: 05                 "GRN"       |\n"reset);
     printf("\t\t\t\t"GRN"|___________________________________________________________________|\n\n"reset);
     Sleep(3000); 
     system("cls");
}
int main(int argc, char *argv[])
{
  tp2();
  srand(time(NULL));
  Search_word = malloc(255 * sizeof(char));
  Mot1 = malloc(255 * sizeof(char));
  Mot2 = malloc(255 * sizeof(char));
  Bst0 = NULL;
  Bst1 = NULL;
  Bst2 = NULL;
  Bst3 = NULL;
  Gen_words();
  Make_bsts();
  Choix = -1;
  while (Choix != 10)
  {
    clearScreen();
    printf("\n\t\t\t\t%s+==================================+%s\n", HCYN, reset);
    printf("\t\t\t\t%s|%s           %sMAIN MENU%s              %s|%s\n", HCYN, BHBLK, BWHT, BHBLK, HCYN, reset);
    printf("\t\t\t\t%s+==================================+%s\n", HCYN, reset);
    printf("\t\t\t\t%s|%s %s1.%s Display BST1 (Y/Z/a root)     %s|%s\n", HCYN, BWHT, BHYEL, BWHT, HCYN, reset);
    printf("\t\t\t\t%s|%s %s2.%s Display BST2 (Y/Z/a middle)   %s|%s\n", HCYN, BWHT, BHYEL, BWHT, HCYN, reset);
    printf("\t\t\t\t%s|%s %s3.%s Display BST3 (other root)     %s|%s\n", HCYN, BWHT, BHYEL, BWHT, HCYN, reset);
    printf("\t\t\t\t%s|%s %s4.%s Search for a word             %s|%s\n", HCYN, BWHT, BHYEL, BWHT, HCYN, reset);
    printf("\t\t\t\t%s|%s %s5.%s Search word range             %s|%s\n", HCYN, BWHT, BHYEL, BWHT, HCYN, reset);
    printf("\t\t\t\t%s|%s %s6.%s Display tree depths           %s|%s\n", HCYN, BWHT, BHYEL, BWHT, HCYN, reset);
    printf("\t\t\t\t%s|%s %s7.%s Display character counts      %s|%s\n", HCYN, BWHT, BHYEL, BWHT, HCYN, reset);
    printf("\t\t\t\t%s|%s %s8.%s Calculate search paths        %s|%s\n", HCYN, BWHT, BHYEL, BWHT, HCYN, reset);
    printf("\t\t\t\t%s|%s %s9.%s Display word statistics       %s|%s\n", HCYN, BWHT, BHYEL, BWHT, HCYN, reset);
    printf("\t\t\t\t%s|%s %s10.%s Exit                         %s|%s\n", HCYN, BWHT, BHYEL, BWHT, HCYN, reset);
    printf("\t\t\t\t%s+==================================+%s\n", HCYN, reset);
    printf("\t\t\t\t\n%sEnter your choice: %s", BHYEL, reset);
    scanf("\t\t\t\t%d", &Choix);
    getchar();
    clearScreen();
    switch (Choix)
    {
    case 1:
      printf("\n%s=== BST1 (inorder traversal) ===%s\n\n", BBLU, reset);
      Show_bst(&Bst1);
      printf("\n");
      break;
    case 2:
      printf("\n%s=== BST2 (inorder traversal) ===%s\n\n", BBLU, reset);
      Show_bst(&Bst2);
      printf("\n");
      break;
    case 3:
      printf("\n%s=== BST3 (inorder traversal) ===%s\n\n", BBLU, reset);
      Show_bst(&Bst3);
      printf("\n");
      break;
    case 4:
      printf("\n%sEnter a word to search: %s", BYEL, reset);
      scanf("%[^\n]", Search_word);
      getchar();
      Search_result = Find_word(&Search_word);
      if (Search_result != NULL)
      {
        printf("\n%sWord found: %s%s%s\n", BGRN, BBLU, Info_As(Search_result), reset);
      }
      else
      {
        printf("\n%sWord not found.%s\n", BRED, reset);
      }
      break;
    case 5:
      printf("\n%sEnter the lower bound (Word1): %s", BYEL, reset);
      scanf("%[^\n]", Mot1);
      getchar();
      printf("%sEnter the upper bound (Word2): %s", BYEL, reset);
      scanf("%[^\n]", Mot2);
      getchar();
      Serach_result_list = NULL;
      Range_on_custom_bsts(&Mot1, &Mot2, &Serach_result_list);
      printf("\n%sWords in range [%s, %s]:%s\n\n", BBLU, Mot1, Mot2, reset);
      while (Serach_result_list != NULL)
      {
        printf("%s%s%s\n", BGRN, Valeur_Ls(Serach_result_list), reset);
        Serach_result_list = Suivant_Ls(Serach_result_list);
      }
      break;
    case 6:
      printf("\n%s=== Tree Depths ===%s\n\n", BBLU, reset);
      printf("%sBST0 (Standard): %s%d%s\n", BGRN, HCYN, Get_depth(&Bst0), reset);
      printf("%sBST1: %s%d%s\n", BGRN, HCYN, Get_depth(&Bst1), reset);
      printf("%sBST2: %s%d%s\n", BGRN, HCYN, Get_depth(&Bst2), reset);
      printf("%sBST3: %s%d%s\n", BGRN, HCYN, Get_depth(&Bst3), reset);
      break;
    case 7:
      Show_stats();
      break;
    case 8:
      Calculate_avg_search_paths();
      break;
    case 9:
      Show_recommendation_stats();
      break;
    case 10:
      printf("\n%sExiting program...%s\n", BGRN, reset);
      break;
    default:
      printf("\n%sInvalid choice. Please try again.%s\n", BRED, reset);
    }
    if (Choix != 10)
    {
      pressKeyToContinue();
    }
  }
  return 0;
}