#include <stdio.h>

char str[100];

char array[100];

int main()

{
   // printf("Hello World!\n");

    int t,i,j,k,l,n,a,b,ciphercode,c;
 
   scanf("%d %s",&k,str);
 
   n=strlen(str);
    
for(i=0;i<n;i++)
  
  {
       
 ciphercode=str[i]-'a'+1;
     
  if(str[i]=='.')
     
   ciphercode=27;
     
   if(str[i]=='_')
       
 ciphercode=0;
      
  a=ciphercode+i;
   
     b=ciphercode-28+i;
  
//      printf("ab %d %d\n",a,b);
  
      if(a>=0 && a<=27)
   
     c=a;
       
 else
      
  c=b;
   
//     printf("c %d\n",c);

        array[(k*i)%n]=c;
 
   }
 
/*   for(i=0;i<n;i++)
    
printf("%d ",array[i]);*/
 
   for(i=0;i<n;i++)
 
   {
        if(array[i]==0)

       {
           array[i]='_';
   
    //    printf("hi\n");
       }
     
   else if(array[i]==27)
      
  {
            array[i]='.';
      
   //   printf("hello\n");
        }
     
   else 
      
  {
            array[i]=array[i]+'a'-1;
       
 //    printf("bye\n");
        
}
   
 }
    
printf("%s\n",array);
  
  return 0;

}
