// a test.cpp : Defines the entry point for the console application.
//

# include <math.h>
#include <stdio.h>
# define TRUE 1
# define FALSE 0
# define OK 1
 typedef int Status;

 void Read(int &a,int &b){  // 读入数据
    printf("please input the values of A,B:");
    scanf("%d%d",&a,&b);
    return ;
}
 void Putout(int a[4]){   //  输出数据
    int i;
    for(i=0;i<4;i++) 
        printf("%d ",a[i]);
    printf("\n");
}

 Status Judje(int a[10][4],int b[10][2],int c[4]){   
    int k=0,i,j,sum=0;

    for(j=0;j<10;j++)
    {
        if(a[j][0]==0) 
            sum++;
        else
        {
            k=0;
            for(i=0;i<4;i++) 
              if(a[j][i]==c[i]) k++;
            if(k==b[j][1]) 
            sum++;
        }
    }
    if(sum==10) 
        return OK;
    else 
        return FALSE;
        
}

Status little(int a[4]){  
    int i,j,k=0;

    for(i=0;i<4;i++)
        for(j=0;j<4;j++)
            if(a[i]==a[j]) k++;
            
    if(k>4) 
        return FALSE;
    else 
        return OK;
}

void Produce(int c[4],int a[10][4],int b[10][2]){ // 输出最终结果
    int i=0,j[4],d[4];
    while(a[i][0]!=0) i++;
   
        for(j[0]=0;j[0]<4;j[0]++)
          for(j[1]=0;j[1]<4;j[1]++)
            for(j[2]=0;j[2]<4;j[2]++)
              for(j[3]=0;j[3]<4;j[3]++)
             {
                 if(b[i-1][1]!=4)  
                 {
                     d[0]=c[j[0]]; d[1]=c[j[1]]; d[2]=c[j[2]]; d[3]=c[j[3]];
                    if(little(d)&&Judje(a,b,d))   
                    { 
                         a[i][0]=d[0];a[i][1]=d[1];a[i][2]=d[2];a[i][3]=d[3];
                         Putout(a[i]);
                         Read(b[i][0],b[i][1]);
                         i++;
                    }
                }
                else 
                {
                    printf("Right Answer! Thank You To Play!\n");
                    return;
                 }
             }
    printf("Your Input is wrong!\n");
        return;

    }

    int main(){
      int j,i=0,b[10][2]={0};
      int a[10][4]={0};
      int    sum=0,c[4]={0};  
      char w; 
     printf("think about 4 ordered and different digits and enter 's' to start:");    
     scanf("%c",&w);
     a[0][0]=1;a[0][1]=2;a[0][2]=3;a[0][3]=4;
        Putout(a[0]);
     Read(b[0][0],b[0][1]);
        if(b[0][0]==4&&b[0][1]==4) 
        {
                printf("Right Answer! Thank You To Play!\n");
                return 0;
        }
        
        if(b[0][0]==4&&b[0][1]!=4)
        {
            for(i=0;i<4;i++) c[i]=a[0][i];
            Produce(c,a,b);
            return 0;
        }
            sum=sum+b[0][0];


         a[1][0]=2;a[1][1]=1;a[1][2]=5;a[1][3]=6;
         Putout(a[1]);
            Read(b[1][0],b[1][1]);
        if(b[1][0]==4&&b[1][1]==4) 
        {
            printf("Right Answer! Thank You To Play!\n");
            return 0;
        }
        
        if(b[1][0]==4&&b[1][1]!=4)
        {
            for(i=0;i<4;i++) c[i]=a[1][i];
             Produce(c,a,b);
             return 0;
        }
            sum=sum+b[1][0];


        a[2][0]=7;a[2][1]=8;a[2][2]=1;a[2][3]=2;
         Putout(a[2]);
        Read(b[2][0],b[2][1]);
            if(b[2][0]==4&&b[2][1]==4) 
            {
                printf("Right Answer! Thank You To Play!\n");
                return 0;
            }
        
        if(b[2][0]==4&&b[2][1]!=4)
        {
                for(i=0;i<4;i++) c[i]=a[2][i];
                Produce(c,a,b);
                 return 0;
        }
            sum=sum+b[2][0];
        
    //do logical judgement according to the 3 results above        
    switch(sum)
    {
    case 3:
      c[0]=9;
      
      if(b[0][0]==b[1][0]&&b[1][0]==b[2][0])
      {
          a[3][0]=9;a[3][1]=3;a[3][2]=5;a[3][3]=7;
              Putout(a[3]);
           Read(b[3][0],b[3][1]);
           
           if(b[3][0]==4) break;
          
           a[4][0]=3;a[4][1]=4;a[4][2]=5;a[4][3]=8;
           Putout(a[4]);
           Read(b[4][0],b[4][1]);

           if(b[3][0]-b[4][0]==2&&b[3][0]==3) 
           {
               c[1]=3;c[2]=6;c[3]=7;
           }
           if(b[3][0]-b[4][0]==1&&b[3][0]==3) 
           {
               c[1]=4;c[2]=5;c[3]=7;
           }
           if(b[3][0]-b[4][0]==1&&b[3][0]==2) 
           {
               c[1]=4;c[2]=6;c[3]=7;
           }
          if(b[3][0]-b[4][0]==0&&b[3][0]==3) 
          {
               c[1]=3;c[2]=5;c[3]=8;
           }
          if(b[3][0]-b[4][0]==0&&b[3][0]==2) 
          {
               c[1]=4;c[2]=6;c[3]=7;
           }
          if(b[3][0]-b[4][0]==-1&&b[3][0]==2) 
          {
               c[1]=4;c[2]=5;c[3]=8;
           }
           if(b[3][0]-b[4][0]==-1&&b[3][0]==1) 
           {
               c[1]=4;c[2]=6;c[3]=8;
           }
      }
      else{
          a[3][0]=9;
          for(j=0;j<3;j++)
          {
              if(b[j][0]==2)
              {
                  a[3][1]=c[1]=2*j+3; a[3][2]=c[2]=2*j+4;
              }
              if(b[j][0]==1) a[3][3]=c[3]=2*j+3;
          }
          Putout(a[3]);
          Read(b[3][0],b[3][1]);
          if(b[3][0]==3) 
          {
              c[3]=c[3]+1;
              break;
          }
      }
      break;



  case 4:
          i=0;
          for(j=0;j<3;j++)
              if(b[j][0]==2)
              {
                c[i]=2*j+3; c[i+1]=2*j+4;i=i+2;
              }
         if(i==4) break;
         
         a[3][1]=c[0];a[3][0]=c[1];
             for(j=0;j<3;j++)
                 if(b[j][0]==1) 
                 {
                     a[3][i]=c[i]=2*j+3;
                     i=i+1;
                 }
          Putout(a[3]);
          Read(b[3][0],b[3][1]);

          if(b[3][0]==4) break;
          if(b[3][0]==2)
          {
              c[3]=c[3]+1;
              c[2]=c[2]+1;
              break;
          }
          c[2]=a[4][0]=a[3][2]+1;a[4][1]=a[3][3];a[4][2]=a[3][1];a[4][3]=a[3][0];
           Putout(a[4]);
          Read(b[4][0],b[4][1]);

          if(b[4][0]==4) break;
          else
          {
              c[2]=c[2]-1;c[3]=c[3]+1;
              break;
          }

  case 5:
      c[0]=a[3][0]=9;i=1;
      for(j=0;j<3;j++)
      {
              if(b[j][0]==3)
              {
                c[i]=a[3][i]=2*j+3; c[i+1]=a[3][i+1]=2*j+4;
                a[3][3]=1;
                Putout(a[3]);
                Read(b[3][0],b[3][1]);
                if(b[3][0]==4) break;

                if(b[3][0]==3)
                {
                   c[3]=2;
                   break;
                }
              }
              
              if(b[j][0]==2)
              {
                 c[i]=a[3][i]=2*j+3; 
                 i=i+1;
              }
      }
       c[3]=a[3][3]=1;
       Putout(a[3]);
       Read(b[3][0],b[3][1]);
       if(b[3][0]==4) break;

       a[4][0]=a[3][2]+1;a[4][3]=a[3][1];a[4][1]=1;a[4][2]=2;
        Putout(a[4]);
        Read(b[4][0],b[4][1]);
          if(b[3][0]-b[4][0]==2&&b[3][0]==3) 
          {
               c[1]=1;c[2]=a[3][1]+1;c[3]=a[3][2];
           }
           if(b[3][0]-b[4][0]==1&&b[3][0]==3) 
           {
               c[1]=2;c[2]=a[3][1];c[3]=a[3][2];                   ;
           }
           if(b[3][0]-b[4][0]==1&&b[3][0]==2) 
           {
               c[1]=2;c[2]=a[3][1]+1;c[3]=a[3][2];
           }
          if(b[3][0]-b[4][0]==0&&b[3][0]==3) 
          {
               c[1]=1;c[2]=a[3][1];c[3]=a[3][2]+1;
           }
          if(b[3][0]-b[4][0]==0&&b[3][0]==2) 
          {
               c[1]=2;c[2]=a[3][1]+1;c[3]=a[3][2];
           }
          if(b[3][0]-b[4][0]==-1&&b[3][0]==2) 
          {
               c[1]=2;c[2]=a[3][1];c[3]=a[3][2]+1;
           }
           if(b[3][0]-b[4][0]==-1&&b[3][0]==1) 
           {
               c[1]=2;c[2]=a[3][1]+1;c[3]=a[3][2]+1;
           }
       break;
        
  case 6:
            i=0;
            for(j=0;j<4;j++)
                if(b[j][0]==2) i++;
                if(i==3)
                {
                   c[0]=a[3][0]=9;c[1]=a[3][1]=3;c[2]=a[3][2]=5;c[3]=a[3][3]=7;
                   Putout(a[3]);
                   Read(b[3][0],b[3][1]);
                   a[4][0]=3;a[4][1]=4;a[4][2]=5;a[4][3]=8;
                   Putout(a[4]);
                   Read(b[4][0],b[4][1]);
                        if(b[3][0]-b[4][0]==1&&b[3][0]==2) 
                        {
                              c[1]=3;c[2]=6;c[3]=7;
                        }
                       if(b[3][0]-b[4][0]==0&&b[3][0]==1) 
                       {
                              c[1]=4;c[2]=5;c[3]=7;
                        }
                        if(b[3][0]-b[4][0]==0&&b[3][0]==1) 
                        {
                               c[1]=4;c[2]=6;c[3]=7;
                        }
                        if(b[3][0]-b[4][0]==-1&&b[3][0]==2) 
                        {
                                c[1]=3;c[2]=5;c[3]=8;
                         }
                        if(b[3][0]-b[4][0]==-1&&b[3][0]==1) 
                        {
                                c[1]=4;c[2]=6;c[3]=7;
                        }
                        if(b[3][0]-b[4][0]==-2&&b[3][0]==1) 
                        {
                                c[1]=4;c[2]=5;c[3]=8;
                        }
                        if(b[3][0]-b[4][0]==-2&&b[3][0]==0) 
                        {
                                 c[1]=4;c[2]=6;c[3]=8;
                        }
                    c[0]=1;
                    for(j=0;j<4;j++)
                         a[5][j]=c[j];
                    Putout(a[5]);
                    Read(b[5][0],b[5][1]);
                    if(b[5][0]==4) 
                        break;
                     else
                     {
                            c[0]=2;
                             break;
                     }
             }
       else{
              for(j=0;j<3;j++)
                 if(b[j][0]==3)
                   {
                        a[3][1]=c[1]=2*j+3;     a[3][2]=c[2]=2*j+4;
                   }
              for(j=0;j<3;j++)
                  if(b[j][0]==2) 
                      a[3][3]=c[3]=2*j+3;
            a[3][0]=c[0]=1;
           Putout(a[3]);
           Read(b[3][0],b[3][1]);
           if(b[3][0]==4) 
               break;
           if(b[3][0]==2)
           {
              c[0]=2;c[3]=c[3]+1;
              break;
           }
       a[4][0]=c[0]=a[3][0]+1;   a[4][3]=a[3][1];   a[4][1]=a[3][2];    a[4][2]=a[3][3];
         Putout(a[4]);
          Read(b[4][0],b[4][1]);
          if(b[4][0]==4)
              break;
           if(b[4][0]==2)
           {
              c[0]=1;c[3]=c[3]+1;
              break;
           }
          }

  
     case 7:
               c[0]=a[3][1]=1;c[1]=a[3][2]=2;c[2]=a[3][0]=9;
            for(j=0;j<3;j++)
                  if(b[j][0]==3) 
                     a[3][3]=c[3]=2*j+3;
           Putout(a[3]);
           Read(b[3][0],b[3][1]);
           if(b[3][0]==4)
               break;
           if(b[3][0]==3)
           {
              c[3]=c[3]+1;
              break;
           }
                     
     case 8:
           c[0]=a[3][3]=1;c[1]=a[3][2]=2;
          for(j=0;j<3;j++)
              if(b[j][0]==4) 
              {
                   a[3][3]=c[2]=2*j+3;a[3][0]=c[3]=2*j+4;
                   break;
              }
        i=0;
         for(j=0;j<3;j++)
                 if(b[j][0]==3) 
                 {
                     a[3][i]=c[i+2]=2*j+3;
                     i=i+1;
                  }
          Putout(a[3]);
          Read(b[3][0],b[3][1]);
          if(b[3][0]==4) 
              break;
          if(b[3][0]==2)    
           {
              c[3]=c[3]+1;
              c[2]=c[2]+1;
              break;
          }
          c[2]=a[4][2]=a[3][0]+1;        a[4][1]=a[3][3];     a[4][0]=a[3][1];      a[4][3]=a[3][2];
           Putout(a[4]);
          Read(b[4][0],b[4][1]);
          if(b[4][0]==4) 
              break;
          else   
          {
              c[2]=c[2]-1;c[3]=c[3]+1;
              break;
          }
         default:printf("ERROR input!"); break;
}    

Produce(c,a,b);
scanf("%d",&j);
       
}