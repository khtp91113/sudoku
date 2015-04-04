#include"Sudoku.h"
#include<cstdlib>
using namespace std;

void Sudoku::GiveQuestion()
{
 int select,origin[12][12],i,j;
 srand(time(NULL));
 select=rand()%3;
 int origin_1[12][12]={{-1,-1,-1, 1, 9, 8, 5, 2, 4, 7, 6, 3},
                       {-1,-1,-1, 6, 2, 4, 3, 9, 7, 8, 5, 1},
                       {-1,-1,-1, 5, 7, 3, 1, 6, 8, 4, 9, 2},
                       { 5, 6, 8, 2, 4, 1,-1,-1,-1, 9, 3, 7},
                       { 2, 4, 7, 9, 3, 5,-1,-1,-1, 1, 8, 6},
                       { 1, 3, 9, 8, 6, 7,-1,-1,-1, 5, 2, 4},
                       { 8, 1, 6,-1,-1,-1, 2, 7, 5, 3, 4, 9},
                       { 3, 9, 5,-1,-1,-1, 4, 1, 6, 2, 7, 8},
                       { 7, 2, 4,-1,-1,-1, 8, 3, 9, 6, 1, 5},
                       { 9, 7, 3, 4, 8, 2, 6, 5, 1,-1,-1,-1},
                       { 6, 8, 1, 3, 5, 9, 7, 4, 2,-1,-1,-1},
                       { 4, 5, 2, 7, 1, 6, 9, 8, 3,-1,-1,-1}};
 int origin_2[12][12]={{ 5, 1, 3, 2, 6, 4,-1,-1,-1, 7, 9, 8},
                       { 7, 6, 4, 8, 1, 9,-1,-1,-1, 2, 3, 5},
                       { 2, 9, 8, 7, 3, 5,-1,-1,-1, 1, 4, 6},
                       {-1,-1,-1, 3, 7, 2, 1, 4, 6, 8, 5, 9},
                       {-1,-1,-1, 5, 9, 6, 2, 3, 8, 4, 7, 1},
                       {-1,-1,-1, 1, 4, 8, 7, 9, 5, 6, 2, 3},
                       { 1, 4, 7,-1,-1,-1, 3, 8, 9, 5, 6, 2},
                       { 3, 2, 6,-1,-1,-1, 4, 5, 1, 9, 8, 7},
                       { 8, 5, 9,-1,-1,-1, 6, 2, 7, 3, 1, 4},
                       { 6, 3, 5, 9, 2, 7, 8, 1, 4,-1,-1,-1},
                       { 9, 7, 2, 4, 8, 1, 5, 6, 3,-1,-1,-1},
                       { 4, 8, 1, 6, 5, 3, 9, 7, 2,-1,-1,-1}};
 int origin_3[12][12]={{-1,-1,-1, 2, 6, 3, 1, 4, 7, 5, 9, 8},
                       {-1,-1,-1, 8, 7, 4, 2, 5, 9, 6, 1, 3},
                       {-1,-1,-1, 5, 9, 1, 8, 3, 6, 2, 4, 7},
                       { 2, 3, 7,-1,-1,-1, 6, 1, 4, 9, 8, 5},
                       { 5, 8, 1,-1,-1,-1, 7, 9, 2, 4, 3, 6},
                       { 4, 6, 9,-1,-1,-1, 3, 8, 5, 7, 2, 1},
                       { 9, 2, 8, 3, 5, 7,-1,-1,-1, 1, 6, 4},
                       { 1, 5, 3, 4, 2, 6,-1,-1,-1, 8, 7, 9},
                       { 7, 4, 6, 1, 8, 9,-1,-1,-1, 3, 5, 2},
                       { 6, 7, 5, 9, 3, 8, 4, 2, 1,-1,-1,-1},
                       { 8, 9, 4, 7, 1, 2, 5, 6, 3,-1,-1,-1},
                       { 3, 1, 2, 6, 4, 5, 9, 7, 8,-1,-1,-1}};
 switch(select)
 {
  case 0:for(i=0;i<12;i++)
          for(j=0;j<12;j++)
           origin[i][j]=origin_1[i][j];
          break;
  case 1:for(i=0;i<12;i++)
          for(j=0;j<12;j++)
           origin[i][j]=origin_2[i][j];
          break;
  default:for(i=0;i<12;i++)
           for(j=0;j<12;j++)
            origin[i][j]=origin_3[i][j];
           break;
 }
 int change_num,rotate;
 int n[9],check[9]={0};
 for(i=0;i<9;i++)
 {
  n[i]=rand()%9+1;
  while(check[n[i]-1]>0)
   n[i]=rand()%9+1;
  check[n[i]-1]++;
 }
 for(i=0;i<12;i++)
  for(j=0;j<12;j++)
  {
   if(origin[i][j]==-1||origin[i][j]==0);
   else
    origin[i][j]=n[origin[i][j]-1];
  }
 int temp[12][12];
 srand(time(NULL));
 rotate=rand()%5;
 switch(rotate)
 {
  case 0:for(i=0;i<12;i++)
          for(j=0;j<12;j++)
           temp[i][j]=origin[i][j];
         for(i=0;i<12;i++)
          for(j=0;j<12;j++)
           origin[j][i]=temp[i][j];
         break;
  case 1:for(i=0;i<12;i++)
          for(j=0;j<12;j++)
           temp[i][j]=origin[i][j];
         for(i=0;i<12;i++)
          for(j=0;j<12;j++)
           origin[11-j][11-i]=temp[i][j];
         break;
  case 2:for(i=0;i<12;i++)
          for(j=0;j<12;j++)
           temp[i][j]=origin[i][j];
         for(i=0;i<12;i++)
          for(j=0;j<12;j++)
           origin[11-i][j]=temp[i][j];
         break;
  case 3:for(i=0;i<12;i++)
          for(j=0;j<12;j++)
           temp[i][j]=origin[i][j];
         for(i=0;i<12;i++)
          for(j=0;j<12;j++)
           origin[i][11-j]=temp[i][j];
         break;
  default:break;
 }
 for(i=0;i<12;i++)
 {
  for(j=0;j<12;j++)
  {
   if(origin[i][j]==-1)
    cout<<origin[i][j]<<" ";
   else
    cout<<" "<<origin[i][j]<<" ";
  }
  cout<<endl;
 } 
}

