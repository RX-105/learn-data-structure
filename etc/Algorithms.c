#include "stdio.h"
#include "math.h"
#include "../chapter3/SqStack.h"

#define MAX_ITERS 100

//void dec2bin(int src, char *dst) {
//  SqStack st;
//  InitStack(&st);
//  int len = 0;
//  while (src != 0) {
//    int remainder = src % 2;
//    src /= 2;
//    Push(&st, remainder);
//    len++;
//  }
//  for (int i = 0; i < len; i++) {
//    int x;
//    Pop(&st, &x);
//    dst[i] = (char)x;
//  }
//}

//void dec2bin(int src, char *dst) {
//  char tmp[100]; // 临时保存余数结果
//  int ti = 0, di = 0;
//  // 连续模二除法
//  while (src != 0) {
//    signed char remainder = (char) ((src % 2) ? '1' : '0');
//    src /= 2;
//    tmp[ti++] = remainder;
//  }
//  // 倒序输出
//  while (ti != 0) {
//    dst[di++] = tmp[--ti];
//  }
//  dst[di] = '\0';
//}

void dec2bin(int src, char *dst) {
  for(int i=15;i>=0;i--)
    dst[15-i] = ((src & (1<<i)) ? '1' : '0');
  dst[16] = '\0'; // 加上终止符防止输出无关字符
}

// 根据给定的基数base和偏移offset，将num转化为base+1进制数，并存储到result中
// 常用的数值对有：
// 二进制：base=1, offset=1
// 八进制：base=7, offset=3
// 十六进制：base=15, offset=4
// 不能用于转换成十进制数，使用itoa或sprintf
void trans(int num, int base, int offset, char *result) {
  if (num == 0) {
    *result = '\0';
    return;
  }

  char serials[] = {
      '0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'A',
      'B', 'C', 'D', 'E', 'F'};
  char buffer[32];
  int position = sizeof(buffer) / sizeof(char);
  while (num != 0) {
    int temp = num & base;
    buffer[--position] = serials[temp];
    num = num >> offset;
  }
  for (int i = position; i < sizeof(buffer) / sizeof(char); i++) {
    *(result++) = buffer[i];
  }
}

int priority(char op) {
  if (op == '*' || op == '/')
    return 2;
  if (op == '+' || op == '-')
    return 1;
  if (op == '(')
    return 0;
}
int isdigit(char ch) {
  return ch >= '0' && ch <= '9';
}
void InfixToPostfix(const char *str, int n) {
  SqStack st;
  InitStack(&st);
  for (int i = 0; i < n; i++) {
    char ch = str[i];
    if (isdigit(ch))//数字直接入栈
      printf("%c ", ch);
    else {
      if (StackEmpty(&st) || ch == '(')// 1.栈空或左括号，直接入栈
        Push(&st, ch);
      else if (ch == ')') {// 2.右括号，不断弹出直到遇到左括号
        char tmp;
        Pop(&st, &tmp);//不保留括号
        while (tmp != '(') {
          printf("%c ", tmp);
          Pop(&st, &tmp);
        }
      } else { // 3.其他符号，比较优先级
        char instack;
        // 插入当前时，需要保证栈顶优先级小于当前优先级，比如栈顶+，当前*，可以插入
        while (!StackEmpty(&st)) {
          GetTop(&st, &instack);
          if (priority(ch) <= priority(instack)) { // 栈顶大于当前时，输出栈顶
            printf("%c ", instack);
            Pop(&st, &instack);
          } else { // 栈顶小于当前，可以插入了
            break;
          }
        }
        Push(&st, ch);
      }
    }
  }
  while (!StackEmpty(&st)) {
    char ch;
    Pop(&st, &ch);
    printf("%c", ch);
  }
}

double f(double x) {
  return (exp(x) + x);
//  return pow(x, 2);
}

double df(double x) {
  return (exp(x) + 1);
//  return (2 * x);
}

double newton_iter(double x) {
  return (x - (f(x) / df(x)));
}

double get_root_newton(double x) {
  double x0 = x, x1, eps = 1e-6, diff;
  int iters = 0;
  do {
    iters++;
    x1 = newton_iter(x0);
    diff = x1 - x0;
    x0 = x1;
  } while (diff >= eps && iters < MAX_ITERS);
  return x1;
}

double get_root_bin(double a, double b) {
  double c = (a + b) / 2;
  do {
    if (f(a) * f(c) > 0) a = c;
    else b = c;
    c = (a + b) / 2;
  } while (fabs(f(c)) > 1e-6 && fabs(a - b) > 1e-6);
  return c;
}

