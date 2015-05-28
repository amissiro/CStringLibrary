//Azret Missirov

#include "strlib.h"
#include <string.h>

void *ics53_memchr(const void *str, int c, size_t n){
    char *s = (char *) str; size_t i;
    char ch = (char) c;
    for (i=0; i < n; i++){
        if (s[i]==ch) return s+i;
    }
    return NULL;
}

int ics53_memcmp(const void *str1, const void *str2, size_t n){
    const char *s = str1, *s1 = str2; int i;
    for (i=0; i < n; i++,s = s+1, s1 = s1+1){
        if (*s!=*s1) return *s-*s1;      
    }
    return 0;
}

void *ics53_memcpy(void *dest, const void *src, size_t n){
    unsigned char *d = dest; 
    const unsigned char *s = src;
    size_t i;
    for (i = 0; i < n; i++, d = d+1 , s = s+1) *d = *s;
    return dest;
}

void *ics53_memmove(void *dest, const void *src, size_t n){
    unsigned char *d = dest;
    const unsigned char *s = src;size_t i; 
    char sub=d-s;
    
    if (d > s)
     for (i = 0; i < n; i++, d=d+1, s=s+1) *d = *s;
    else
     for (i = n+sub; i>=sub; i--) d[i-sub]=s[i-sub];
    return dest;
}

void *ics53_memset(void *str, int c, size_t n){
    char *s = (char *)str; int i;
    for (i=0; i < n; i++, s = s+1) *s=c;
    return str;
}

char *ics53_strcat(char *dest, const char *src){
    size_t i,size;
    size = ics53_strlen(dest);
    for (i=0; i < ics53_strlen(src); i++)
     {
        dest[size+i] = src[i];
     }
     return dest;
}

char *ics53_strncat(char *dest, const char *src, size_t n){
    size_t i,size;
    size = ics53_strlen(dest);
    for (i=0; i < n; i++)
    {
        dest[size+i] = src[i];
    }
    return dest;
}

char *ics53_strchr(const char *str, int c){
    size_t i;
    
    for (i=0; i < ics53_strlen(str)+1; i++)
    {
        if (str[i]==c) {size_t j=i; return ((char*)str+j);}
    }
    return NULL;
}

int my_strcmp_helper(const char *str1, const char *str2, size_t n)
{   int i;
    for (i=0; i < n; i++)
    {
        if (str1[i] > str2[i]) return 1;
        else if (str1[i]<str2[i]) return -1;
    }
    
    return 0;
}

int ics53_strcmp(const char *str1, const char *str2){
    if (ics53_strlen(str1)>ics53_strlen(str2)) return 1;
    else if (ics53_strlen(str1)<ics53_strlen(str2))return -1;
    else return my_strcmp_helper(str1, str2, ics53_strlen(str1));
}

int ics53_strncmp(const char *str1, const char *str2, size_t n){
  return my_strcmp_helper(str1, str2, n);
}

int ics53_strcoll(const char *str1, const char *str2){
    
    return ics53_strcmp(str1,str2);
}

char *ics53_strcpy(char *dest, const char *src){
    size_t i;
    for (i = 0 ; i < ics53_strlen(src)+1; i++)
    {
        dest[i] = src[i];
    }
    return dest;
}

char *ics53_strncpy(char *dest, const char *src, size_t n){
    size_t i;
    
    for (i = 0 ; i < n && src[i] != '\0'; i++) dest[i] = src[i];
    for ( ; i < n; i++) dest[i] = '\0';
    
    return dest;
}

size_t my_contains(const char * str, char c)
{
    size_t i;
    
    for (i=0; i < ics53_strlen(str); i++)
        if (str[i]==c) return i+1;
    
    return 0;
}

size_t ics53_strcspn(const char *str1, const char *str2){
    size_t i, cont;
    
    for (i=0; i < ics53_strlen(str2); i++)
    {
        cont = my_contains(str1,str2[i]);
        if (cont!=0) return cont;
    }
    return 0;
}

char *ics53_strerror(int errnum){
    enum errno{ERRORSMALL,ERRORLONG,ERROREMTY};
    enum errno msg= errnum;
    char *errorMessages[3];
    errorMessages[ERRORSMALL] = "string is too small";
    errorMessages[ERRORLONG] = "string is too long";
    errorMessages[ERROREMTY] = "empty string";
    return errorMessages[msg];
}

size_t ics53_strlen(const char *str){
    size_t i=0, length=0;
    
    while (str[i]!='\0'){
        length++;
        i++;
    }
    return length;
}

size_t my_min (size_t *array)
{
    size_t i, min = array[0];
    size_t size = sizeof(array)/sizeof(size_t);
    
    for (i=0; i < size+1; i++) {
        if (array[i] < array[0]) min = array[i];
    }
    
    return min;
}

char *ics53_strpbrk(const char *str1, const char *str2){
    size_t i,j=0,cont,temp[ics53_strlen(str2)]; char *p = NULL;
    
    for (i=0; i < ics53_strlen(str2); i++)
    {
        cont = my_contains(str1,str2[i]);
        if (cont != 0) {temp[i] = cont; j++;};
    }
    if (j>0) p = (char*)(str1+(my_min(temp)+1));
    
    return p;
}

char *ics53_strrchr(const char *str, int c){
    size_t i,j=0; char *p = NULL;
    
    for (i=0; i < ics53_strlen(str)+1; i++)
    {
        if (str[i]==c) {j=i;}
    }
    if (j>0) p = ((char*)str+j);
    
    return p;
}

size_t ics53_strspn(const char *str1, const char *str2){
    size_t count = 0,i;
    for (i=0; i < ics53_strlen(str1); i++)
    {
        if (my_contains(str2, str1[i])>0)
            count++;
        else break;
    }
    return count;
}

char *ics53_strstr(const char *str1, const char *str2){
    
        const char * p = str1;
        while ((p = ics53_strchr(p, *str2))!=0)
        {
            if (ics53_strncmp(p, str2, ics53_strlen(str2))==0)
                return (char *) p;
            p++;
        }
        return NULL;
}

size_t ics53_strxfrm(char *dest, const char *src, size_t n){
    return ics53_strlen(ics53_strncpy(dest,src,n));
}
