//Azret Missirov
//29512170
#include "strlib.h"
#include <stdio.h>
 #include <string.h>

int test_memchr_1(){
    //test1
    const char str[] = "http://www.tutorialspoint.com";
    const char ch = '.';
    char *ret = ics53_memchr(str, ch, ics53_strlen(str));
    return ret == str + 10;
}

int test_memchr_2(){
    const char str[] = "http://www.tutorialspoint.com";
    const char ch = '?';
    char *ret = ics53_memchr(str, ch, ics53_strlen(str));
    return ret == NULL;
}

int test_memchr_3(){
    const char str[] = "http://www.tutorialspoint.com";
    const char ch = 'c';
    char *ret = ics53_memchr(str, ch, 12);
    return ret == NULL;
}

int test_memchr(){
    int score = 15;
    
    if (!test_memchr_1())
        score -= 5;
    if (!test_memchr_2())
        score -= 5;
    if (!test_memchr_3())
        score -= 5;
    return score;
}

////////////////////////////MEMCMP///////////////////////////////////

int test_memcmp_1(){
    char str1[] = "http://www.tutorialspoint.com";
    char str2[] = "http://www.tutorialspoint.com";
    int ret;
    ret = ics53_memcmp(str1, str2, ics53_strlen(str1));
    return ret == 0;
}

int test_memcmp_2(){
    char str1[] = "http://www.tutorialspoint.com";
    char str2[] = "http://www.tutzrialspoint.com";
    int ret;
    ret = ics53_memcmp(str1, str2, ics53_strlen(str1));
    return ret < 0;
}

int test_memcmp_3(){
    char str1[] = "http://www.tutzrialspoint.com";
    char str2[] = "http://www.tutorialspoint.com";
    int ret;
    ret = ics53_memcmp(str1, str2, ics53_strlen(str1));
    return ret > 0;
}

int test_memcmp(){
    int score = 15;
    
    if (!test_memcmp_1())
        score -= 5;
    if (!test_memcmp_2())
        score -= 5;
    if (!test_memcmp_3())
        score -= 5;
    
    return score;
}

////////////////////////////MEMCPY/////////////////////////////////////////

int test_memcpy_1(){
    const char src[] = "http://www.tutorialspoint.com";
    char dest[50];
    int ret;
    ics53_memcpy(dest, src, ics53_strlen(src));
    ret = ics53_memcmp(dest,src,ics53_strlen(dest));
    return ret == 0;
}

int test_memcpy_2(){
    const char src[] = "http://www.tutorialspoint.com";
    char dest[50];
    int ret;
    ics53_memcpy(dest, src, ics53_strlen(src)+1);
    ret = ics53_memcmp(dest,src,ics53_strlen(dest)+1);
    return ret == 0;
}

int test_memcpy_3(){
    const char src[] = "http://www.tutorialspoint.com";
    char dest[50];
    int ret;
    ics53_memcpy(dest, src, 1);
    ret = ics53_memcmp(dest,src,10);
    return ret == 0;
}

int test_memcpy(){
    int score = 15;
    
    if (!test_memcpy_1())
        score -= 5;
    if (!test_memcpy_2())
        score -= 5;
    if (!test_memcpy_3())
        score -= 5;
    
    return score;
}

////////////////////////////MEMMOVE/////////////////////////////////////////
int test_memmove_1(){
    const char src[] = "azret missirov";
    char dest[] = "missirov azret";
    int ret;
    ics53_memmove(dest, src, ics53_strlen(src));
    ret = ics53_memcmp(dest,src,ics53_strlen(dest));
    return ret == 0;
}

int test_memmove_2(){
    const char src[] = "azret missirov";
    char dest[] = "missirov azret";
    int ret;
    ics53_memmove(dest, src, 5);
    ret = ics53_memcmp(dest,src,ics53_strlen(dest));
    return ret != 0;
}

int test_memmove_3(){
    const char src[] = "azret missirov";
    char dest[] = "missirov azret";
    int ret;
    ics53_memmove(dest, src, 5);
    ret = ics53_memcmp(dest,src,5);
    return ret == 0;
}

int test_memmove(){
    int score = 15;
    
    if (!test_memmove_1())
        score -= 5;
    if (!test_memmove_2())
        score -= 5;
    if (!test_memmove_3())
        score -= 5;
    
    return score;
}

////////////////////////////MEMSET/////////////////////////////////////////
int test_memset_1(){
    char str[50];
    ics53_memset(str, ',', 8);
    int i;
    for (i = 0; i < 8; i++)
        if (str[i] != ',')
            return 0;
    return 1;
}

