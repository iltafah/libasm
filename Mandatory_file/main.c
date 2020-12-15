/*
==========================================================                      ;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
|| 1337    133713371337    133713371337    133713371337 ||                      ;;                                                               ;;
|| 1337            1337            1337           1337  ||                      ;; LL      IIIIIIII  BBBBBBB     AAA      SSSSSS   MM        MM  ;;
|| 1337            1337            1337          1337   ||                      ;; LL         II     BB    BB  AA   AA    SS    S  MM MM  MM MM  ;;
|| 1337    133713371337    133713371337         1337    ||                      ;; LL         II     BBBBBBB   AA   AA      SS     MM   MM   MM  ;;
|| 1337            1337            1337        1337     ||                      ;; LL         II     BB    BB  AAAAAAA   S    SS   MM        MM  ;;
|| 1337            1337            1337       1337      ||                      ;; LLLLLLL IIIIIIII  BBBBBBB   AA   AA    SSSSS    MM        MM  ;;
|| 1337    133713371337    133713371337      1337       ||                      ;;                                                               ;;
==========================================================                      ;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;   
*/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <fcntl.h>
#include <errno.h>

#define RED   "\x1B[31m"
#define GRN   "\x1B[32m"
#define YEL   "\x1B[33m"
#define BLU   "\x1B[34m"
#define MAG   "\x1B[35m"
#define CYN   "\x1B[36m"
#define WHT   "\x1B[37m"
#define RESET "\x1B[0m"

#define F_H     "/*-----------------------------------------------------------------------*/"
#define S_H     "///////////////////////////////////////////////////////////////////////////"
#define T1_H    "/*-------------------------------"
#define T2_H    "-------------------------------*/"

char    *ft_strdup(const char *s1);
char    *ft_strcpy(char *dst, const char *src);
int     ft_strcmp(const char *s1, const char *s2);
size_t  ft_strlen(const char *s);
ssize_t ft_write(int fildes, const void *buf, size_t nbyte);
ssize_t ft_read(int fildes, void *buf, size_t nbyte);

void    print_spaces(int num)
{
    while (num-- > 0)
        printf(" ");
}

