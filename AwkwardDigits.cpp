/*

This is free and unencumbered software released into the public domain.

Anyone is free to copy, modify, publish, use, compile, sell, or
distribute this software, either in source code form or as a compiled
binary, for any purpose, commercial or non-commercial, and by any
means.

In jurisdictions that recognize copyright laws, the author or authors
of this software dedicate any and all copyright interest in the
software to the public domain. We make this dedication for the benefit
of the public at large and to the detriment of our heirs and
successors. We intend this dedication to be an overt act of
relinquishment in perpetuity of all present and future rights to this
software under copyright law.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,
EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF
MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.
IN NO EVENT SHALL THE AUTHORS BE LIABLE FOR ANY CLAIM, DAMAGES OR
OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE,
ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR
OTHER DEALINGS IN THE SOFTWARE.

For more information, please refer to <http://unlicense.org/>

*/


#include <iostream>
#include <string>

using namespace std;

void c(string a, string b)
{
    int d, t=0, s=a.length()-1;
    int b2=0, b3=0;
    int i;
    while(s>=0){
        d=a[s--]-48;
        for(i=0;i<t;i++){
            d*=2;
        }
        b2+=d, t++, d=0;
    }
    s=b.length()-1, t=0;
    while(s>=0){
        d=b[s--]-48;
        for(i=0;i<t;i++){
            d*=3;
        }
        b3+=d, t++, d=0;
    }
    if(b2==b3){
        cout << b2 << endl;
    }
    return ;
}

int main()
{
    string base2, base3;
    int len2, len3;
    int i, j;
    
    cin >> base2 >> base3;
    len2=base2.length(), len3=base3.length();
    
    for(i=0;i<len2;i++){
        base2[i]=char(97-int(base2[i]));
        for(j=0;j<len3;j++){
            if(base3[j]=='0'){
                base3[j]='1';
                c(base2, base3);
                base3[j]='2';
                c(base2, base3);
                base3[j]='0';
            }
            else if(base3[j]=='1'){
                base3[j]='0';
                c(base2, base3);
                base3[j]='2';
                c(base2, base3);
                base3[j]='1';
            }
            else if(base3[j]=='2'){
                base3[j]='1';
                c(base2, base3);
                base3[j]='0';
                c(base2, base3);
                base3[j]='2';
            }
        }
        base2[i]=char(97-int(base2[i]));
    }
    
    return 0;
}