int test_memset_2(){
    char str[50];
    ics53_memset(str, 'a', ics53_strlen(str));
    int i;
    for (i = 0; i < ics53_strlen(str); i++)
        if (str[i] != 'a')
            return 0;
    return 1;
}
int test_memset_3(){
    char str[50]="azret missirov";
    ics53_memset(str, '!', ics53_strlen(str));
    int i;
    for (i = 0; i < ics53_strlen(str); i++)
        if (str[i] != 'a')
            return 1;
    return 0;
}
int test_memset(){
    int score = 15;
    
    if (!test_memset_1())
        score -= 5;
    if (!test_memset_2())
        score -= 5;
    if (!test_memset_3())
        score -= 5;
    
    return score;
}

////////////////////////////SETCAT/////////////////////////////////////////

int test_strcat_1(){
        char src[50], dest[50];
        ics53_strcpy(src,  "azret");
        ics53_strcpy(dest,  "missirov");
        ics53_strcat(dest, src);
        char res[] = "missirovazret";
        int i;
        for (i = 0; res[i]; i++)
            if (res[i] != dest[i])
                return 0;
        return 1;
}

int test_strcat_2(){
    char src[50], dest[50];
    ics53_strcpy(src,  "azret");
    ics53_strcpy(dest,  "missirov");
    ics53_strcat(dest, src);
    char res[] = "azretmissirov";
    int i;
    for (i = 0; res[i]; i++)
        if (res[i] != dest[i])
            return 1;
    return 0;
}

int test_strcat_3(){
    char src[50], dest[50], total[100];
    ics53_strcpy(src,  "azret");
    ics53_strcpy(dest,  "missirov");
    ics53_strcpy(total,  "full:");
    ics53_strcat(dest, src);
    ics53_strcat(total, dest);
    ics53_memcmp(total,"full:missirovazret",ics53_strlen(total));
    int ret;
    return ret==0;
}

int test_strcat(){
    int score = 15;
    
    if (!test_strcat_1())
        score -= 5;
    if (!test_strcat_2())
        score -= 5;
    if (!test_strcat_3())
        score -= 5;
    
    return score;
}

////////////////////////////STRNCAT/////////////////////////////////////////

int test_strncat_1(){
    char src[50], dest[50];
    ics53_strcpy(dest,  "azret");
    ics53_strcpy(src,  "missirov");
    ics53_strncat(dest, src,ics53_strlen(dest));
    char res[] = "azretmissi";
    int i;
    for (i = 0; res[i]; i++)
        if (res[i] != dest[i])
            return 0;
    return 1;
}

int test_strncat_2(){
    char src[50], dest[50];
    ics53_strcpy(dest,  "azret");
    ics53_strcpy(src,  "missirov");
    ics53_strncat(dest, src,10);
    char res[] = "azretmissirov";
    int i;
    for (i = 0; res[i]; i++)
        if (res[i] != dest[i])
            return 0;
    return 1;
}

int test_strncat_3(){
    char src[50], dest[50], total[100];
    ics53_strcpy(src,  "missirov");
    ics53_strcpy(dest,  "azret");
    ics53_strcpy(total,  "full:");
    ics53_strcat(dest, src);
    ics53_strncat(total, dest,5);
    ics53_memcmp(total,"azretmissir",ics53_strlen(total));
    int ret;
    return ret!=0;
}

int test_strncat(){
    int score = 15;
    
    if (!test_strncat_1())
        score -= 5;
    if (!test_strncat_2())
        score -= 5;
    if (!test_strncat_3())
        score -= 5;
    
    return score;
}

////////////////////////////STRCHR/////////////////////////////////////////

int test_strchr_1(){
    const char src[] = "azret.missirov";
    const char ch = '.';
    int ret;
    char *res;
    res = ics53_strchr(src, ch);
    ret = ics53_memcmp(src,res,ics53_strlen(src));
    return ret != 0;
}

int test_strchr_2(){
    const char src[] = "azret.missirov";
    const char ch = '.';
    int ret;
    char *res;
    res = ics53_strchr(src, ch);
    ret = ics53_memcmp(res,".missirov",ics53_strlen(res));
    return ret == 0;
}

int test_strchr_3(){
    const char src[] = "azret.missirov";
    const char ch = '!';
    int ret;
    char *res;
    res = ics53_strchr(src, ch);
    return res == NULL;
}

