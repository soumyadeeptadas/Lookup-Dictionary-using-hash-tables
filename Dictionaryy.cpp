#include <stdio.h>
#include <conio.h>
#include <malloc.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include<iostream>
using namespace std;

struct node
{
    char data [ 20 ] ;
    char m [ 5 ] [ 20 ] ;
    int mcount ;
    struct node * link ;
} ;

struct node * dic [ 26 ] ;

int add ( char * ) ;
int  search ( char * ) ;
void show( ) ;
void deldic( ) ;
int lcs(char *);

int main( )
{int u;
    char word [ 20 ] , ch ;
    int i ;
    
/*	for(int n=0;n<26;n++)
	{
		
	}
	char t[3];
    for(int g=0;g<26;g++)
    { t[0]=char(g);
    	strcpy(dic[g]->data,t);
	}
    
    char ze[3];
    struct node *o,*b;
    strcpy(o->data,ze);
    
for(int h=0;h<26;h++)
{

        dic [ h ] = o ;
        
	
}*/
   

    while ( 1 )
    {
        
        printf ( "\n\t\tDictionary\n" ) ;
        printf ( "\n\t\t1.Add Word.\n" ) ;
        printf ( "\t\t2.Search Word.\n" ) ;
        printf ( "\t\t3.Show Dictionary.\n" ) ;
        printf ( "\t\t0.Exit." ) ;
        printf ( "\n\n\t\tYour Choice ") ;
        scanf ( "%d", &ch ) ;

        switch ( ch )
        {
            case 1 :

                printf ( "\nEnter any word : " ) ;
                fflush ( stdin ) ;
                gets ( word ) ;
                u=add ( word ) ;
                if(u==1)
				{cout<<"Word Added!"<<endl;
				 } 
                break ;

            case 2 :

                printf ( "\nEnter the word to search : " ) ;
                fflush ( stdin ) ;
                gets ( word ) ;
                i = search ( word ) ;
                if ( ! i )
                   {
					cout<<"Word does not exists.\n\n";
                    int o;
					o=lcs(word);
                    
                   }
                /*else
                {
                	cout<<"Word found";
                	//show(word);
				}*/
                getch( ) ;

                break ;

            case 3 :

                show( ) ;
                getch( ) ;

                break ;

            case 0 :

                deldic( ) ;
                exit ( 0 ) ;

            default :

                printf ( "\nWrong Choice" ) ;
        }
    }
}

int add ( char * str )
{
    int i, j = toupper ( str [ 0 ] ) - 65 ;
    struct node * r, * temp = dic [ j ], * q ;
    char mean [5][20], ch = 'y' ;

    i = search ( str ) ;
    if ( i )
    {
        printf ( "\nWord already exists." ) ;
        getch( ) ;
        return 0;
    }
    q = ( struct node * ) malloc ( sizeof ( struct node ) ) ;
    strcpy ( q -> data, str ) ;
    q -> link = NULL ;

    for ( i = 0 ; tolower ( ch ) == 'y' && i < 5 ; i++ )
    {
        
		fflush ( stdin ) ;
        printf ( "\n\nEnter the meaning(s) : " ) ;
        gets(mean[i]) ;
        strcpy ( q -> m [ i ], mean[i] ) ;
        if(i!=4)
        printf ( "\nAdd more meanings (y/n) " ) ;
        
        else
            printf ( "You cannot enter more than 5 meanings." ) ;
        fflush ( stdin ) ;
        cin>>ch;
    }

    q -> mcount = i ;
    if ( dic[j] == NULL || strcmp ( dic [ j ] -> data, str ) > 0)
    {
        
        r = dic [ j ] ;
        dic [ j ] = q ;
        dic[j]-> link = r;    //replace dic[j] with q for prev code in this line
        return 1;
    }

    else
    {
        while ( temp != NULL )
        {
            if (( ( strcmp ( temp -> data, str ) < 0 ) &&  ( strcmp ( temp -> link -> data, str ) > 0 ) && (temp->link!=NULL) )||(temp -> link == NULL ) )
            {
            	if(temp->link==NULL)                //edit
            	{
            		q->link=NULL;
            		temp->link=q;
            		return 1;
				}
				
				else
				{			
                q -> link = temp->link ;
                temp -> link = q ;
                return 1 ;
                }                                    //
            }
        
            temp = temp -> link ;
        }
    }
}

