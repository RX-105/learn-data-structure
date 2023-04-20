#define MAXLEN 255

typedef struct {
    char ch[MAXLEN];
    int length;
} SString;

typedef struct {
    char *ch;
    int length;
} HString;

void StrAssign(SString *S, char *chars, int length);
void StrCpy(SString *src, SString *dest);
int StrEmpty(SString *S);
int StrCompare(SString *s1, SString *s2);
int StrLength(SString *S);
void SubString(SString *src, SString *dest, int pos, int length);
void ConCat(SString *dest, SString *src1, SString *src2);
int Index(SString *S, SString *T);
void ClearString(SString *T);
void DestroyString(SString *T);