int test_strchr(){
    int score = 15;
    
    if (!test_strchr_1())
        score -= 5;
    if (!test_strchr_2())
        score -= 5;
    if (!test_strchr_3())
        score -= 5;
    return score;
}

////////////////////////////STRCMP/////////////////////////////////////////

int test_strcmp_1(){
    char str1[] = "http://www.tutorialspoint.com";
    char str2[] = "http://www.tutorialspoint.com";
    int ret;
    ret = ics53_strcmp(str1, str2);
    return ret == 0;
}

int test_strcmp_2(){
    char str1[] = "http://www.tutorialspoint.com";
    char str2[] = "http://www.tutzrialspoint.com";
    int ret;
    ret = ics53_strcmp(str1, str2);
    return ret < 0;
}

int test_strcmp_3(){
    char str1[] = "http://www.tutzrialspoint.com";
    char str2[] = "http://www.tutorialspoint.com";
    int ret;
    ret = ics53_strcmp(str1, str2);
    return ret > 0;
}

int test_strcmp(){
    int score = 15;
    
    if (!test_strcmp_1())
        score -= 5;
    if (!test_strcmp_2())
        score -= 5;
    if (!test_strcmp_3())
        score -= 5;
    
    return score;
}

/////////////////////STRNCMP////////////////////////////
int test_strncmp_1(){
    char str1[] = "http://www.tutorialspoint.com";
    char str2[] = "http://www.tutorialspoint.com";
    int ret;
    ret = ics53_strncmp(str1, str2, ics53_strlen(str1));
    return ret == 0;
}

int test_strncmp_2(){
    char str1[] = "http://www.tutorialspoint.com";
    char str2[] = "http://www.tutzrialspoint.com";
    int ret;
    ret = ics53_strncmp(str1, str2, 20);
    return ret < 0;
}

int test_strncmp_3(){
    char str1[] = "http://www.tutzrialspoint.com";
    char str2[] = "http://www.tutorialspoint.com";
    int ret;
    ret = ics53_strncmp(str1, str2, 20);
    return ret > 0;
}

int test_strncmp(){
    int score = 15;
    
    if (!test_strncmp_1())
        score -= 5;
    if (!test_strncmp_2())
        score -= 5;
    if (!test_strncmp_3())
        score -= 5;
    
    return score;
}

/////////////////////STRCOLL////////////////////////////

int test_strcoll_1(){
    char str1[] = "http://www.tutorialspoint.com";
    char str2[] = "http://www.tutorialspoint.com";
    int ret;
    ret = ics53_strcoll(str1, str2);
    return ret == 0;
}

int test_strcoll_2(){
    char str1[] = "http://www.tutorialspoint.com";
    char str2[] = "http://www.tutzrialspoint.com";
    int ret;
    ret = ics53_strcoll(str1, str2);
    return ret < 0;
}

int test_strcoll_3(){
    char str1[] = "http://www.tutzrialspoint.com";
    char str2[] = "http://www.tutorialspoint.com";
    int ret;
    ret = ics53_strcoll(str1, str2);
    return ret > 0;
}

int test_strcoll(){
    int score = 15;
    
    if (!test_strcoll_1())
        score -= 5;
    if (!test_strcoll_2())
        score -= 5;
    if (!test_strcoll_3())
        score -= 5;
    
    return score;
}

/////////////////////STRCPY////////////////////////////

int test_strcpy_1(){
    const char src[] = "http://www.google.com";
    char dest[50];
    int ret;
    ics53_strcpy(dest, src);
    ret = ics53_memcmp(dest,src,ics53_strlen(dest));
    return ret == 0;
}

int test_strcpy_2(){
    const char src[] = "http://www.google.com";
    char dest[50];
    int ret;
    ics53_strcpy(dest, src);
    ret = ics53_memcmp(dest,src,ics53_strlen(dest)+1);
    return ret == 0;
}

int test_strcpy_3(){
    const char src[] = "http://www.google.com";
    char dest[50];
    int ret;
    ics53_strcpy(dest, src);
    ret = ics53_memcmp(dest,src,10);
    return ret == 0;
}

int test_strcpy(){
    int score = 15;
    
    if (!test_strcpy_1())
        score -= 5;
    if (!test_strcpy_2())
        score -= 5;
    if (!test_strcpy_3())
        score -= 5;
    
    return score;
}

/////////////////////STRNCPY////////////////////////////