int search ( char *str )
{
    struct node *n ;
    char temp1 [ 20 ] ;
    char temp2 [ 20 ] ;
    int i ;

    n = dic [ toupper ( str [ 0 ] ) - 65 ] ;
    strcpy ( temp2, str ) ;
    strupr ( temp2 ) ;

    while ( n != NULL )
    {
        strcpy ( temp1, n -> data ) ;

        if (  strcmp ( strupr ( temp1 ), temp2 ) == 0 )
        {
            printf ( "\n%s\t\t%s", n -> data, n -> m [ 0 ] ) ;
            for ( i = 1 ; i < n -> mcount ; i++ )
                printf ( "\n\t\t%s", n -> m [ i ] ) ;
            return 1 ;
        }
        n = n -> link ;
    }
    return 0 ;
}

void show( )
{
    struct node *n ;
    int i, j ;

    printf ( "Word\t\tMeaning\n" ) ;
    for ( i = 0 ; i <= 30 ; i++ )
        printf ( "-" ) ;


    for ( i = 0 ; i <= 25 ; i++ )
    {
        n = dic [ i ] ;
        while ( n != NULL )
        {
            printf ( "\n%s\t\t%s", n -> data, n -> m [ 0 ] ) ;
            for ( j = 1 ; j < n -> mcount ; j++ )
                printf ( "\n\t\t%s", n -> m [ j ] ) ;
            n = n -> link ;
        }
    }
}

void deldic( )
{
    struct node *n, *t ;
    int i ;

    for ( i = 0 ; i <= 25 ; i++ )
    {
        n = dic [ i ] ;
        while ( n != NULL )
        {
            t = n -> link ;
            free ( n ) ;
            n = t ;
        }
    }
}




int lcs( char *str )
{
    struct node *n ;
    char temp1 [ 20 ] ;
    char temp2 [ 20 ] ;
    int p, q;
    
    /*p=strlen(temp1);
    q=strlen(temp2);
    int L[p + 1][q + 1]; 
    int i, j; */
    int i, j; 
    n = dic [ toupper ( str [ 0 ] ) - 65 ] ;
    strcpy ( temp2, str ) ;
    strupr ( temp2 ) ;

    while ( n != NULL )
    {
    	
        strcpy ( temp1, n -> data ) ;

        if (  strcmp ( strupr ( temp1 ), temp2 ) == 0 )
        {
            printf ( "\n%s\t\t%s", n -> data, n -> m [ 0 ] ) ;
            for ( i = 1 ; i < n -> mcount ; i++ )
                printf ( "\n\t\t%s", n -> m [ i ] ) ;
            return 1 ;
        }
       // n = n -> link ;
    
    
    
    
    
    //int max(int a, int b); 
  
/* Returns length of LCS for X[0..m-1], Y[0..n-1] */
 
   p=strlen(temp1);
    q=strlen(temp2);
    int L[p + 1][q + 1]; 
    
  
    /* Following steps build L[m+1][n+1] in bottom up fashion. Note  
      that L[i][j] contains length of LCS of X[0..i-1] and Y[0..j-1] */
    for (i = 0; i <= p; i++) 
	{ 
        for (j = 0; j <= q; j++) 
		{ 
            if (i == 0 || j == 0) 
                L[i][j] = 0; 
  
            else if (temp1[i - 1] == temp2[j - 1]) 
                L[i][j] = L[i - 1][j - 1] + 1; 
  
            else
                L[i][j] = (L[i-1][j]>L[i][j-1])?L[i-1][j]:L[i][j-1];     /* Utility function to get max of 2 integers */
        } 
    } 
  
    
	
	 
     // Following code is used to print LCS 
   int index = L[p][q]; 
  
   // Create a character array to store the lcs string 
   char lcs[index+1]; 
   //lcs[index] = ' '; // Set the terminating character 
  
   // Start from the right-most-bottom-most corner and 
   // one by one store characters in lcs[] 
   i = p; 
   j = q; 
   while (i > 0 && j > 0) 
   { 
      // If current character in X[] and Y are same, then 
      // current character is part of LCS 
      if (temp1[i-1] == temp2[j-1]) 
      { 
          lcs[index-1] = temp1[i-1]; // Put current character in result 
          i--; j--; index--;     // reduce values of i, j and index 
      } 
  
      // If not same, then find the larger of two and 
      // go in the direction of larger value 
      else if (L[i-1][j] > L[i][j-1]) 
         i--; 
      else
         j--; 
   } 
   // Print the lcs 
   cout << "LCS of " << temp1 << " and " << temp2<< " is " << lcs<<endl;
   cout<<"Did you mean this? : "<<temp1<<endl<<"\n";
   //cout<<"\nLCS length:"<<L[p][q]<<"\n\n";

   

n = n -> link ;
}/* L[m][n] contains length of LCS for X[0..n-1] and Y[0..m-1] 
    return L[p][q];  */
return 0;
}







