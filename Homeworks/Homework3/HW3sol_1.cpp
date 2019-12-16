#include<iostream>
#include<cstring>
using namespace std;

int main()
{
    char s[64][1025]; /// Can be made without array. Using it for simplicity.
    int par = 0, curr = 0; /// par - count for paragraphs, curr - length of the current paragraph
    char ch;

    do /// Formating the input
    {
        cin.get(ch);
        if(ch == '\n' || ch == '~')
        {
            if(curr && s[par][curr-1]==' ')s[par][curr-1] = 0; /// if the paragraph isn't empty then put '\0' one symbol before the end of the paragraph
            s[par++][curr] = 0; /// if the paragraph is not empty then putting '\0' at the end of the paragraph
            curr = 0; /// resetting the length of the current paragraph
        }
        if(ch == '.' || ch == ',' || ch == '?' || ch == '!')
        {
            if(curr && s[par][curr-1] == ' ') curr--; /// if the paragraph is not empty and the previous character is space then curr-- (before '.', ',', '?' and '!' we don't have to have space)
            s[par][curr++] = ch; /// setting the curr symbol to be the punctuation mark
            s[par][curr++] = ' '; /// setting the next symbol to be space (if needed we will replace it where needed)
        }
        if(ch >= 'A' && ch <= 'Z') ch += ('a' - 'A'); /// setting all letters to be lower case
        if(ch >= 'a' && ch <= 'z')
        {
            if(!curr) s[par][curr++] = ch + ('A' - 'a'); /// if the paragraph is empty then setting the letter to upper case
            else if(curr>1 && (s[par][curr-2] == '.' || s[par][curr-2] == '?' || s[par][curr-2] == '!')) s[par][curr++] = ch + ('A' - 'a'); /// if the paragraph isn't empty and 2 symbols before there is punctuation mark then setting the letter to upper
            else s[par][curr++] = ch; /// else the letter is lower case
        }
        if(ch == ' ')
        {
            if(curr && ((s[par][curr-1] >= 'a' && s[par][curr-1] <= 'z') || (s[par][curr-1] >= 'A' && s[par][curr-1] <= 'Z'))) s[par][curr++] = ' '; /// if the paragraph isn't empty and the previous symbol is a letter, then add space
        }
    }while(ch!='~');

    /// Printing the text in the required form
    int i=0;
    while(s[i++][0] == 0);
    for(int j=0;s[i-1][j];j++) /// the title paragraph
    {
        if(j && s[i-1][j-1]==' ' && s[i-1][j]>='a' && s[i-1][j]<='z')s[i-1][j]+=('A'-'a');
        cout<<s[i-1][j];
    }
    cout<<endl;
    for(; i<=par; i++)
     if(s[i][0] != 0)
      cout<<endl<<s[i];
    return 0;
}