int     main()
{
    char    *sprint_buff = calloc(sizeof(char), 1337 + 1);
    int     sprint_ret;
    /*-----------------------------------------------------------------------*/
    ///////////////////////////////////////////////////////////////////////////
    /********************************ft_read**********************************/
    int     fd = open("./Mandatory_file/main.c", O_RDONLY);                    //you should compile this main in Makefile directory
    char    *buff = calloc(sizeof(char), 1337 + 1);
    int     ret = ft_read(fd, buff, 1337);
    int     errno_ret = errno;

    printf(CYN "%s\n",buff+3);
    printf(RESET);

    printf(GRN "%s\t%s\n%s\t%s\n%s%s%s\t%s%s%s\n",F_H,F_H,S_H,S_H,T1_H,"-ft_read-",T2_H,T1_H,"---read--",T2_H);
    printf(RESET);

    sprint_ret = snprintf(sprint_buff, 1337,"ret value = %d,  error value = %d -> %s", ret, errno_ret, strerror(errno_ret));
    printf("%s",sprint_buff);
    print_spaces(80 - sprint_ret);

    ret = read(fd, buff, 1337);
    errno_ret = errno;
    printf("ret value = %d,  error value = %d -> %s\n", ret, errno_ret, strerror(errno_ret));
    
    printf(GRN "%s\t%s\n%s\t%s\n%s%s%s\t%s%s%s\n",F_H,F_H,S_H,S_H,T1_H,"ft_strdup",T2_H,T1_H,"--strdup-",T2_H);
    printf(RESET);
    /*-----------------------------------------------------------------------*/
    ///////////////////////////////////////////////////////////////////////////
    /********************************ft_strdup********************************/
    char    str[12] = "hi nice one";

    sprint_ret = snprintf(sprint_buff, 1337, "|%s|",ft_strdup("hello world"));
    printf("%s",sprint_buff);
    print_spaces(80 - sprint_ret);
    
    printf("|%s|\n",strdup("hello world"));
    
    char    *xd;
    char    *xd1;

    xd = ft_strdup(str);
    sprint_ret = snprintf(sprint_buff, 1337, "|%s|",xd);
    printf("%s",sprint_buff);
    print_spaces(80 - sprint_ret);
    
    xd1 = strdup(str);
    printf("|%s|\n",xd1);
    
    printf(GRN "%s\t%s\n%s\t%s\n%s%s%s\t%s%s%s\n",F_H,F_H,S_H,S_H,T1_H,"ft_strcpy",T2_H,T1_H,"--strcpy-",T2_H);
    printf(RESET);
    /*-----------------------------------------------------------------------*/
    ///////////////////////////////////////////////////////////////////////////
    /********************************ft_strcpy********************************/
    char    src[22] = "omae wa mou shindeiru";
    char    msg[15] = "NAAAaaaaaNI";
    char    *dst1 = malloc(sizeof(char) * 22);
    char    *dst2 = malloc(sizeof(char) * 22);

    sprint_ret = snprintf(sprint_buff, 1337, "|%s|", ft_strcpy(dst1,src));
    printf("%s",sprint_buff);
    print_spaces(80 - sprint_ret);

    printf("|%s|\n", strcpy(dst2,src));
    
    free(dst1);
    free(dst2);

    dst1 = malloc(sizeof(char) * 16);
    dst2 = malloc(sizeof(char) * 16);

    ft_strcpy(dst1, msg);
    strcpy(dst2, msg);

    sprint_ret = snprintf(sprint_buff, 1337, "|%s|",dst1);
    printf("%s",sprint_buff);
    print_spaces(80 - sprint_ret);

    printf("|%s|\n",dst2);
    
    printf(GRN "%s\t%s\n%s\t%s\n%s%s%s\t%s%s%s",F_H,F_H,S_H,S_H,T1_H,"ft_write-",T2_H,T1_H,"--write--",T2_H);
    printf(RESET);
    printf("\n");
    /*-----------------------------------------------------------------------*/
    ///////////////////////////////////////////////////////////////////////////
    /********************************ft_write*********************************/
    int     ret2;
    char    write_msg[] = "Za Warudo";
    int     msg_len = strlen(write_msg);

    ret = ft_write(1, write_msg, msg_len);
    for (int i = 80 - msg_len; i > 0; i--)
        write(1," ",1);
    ret2 = write(1, write_msg, msg_len);

    sprint_ret = snprintf(sprint_buff, 1337, "\nret value = %d,  error value = %d -> %s", ret, errno, strerror(errno));
    printf("%s",sprint_buff);
    print_spaces(80 - sprint_ret);

    printf("\tret value = %d,  error value = %d -> %s\n", ret, errno, strerror(errno));
    
    printf(GRN "%s\t%s\n%s\t%s\n%s%s%s\t%s%s%s\n",F_H,F_H,S_H,S_H,T1_H,"ft_strlen",T2_H,T1_H,"--strlen-",T2_H);
    printf(RESET);
    /*-----------------------------------------------------------------------*/
    ///////////////////////////////////////////////////////////////////////////
    /********************************ft_strlen********************************/
    char    ecole[1337 + 1] = {0};
    for (int i = 0; i <= 1337; i+=4)
    {
        ecole[i + 0] = '1';
        ecole[i + 1] = '3';
        ecole[i + 2] = '3';
        ecole[i + 3] = '7';
    }
    ecole[1337] = '\0';
    sprint_ret = snprintf(sprint_buff, 1337, "len = |%zu|",ft_strlen(ecole));
    printf("%s",sprint_buff);
    print_spaces(80 - sprint_ret);
    printf("len = |%zu|\n",strlen(ecole));
   
    printf(GRN "%s\t%s\n%s\t%s\n%s%s%s\t%s%s%s\n",F_H,F_H,S_H,S_H,T1_H,"ft_strcmp",T2_H,T1_H,"--strcmp-",T2_H);
    printf(RESET);
    /*-----------------------------------------------------------------------*/
    ///////////////////////////////////////////////////////////////////////////
    /********************************ft_stcmp********************************/
    char    cmp1[] = "Wtf";
    char    cmp2[] = "Wth";
    sprint_ret = snprintf(sprint_buff, 1337, "\"%s\" \"%s\" ==> |%d|",cmp1, cmp2, ft_strcmp(cmp1, cmp2));
    printf("%s",sprint_buff);
    print_spaces(80 - sprint_ret);

    printf("\"%s\" \"%s\" ==> |%d|\n",cmp1, cmp2, strcmp(cmp1, cmp2));
       
    printf(GRN "%s\t%s\n%s\t%s\n%s%s%s\t%s%s%s\n",F_H,F_H,S_H,S_H,T1_H,"-ft_end--",T2_H,T1_H,"---end---",T2_H);
    printf(RESET);
    /*-----------------------------------------------------------------------*/
    ///////////////////////////////////////////////////////////////////////////
    /**********************************END************************************/
}