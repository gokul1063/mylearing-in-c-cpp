#include <stdio.h>
#include <string.h>

int max(int a, int b) { return (a > b) ? a : b; }

#define MAX 1000

int lcs_rec(const char *s1, const char *s2, int m1, int m2,
            int memo[MAX][MAX]) {
  if (m1 == 0 || m2 == 0)
    return 0;

  if (memo[m1][m2] != -1)
    return memo[m1][m2];

  if (s1[m1 - 1] == s2[m2 - 1])
    return memo[m1][m2] = 1 + lcs_rec(s1, s2, m1 - 1, m2 - 1, memo);
  else
    return memo[m1][m2] = max(lcs_rec(s1, s2, m1 - 1, m2, memo),
                              lcs_rec(s1, s2, m1, m2 - 1, memo));
}

int lcs(char s1[], char s2[]) {
  int m1 = strlen(s1);
  int m2 = strlen(s2);

  int memo[MAX][MAX];

  for (int i = 0; i < 1000; i++) {
    for (int j = 0; j < 1000; j++) {
      memo[i][j] = -1;
    }
  }

  return lcs_rec(s1, s2, m1, m2, memo);
}

int main() {
  char s1[50];
  char s2[50];

  printf("Enter s1 and s2 \n");

  scanf("%s", s1);
  scanf("%s", s2);

  printf("lcs : %d \n", lcs(s1, s2));
}
