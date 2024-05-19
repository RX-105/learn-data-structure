
#ifndef LEARN_DATA_STRUCTURE_ETC_ALGORITHMS_H_
#define LEARN_DATA_STRUCTURE_ETC_ALGORITHMS_H_

void dec2bin(int src, char *dst);
void trans(int num, int base, int offset, char *result);

int priority(char op);
void InfixToPostfix(const char *str, int n);

double get_root_newton(double x);
double get_root_bin(double a, double b);

#endif //LEARN_DATA_STRUCTURE_ETC_ALGORITHMS_H_
