#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pwd.h>
#include <unistd.h>
#include <sys/types.h>

char * who_am_i(void);
int main(int argc, char *argv[])
{
  //requires file of all authorized users for a better version of Auto users
  if(argc == 1)
    {
      printf("please give users file\n");
    }

//banner not final might need a better version
  printf("===========================================================================================\n");
  printf("=  ======================================        =====================   ============  ====\n");
  printf("=  ======================================  =========================   =   =========   ====\n");
  printf("=  ======================================  ========================   ===   =========  ====\n");
  printf("=  ========  ==  = ===  =  ==  =  =======  ========  ==  =  ============   ==========  ====\n");
  printf("=  ============     ==  =  ==  =  =======      ========  =  ===========   ===========  ====\n");
  printf("=  ========  ==  =  ==  =  ===   ========  ========  ===   ===========   ============  ====\n");
  printf("=  ========  ==  =  ==  =  ===   ========  ========  ===   ==========   =============  ====\n");
  printf("=  ========  ==  =  ==  =  ==  =  =======  ========  ==  =  ========   =======  =====  ====\n");
  printf("=        ==  ==  =  ===    ==  =  =======  ========  ==  =  =======        ===  ===      ==\n");
  printf("===========================================================================================\n");
  printf("\n");
  printf("\n");
  printf("\n");

  char *user;
  user = (char *)malloc(sizeof(char) * 10);
  user = who_am_i();
  int compare = strcmp(user,"root");
  free(user);
  if(compare==0)
  {

  }
  else
  {
    printf("use as root\n");
  }
}
//modified version of whoami command to return string instead of printing
char * who_am_i(void)
  {
    struct passwd *pw;
    char *user = NULL;

    pw = getpwuid(geteuid());
    if(pw)
      user = pw->pw_name;
    else if ((user=getenv("USER"))==NULL)
    {
        return "1";
    }
    return user;
  }
