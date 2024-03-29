#include "SString.h"
#include "string.h"
#include "stdlib.h"
#include "stdio.h"

void StrAssign(SString *S, char *chars, int length) {
  for (int i = 0; i < length; i++) {
    S->ch[i] = chars[i];
  }
  S->length = length;
}
void StrCpy(SString *src, SString *dest) {
  strcpy(dest->ch, src->ch);
  dest->length = src->length;
}
int StrEmpty(SString *S) {
  return S->length == 0;
}
int StrCompare(SString *s1, SString *s2) {
  return strcmp(s1->ch, s2->ch);
}
int StrLength(SString *S) {
  return S->length;
}
void SubString(SString *src, SString *dest, int pos, int length) {
  for (int i = 0; i < length; i++) {
    dest->ch[i] = src->ch[pos + i];
  }
  dest->length = length;
}
void ConCat(SString *dest, SString *src1, SString *src2) {
  if (src1->length + src2->length > MAXLEN) {
    return;
  }
  dest->length = src1->length + src2->length;
  strcat(dest->ch, src1->ch);
  strcat(dest->ch, src2->ch);
}
int Index(SString *S, SString *T) {
  int i = 0, j = 0;
  while (i < S->length && j < T->length) {
    if (S->ch[i] == T->ch[j]) {
      ++i; ++j;
    } else {
      i = i - j + 1; j = 0;
    }
  }
  if (j >= T->length)
    return i - T->length;
  else
    return 0;
}
void GetNext(SString *T, int *next) {
  // 如果字符串下标从0开始，i、j和next[0]都要相应减一
  int i = 1, j = 0;
  next[0] = 0;
  while (i < T->length) {
    if (j == -1 || T->ch[i] == T->ch[j]) {
      i++; j++;
      next[i] = j;
    } else {
      j = next[j];
    }
  }
}
int Index_KMP(SString *S, SString *T, int *next) {
  GetNext(S, next);
  int i = 0, j = 0;
  while (i < S->length && j < T->length) {
    if (j == 0 || S->ch[i] == T->ch[j]) {
      i++; j++;
    } else
      j = next[j];
  }
  if (j >= T->length)
    return i - T->length;
  else
    return 0;
}
void ClearString(SString *T) {
  T->length = 0;
}
void DestroyString(SString *T) {
  free(T->ch);
}