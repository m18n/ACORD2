#include "include/parsehtml.h"
ParseHtml::ParseHtml(char *html, int size)
{
    this->html = html;
    this->sizehtml = size;
}

ParseHtml::~ParseHtml()
{
}
int ParseHtml::SearchWord(const char *word)
{
    int sizeword = strlen(word);
    int n = 0;
    int i = 0;
    bool sovpad = false;
    for (i = 0; i < sizehtml; i++)
    {
        
        if (html[i] == word[n])
        {

            std::cout << html[i] << "\n";
            if (html[i] == '\"'){
                std::cout << "STOP\n";
                std::cout<<"\nNEXT: \n";
                std::cout<<"HTML: "<<html[i+1]<<"\n";
                std::cout<<"WORD: "<<word[n+1]<<"\n\n";
            }
            if (n == sizeword - 1)
            {
                sovpad = true;
                break;
            }
            n++;
        }
        else
            n = 0;
    }
    if (sovpad == true)
        return i;
    else
        return -1;
}