int test_strncpy_1(){
    const char src[] = "http://www.google.com";
    char dest[50];
    int ret;
    ics53_strncpy(dest, src, ics53_strlen(src));
    ret = ics53_memcmp(dest,src,ics53_strlen(dest));
    return ret == 0;
}

int test_strncpy_2(){
    const char src[] = "http://www.google.com";
    char dest[50];
    int ret;
    ics53_strncpy(dest, src, ics53_strlen(src)+1);
    ret = ics53_memcmp(dest,src,ics53_strlen(dest)+1);
    return ret == 0;
}

int test_strncpy_3(){
    const char src[] = "http://www.google.com";
    char dest[50];
    int ret;
    ics53_strncpy(dest, src, 1);
    ret = ics53_memcmp(dest,src,10);
    return ret == 0;
}

int test_strncpy(){
    int score = 15;
    
    if (!test_strncpy_1())
        score -= 5;
    if (!test_strncpy_2())
        score -= 5;
    if (!test_strncpy_3())
        score -= 5;
    
    return score;
}

/////////////////////STRCSPN///////////////////////////////


int test_strcspn_1(){
  int ret;
    const char str1[] = "http://www.google.com";
    const char str2[] = "w3w";
    
    ret = ics53_strcspn(str1, str2);
    
    return ret==8;
}

int test_strcspn_2(){
    int ret;
    const char str1[] = "http://www.google.com";
    const char str2[] = "az";
    
    ret = ics53_strcspn(str1, str2);
    
    return ret==0;
}

int test_strcspn_3(){
    int ret;
    const char str1[] = "http://www.google.com";
    const char str2[] = "l";
    
    ret = ics53_strcspn(str1, str2);
    
    return ret==16;
}

int test_strcspn(){
    int score = 15;
    
    if (!test_strcspn_1())
        score -= 5;
    if (!test_strcspn_2())
        score -= 5;
    if (!test_strcspn_3())
        score -= 5;
    
    return score;
}

//////////////////////strerror/////////////////////////

int test_strerror_1(){
    enum errno{ERRORSMALL,ERRORLONG,ERROREMTY};

    ics53_strerror(ERRORSMALL);
    int res = ics53_strcmp(ics53_strerror(0),"string is too small");
    
    return res==0;
}

int test_strerror_2(){
    char *ret;
    enum errno{ERRORSMALL,ERRORLONG,ERROREMTY};

    ret = ics53_strerror(ERRORLONG);
    int res = ics53_strcmp(ret,"string is too long");
    
    return res==0;
}

int test_strerror_3(){
    char *ret;
    enum errno{ERRORSMALL,ERRORLONG,ERROREMTY};

    ret = ics53_strerror(ERROREMTY);
    int res = ics53_strcmp(ret,"empty string");
    
    return res==0;
}



int test_strerror(){
    int score = 15;
    
    if (!test_strerror_1())
        score -= 5;
    if (!test_strerror_2())
        score -= 5;
    if (!test_strerror_3())
        score -= 5;
    
    return score;
}


////////////////////////STRLEN//////////////////////////////////////
int test_strlen_1(){
    const char str1[] = "azret azret azret";
    
    int res = ics53_strlen(str1);
    
    return res==17;
}

int test_strlen_2(){
    const char str1[] = "azret ";
    
    int res = ics53_strlen(str1);
    
    return res==6;
}

int test_strlen_3(){
    const char str1[] = "";
    
    int res = ics53_strlen(str1);
    
    return res==0;
}


int test_strlen(){
    int score = 15;
    
    if (!test_strlen_1())
        score -= 5;
    if (!test_strlen_2())
        score -= 5;
    if (!test_strlen_3())
        score -= 5;
    
    return score;
}

////////////////////////strpbrk//////////////////////////////////////

int test_strpbrk_1(){
    const char str1[] = "azret missirov";
    const char str2[] = "al";
    char *ret=ics53_strpbrk(str1, str2);
    
    return (ics53_strcmp(ret,"a"));

    
}

int test_strpbrk_2(){
    const char str1[] = "azret missirov";
    const char str2[] = "al";
    char *ret=ics53_strpbrk(str1, str2);
    int res = ics53_strcmp(ret,"b");
    return (res!=0);
}

int test_strpbrk_3(){
    const char str1[] = "azret missirov";
    const char str2[] = "dft";
    char *ret=strpbrk(str1, str2);
    int res = ics53_strcmp(ret,"t");
    return (res!=0);
}


