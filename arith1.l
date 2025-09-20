%{
#include "y.tab.h"
%}

%%
\+ {return(PLUS);}
- {return(MOINS);}
\/ {return(DIV);}
\* {return(MULT);}
\( {return(PO);}
\)  {return(PF);}
0|[1-9][0-9] {return(ENTIER);}

%% 
int yywrap(){
    return(1); 
}