void Sudoku::ReadIn()
{
 int i,j;
 for(i=0;i<12;i++)
  for(j=0;j<12;j++)
   cin>>sudoku[i][j];
 for(i=0;i<12;i++)
 {
  for(j=0;j<12;j++)
  {
   if(sudoku[i][j]==-1)
    cout<<sudoku[i][j]<<" ";
   else
    cout<<" "<<sudoku[i][j]<<" ";
  }
  cout<<endl;
 } 
}

void Sudoku::Solve()
{
 int result=-1,i,j,total=0,pass=0,check[9]={0};
 for(i=0;i<12;i++)
  for(j=0;j<12;j++)
  {
   if(sudoku[i][j]==-1)
   {
    total++;
    if(pass==0)
     if(sudoku[i][j+1]!=-1||sudoku[i][j+2]!=-1||sudoku[i+1][j]!=-1||sudoku[i+1][j+1]!=-1||sudoku[i+1][j+2]!=-1||sudoku[i+2][j]!=-1||sudoku[i+2][j+1]!=-1||sudoku[i+2][j+2]!=-1)
      result=0;
     else;
    else;
    pass=1;
    if(total%9==0)
     pass=0;
    else;
   }
  }
 if(total!=36)
  result=0;
 else;
 for(i=0;i<12;i++)
 {
  for(j=0;j<12;j++)
  {
   if(sudoku[i][j]==-1||sudoku[i][j]==0);
   else
   {
    if(check[sudoku[i][j]-1]==1)
     result=0;
    else;
    check[sudoku[i][j]-1]++;
   }
  }
  for(j=0;j<9;j++)
   check[j]=0;
 }
 if(result==0)
 {
  cout<<result<<endl;
  return;
 }
}
