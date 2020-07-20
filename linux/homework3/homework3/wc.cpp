#include<iostream>
#include<string>
#include<fstream>
#include<vector>
#include<io.h>

void wc( char* );

int main( int argc, char* argv[] )
{
    for( int i = 1; i < argc; i++ )
    {
        wc( argv[i] );
    }
}

void wc( char* name )
{
    using namespace std;
    ifstream fin( name );

    if( ( _access( name, 0 ) ) < 0 )
    {
        cout << name << "文件或目录不存在!" << endl;
        return;
    }

    //cout << name;
    char c;
    int line_num = 1;
    int word_num = 0;
    bool isABC = false;
    vector<char> v;

    while( ( c = fin.get() ) != EOF )
    {
        if( c == '\n' )
        {
            isABC = false;
            word_num++;
            line_num++;
        }

        if( c != '\n' && c != '\t' && c != ' ' )
        {
            isABC = true;
        }

        if( isABC && c == ' ' )
        {
            isABC = false;
            word_num++;
        }

        v.push_back( c );
        //cout << c;
    }

    if( v.size() == 0 )
        cout << 0 << " " << 0 << " " << 0 << " " << name << endl;
    else
        cout << line_num << " " << word_num << " " << v.size() << " " << name << endl;

}
