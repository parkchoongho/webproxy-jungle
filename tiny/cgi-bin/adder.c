/*
 * adder.c - a minimal CGI program that adds two numbers together
 */
/* $begin adder */
#include "csapp.h"

int main(void) {
  char *buf, *p, *arg1p, *arg2p, *method;
  char arg1[MAXLINE], arg2[MAXLINE], content[MAXLINE];
  int n1 = 0, n2 = 0;

  /* Extract the two arguments */
  if ((buf = getenv("QUERY_STRING")) != NULL) {
    p = strchr(buf, '&');
    *p = '\0';
    strcpy(arg1, buf);
    strcpy(arg2, p + 1);
    arg1p = strchr(arg1, '=');
    *arg1p = '\0';
    arg2p = strchr(arg2, '=');
    *arg2p = '\0';
    strcpy(arg1, arg1p + 1);
    strcpy(arg2, arg2p + 1);

    n1 = atoi(arg1);
    n2 = atoi(arg2);
  }

  method = getenv("REQUEST_METHOD"); 


  /* Make the response body */
  // sprintf(content, "QUERY_STRING=%s\r\n", buf);
  sprintf(content, "%sWelcome to add.com: ", content);
  sprintf(content, "%sTHE Internet addition portal.\r\n<p>", content);
  sprintf(content, "%sThe answer is: %d + %d = %d\r\n<p>", content, n1, n2, n1 + n2);
  sprintf(content, "%sThanks for visiting!\r\n", content);

  /* Generate the HTTP response */
  printf("Connection: close\r\n");
  printf("Content-length: %d\r\n", (int)strlen(content));
  printf("Content-type: text/html\r\n\r\n");
  if (!strcasecmp(method, "GET")) printf("%s", content);
  fflush(stdout);

  exit(0);
}
/* $end adder */
