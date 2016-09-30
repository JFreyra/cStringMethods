#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int myStrlen(char *arr);
char *myStrcpy(char *arr1, char *arr2);
char *myStrncpy(char *arr1, char *arr2, int n);
char *myStrcat(char *arr1, char *arr2);
char *myStrncat(char *arr1, char *arr2, int n);
int myStrcmp(char *arr1, char *arr2);
char *myStrchr(char *arr, char c);
char *myStrstr(char *arr1, char *arr2);

void main(){

  char str1[] = "Tuesday";
  char str2[] = "Friday";
  char str3[] = "Monday";
  char str4[] = "Thursday";
  char str5[] = "one";
  char str6[] = "one";
  char str7[] = "two";
  char str8[] = "four";
  char str9[] = "fourzzz";
  char extra1[] = "tester";
  char extra2[] = "undead";
  char extra3[17] = "unfortunate"; // specified size bc it would bleed into extra5
  char extra4[] = "random";
  char extra5[] = "onetwothree";
  char extra6[] = "ne";

  //variables
  printf("variables:\n");

  printf("str1: %s\n",str1);
  printf("str2: %s\n",str2);
  printf("str3: %s\n",str3);
  printf("str4: %s\n",str4);
  printf("str5: %s\n",str5);
  printf("str6: %s\n",str6);
  printf("str7: %s\n",str7);
  printf("str8: %s\n",str8);
  printf("str9: %s\n",str9);
  printf("extra1: %s\n",extra1);
  printf("extra2: %s\n",extra2);
  printf("extra3: %s\n",extra3);
  printf("extra4: %s\n",extra4);
  printf("extra5: %s\n",extra5);
  printf("extra6: %s\n",extra6);
  printf("\n");

  //strlen
  printf("myStrlen\n");

  printf("length of strLen1: %d \n",myStrlen(str1));
  printf("length of strLen2: %d \n",myStrlen(str2));
  printf("\n");

  //strcpy
  printf("myStrcpy\n");

  myStrcpy(extra1,extra2);
  printf("Copy extra2 onto extra1: %s\n",extra1);
  printf("\n");

  //strncpy
  printf("myStrncpy\n");

  myStrncpy(str1,str2,5);
  printf("Copy first 5 chars of str2 onto str1: %s \n",str1);
  printf("\n");

  //strcat
  printf("myStrcat\n");

  myStrcat(str3,str4);
  printf("Concatenate str4 to str3: %s \n",str3);
  printf("\n");

  //strncat
  printf("myStrncat\n");

  myStrncat(extra3,extra4,5);
  printf("Concatenate first 5 chars of extra4 to extra3: %s\n",extra3);
  printf("\n");

  //strcmp
  printf("myStrcmp\n");

  printf("Compare str5 to str6: %d \n",myStrcmp(str5,str6));
  printf("Compare str6 to str7: %d \n",myStrcmp(str6,str7));
  printf("Compare str7 to str8: %d \n",myStrcmp(str7,str8));
  printf("Compare str8 to str9: %d \n",myStrcmp(str8,str9));
  printf("\n");

  //strchr
  printf("myStrchr\n");

  printf("Char 'a' in str5 does not exist: %d \n",myStrchr(str5,'a') == 0);
  printf("Char 'o' in str5 exists: %d \n",myStrchr(str5,'o') > 0);
  printf("\n");

  //strstr
  printf("myStrstr\n");

  printf("Print from location of 'ne' in 'onetwothree': %s\n",myStrstr(extra5,extra6));
  printf("\n");
}

// assumes arr1 and arr2 are null terminated
int myStrlen(char *arr){
  int i = 0;
  while(*arr){
    i++;
    arr++;
  }
  return i;
}

char *myStrcpy(char *arr1, char *arr2){
  while(*arr1 && *arr2){
    *arr1 = *arr2;
    arr1++;
    arr2++;
  }
  *arr1 = *arr2;
  return arr1;
}

// assumes arr1 and arr2 are null terminated
char *myStrncpy(char *arr1, char *arr2, int n){
  while(n && *arr1 && *arr2){
    *arr1 = *arr2;
    arr1++;
    arr2++;
    n--;
  }
  *arr1 = *arr2;
  return arr1;
}

// assumes arr1 and arr2 are null terminated
char *myStrcat(char *arr1, char *arr2){
  int i = myStrlen(arr1);
  int j = myStrlen(arr2);
  while(*arr1){
    arr1++;
  }
  while(*arr2){
    *arr1 = *arr2;
    arr1++;
    arr2++;
  }
  *arr1 = *arr2;
  arr1 = arr1 - i - j - 1;
  return arr1;
}

char *myStrncat(char *arr1, char *arr2, int n){
  int i = myStrlen(arr1);
  int j = myStrlen(arr2);
  while(*arr1){
    arr1++;
  }
  while(n && *arr2){
    *arr1 = *arr2;
    arr1++;
    arr2++;
    n--;
  }
  *arr1 = *arr2;
  arr1++;
  *arr1 = 0;
  if(n)
    arr1 = arr1 - i - j - 1;
  else
    arr1 = arr1 - i - n - j;
  return arr1; //fix, does not return proper pointer
}

// assumes arr1 and arr2 are null terminated
int myStrcmp(char *arr1, char *arr2){
  while(*arr1 && *arr2){
    if(*arr1 == *arr2){
      arr1++;
      arr2++;
    }
    else
      break;
  }
  return *arr1 - *arr2;
}

// assumes arr is null terminated
char *myStrchr(char *arr, char c){
  while(*arr){
    if(*arr == c)
      return arr;
    arr++;
  }
  return 0;
}

// fix
char *myStrstr(char *arr1, char *arr2){
  int i = 0;
  while(*arr1){
    if(*arr1 == *arr2){
      while(*arr1 && *arr2){
	if(*arr1 != *arr2)
	  break;
	arr1++;
	arr2++;
	i++;
      }
      arr1 = arr1-i;
      if(!*arr2)
	break;
      arr2 = arr2-i;
    }
    arr1++;
  }
  return arr1;
}