int test_strpbrk(){
    int score = 15;
    
    if (!test_strpbrk_1())
        score -= 5;
    if (!test_strpbrk_2())
        score -= 5;
    if (!test_strpbrk_3())
        score -= 5;
    
    return score;
}

/////////////////////////strrchr///////////////////

int test_strrchr_1(){
    const char str1[] = "azret missirov";
    const char c = 's';
    char *ret=strrchr(str1, c);
    
    return (ics53_strcmp(ret,"sirov")==0);
}

int test_strrchr_2(){
    const char str1[] = "azret missirov";
    const char c = ' ';
    char *ret=ics53_strrchr(str1, c);
    
    return (ics53_strcmp(ret," missirov")==0);
}

int test_strrchr_3(){
    const char str1[] = "azret missirov";
    char c = 'o';
    char *ret=strrchr(str1, c);
    return (ics53_strcmp(ret,"ov")==0);
}

int test_strrchr(){
    int score = 15;
    
    if (!test_strrchr_1())
        score -= 5;
    if (!test_strrchr_2())
        score -= 5;
    if (!test_strrchr_3())
        score -= 5;
    
    return score;
}

/////////////////////////strspn///////////////////

int test_strspn_1(){
    char str1[] = "129th";
   int res = ics53_strspn(str1, "1234567890");

    return res==3;
    
}

int test_strspn_2(){
    char str1[] = "azret";
    int res = ics53_strspn(str1, "1234567890");
    
    return res==0;
    
}

int test_strspn_3(){
    char str1[] = "8";
    int res = strspn(str1, "1234567890");
    return res==1;
    
}

int test_strspn(){
    int score = 15;
    
    if (!test_strspn_1())
        score -= 5;
    if (!test_strspn_2())
        score -= 5;
    if (!test_strspn_3())
        score -= 5;
    return score;
}

/////////////////////////strstr///////////////////

int test_strstr_1(){
    char str1[] = "azret missirov";
    char str2[] = "missirov";
    
    char *res = ics53_strstr(str1, str2);

    return (ics53_strcmp(res,"missirov")==0);
    
}

int test_strstr_2(){
    char str1[] = "azret missirov";
    char str2[] = "azret";
    char *res = ics53_strstr(str1, str2);
    return (ics53_strcmp(res,"azret missirov")==0);
    
}

int test_strstr_3(){
    char str1[] = "azret missirov";
    char str2[] = "53";
    
    char *res = ics53_strstr(str1, str2);
    return (res==NULL);
    
}

int test_strstr(){
    int score = 15;
    
    if (!test_strstr_1())
        score -= 5;
    if (!test_strstr_2())
        score -= 5;
        if (!test_strstr_3())
            score -= 5;
    return score;
}


/////////////////////////strxfrm///////////////////

int test_strxfrm_1(){
    char dest[20];
    char str1[] = "azret missirov uci";
    size_t res = strxfrm(dest,str1,5);
    return res==18;
}

int test_strxfrm_2(){
    char dest[20];
    char str1[] = "azret missirov uci";
    size_t res = strxfrm(dest,str1,15);
    return res==18;
}

int test_strxfrm_3(){
    char dest[20];
    char str1[] = "azret missirov uci";
    size_t res = ics53_strxfrm(dest,str1,14);
    return res == 15;
}


int test_strxfrm(){
    int score = 15;
    
    if (!test_strxfrm_1())
        score -= 5;
    if (!test_strxfrm_2())
        score -= 5;
    if (!test_strxfrm_3())
        score -= 5;
    
    return score;
}

int main(void){
    printf("score is %d\n", test_memchr());
    printf("score is %d\n", test_memcmp());
    printf("score is %d\n", test_memcpy());
    printf("score is %d\n", test_memmove());
    printf("score is %d\n", test_memset());
    printf("score is %d\n", test_strcat());
    printf("score is %d\n", test_strncat());
    printf("score is %d\n", test_strchr());
    printf("score is %d\n", test_strcmp());
    printf("score is %d\n", test_strncmp());
    printf("score is %d\n", test_strcoll());
    printf("score is %d\n", test_strcpy());
    printf("score is %d\n", test_strncpy());
    printf("score is %d\n", test_strcspn());
    printf("score is %d\n", test_strerror());
    printf("score is %d\n", test_strlen());
    printf("score is %d\n", test_strpbrk());
    printf("score is %d\n", test_strrchr());
    printf("score is %d\n", test_strspn());
    printf("score is %d\n", test_strstr());
    printf("score is %d\n", test_strxfrm());

    exit(1);
    return 0;
}
