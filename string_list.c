#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define L_MAX 36	// -1 than actual char_list[]
const char char_list[] = "0123456789abcdefghijklmnopqrstuvwxyzE";

int main(int argc, char *argv[])
{
    if (argc < 2) {
        printf("Usage : $ ./string_list [the length of string]\n");
        exit(1);
    }   
    else if(argc > 2) {
        printf("Too many arguments!\n");
        exit(1);
    }   
    
    const int length = atoi(argv[1]);
    char *r_str = (char *)malloc((sizeof(char)*length)+1);

    for(int i=0; i<length; i++)
        r_str[i] = char_list[0];

    int l_reckon[length];
    for(int ini=0; ini<length; ini++){
	    l_reckon[ini] = 0;
    }

    for(int i=0; i<pow((double)L_MAX, (double)length); i++){
        printf("%s\n", r_str);
		r_str[length-1] = char_list[++l_reckon[length-1]];
		
		for(int j=length-1; j>=0; j--){
			if(r_str[j] == char_list[L_MAX]){
				r_str[j] = char_list[0];
				l_reckon[j]=0;
				if(j!=0){
					r_str[j-1] = char_list[++l_reckon[j-1]];
				}
			}
			else
				break;
		}
	}

	return 0;
}
