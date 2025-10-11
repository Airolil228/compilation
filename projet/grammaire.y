        %{
        #include <stdio.h>
        #include <stdlib.h>

        int yylex();
        int yyerror(char *s); 

        extern int yylineno;      // Nécessaire pour afficher le numéro de ligne
        extern char *yytext;      // Nécessaire pour afficher le token

        %}

        %token PROG  
        %token POINT_VIRG POINT
        %token DEBUT FIN
        %token TYPE IDF DEUX_POINTS
        %token STRUCT FINSTRUCT
        %token TABLEAU DE 
        %token CROCHET_OUVRANT CROCHET_FERMANT
        %token VIRGULE
        %token CSTE_ENTIERE POINT_POINT
        %token ENTIER REEL BOOLEEN CARACTERE CHAINE 
        %token VARIABLE 
        %token PROCEDURE FONCTION RETOURNE
        %token PARENTHESE_OUVRANTE PARENTHESE_FERMANTE
        %token VIDE
        %token SI ALORS SINON FINSI
        %token TANT_QUE FAIRE FINTANT_QUE
        %token OPAFF
        %token PLUS MOINS MULT DIV
        %token ET OU NON
        %token EGALE DIFFERENT INFERIEUR INFERIEUR_EGAL SUPERIEUR SUPERIEUR_EGAL
        %token VRAI FAUX
        %%

        programme: PROG corps
        ;

         corps:  liste_decl liste_inst   
                | liste_inst
        ;        
                
        liste_decl:  declaration POINT_VIRG   
                   | liste_decl declaration POINT_VIRG
        ;
        
        liste_inst: DEBUT suite_liste_inst FIN
        ; 
        
        suite_liste_inst: /*vide*/ 
                      | suite_liste_inst instruction POINT_VIRG 
                      | liste_inst_non_vide POINT_VIRG 
        ;
        
        declaration:    declaration_variable                                    { printf("Declaration de variable reconnue ! \n");}
                      | declaration_fonction                                    { printf("Declaration de fonction reconnue ! \n");}
                      | declaration_procedure                                   { printf("Declaration de procedure reconnue ! \n");} 
                      | declaration_type                                        { printf("Declaration de type reconnue ! \n");}       
        ;
        
        declaration_type: TYPE IDF DEUX_POINTS suite_decl_type 
        ;  

        suite_decl_type: STRUCT liste_champs FINSTRUCT                          { printf("Type structure reconnu ! \n"); }
                        | TABLEAU dimension DE nom_type                         { printf("Type tableau reconnu ! \n"); }       
        ;

        dimension: CROCHET_OUVRANT liste_dimensions CROCHET_FERMANT             
        ; 

        liste_dimensions: une_dimension  
                        | liste_dimensions VIRGULE  une_dimension 
        ; 

        une_dimension: CSTE_ENTIERE POINT_POINT CSTE_ENTIERE 
        ; 

        liste_champs: un_champ  
                | liste_champs POINT_VIRG un_champ     
        ;

        un_champ: IDF DEUX_POINTS nom_type 
        ; 
        
        declaration_variable: VARIABLE IDF DEUX_POINTS nom_type 
        ;  

        nom_type: type_simple 
                  | IDF 
        ; 

        type_simple: ENTIER 
                  | REEL  
                  | BOOLEEN  
                  | CARACTERE  
                  | CHAINE  CROCHET_OUVRANT CSTE_ENTIERE CROCHET_FERMANT 
        ;

        declaration_procedure: PROCEDURE IDF liste_parametres corps
        ;

        declaration_fonction: FONCTION IDF liste_parametres RETOURNE type_simple corps 
        ; 

        liste_parametres: /* vide  */
                  | PARENTHESE_OUVRANTE liste_param PARENTHESE_FERMANTE 
        ; 

        liste_param: un_param 
                  | liste_param POINT_VIRG un_param 
        ; 

        un_param: IDF DEUX_POINTS type_simple 
        ; 

        liste_inst_non_vide: DEBUT suite_liste_inst_non_vide FIN
        ;

        suite_liste_inst_non_vide: instruction POINT_VIRG
                         | suite_liste_inst_non_vide instruction POINT_VIRG
        ;

        instruction: affectation  
                | condition  
                |tant_que    
                |appel      
                | VIDE       
                | RETOURNE resultat_retourne
        ; 

        resultat_retourne: /* vide */                                                  
                         | expression 
                         ; 

        appel: IDF liste_arguments                                                   { printf("Appel de fonction reconnue ! \n"); }
         ; 

        liste_arguments: /* vide */
                 | PARENTHESE_OUVRANTE liste_args PARENTHESE_FERMANTE  
        ; 

        liste_args: un_arg 
                  | liste_args VIRGULE un_arg 
                  ;

        un_arg: expression 
                ; 

        condition: SI expression_booleenne ALORS liste_inst SINON liste_inst FINSI       { printf("Condition avec sinon reconnue ! \n"); }
                 | SI expression_booleenne ALORS liste_inst FINSI                        { printf("Condition sans sinon reconnue ! \n"); }
                 ;                    

        tant_que: TANT_QUE expression_booleenne FAIRE liste_inst FINTANT_QUE             { printf("Tant que boucle reconnue ! \n"); }
        ;                       

        affectation: variable OPAFF expression                                           { printf("Affectation reconnue ! \n"); } 
        ;                                        

        /*** Partie autonomie ***/
        variable: IDF  
                | IDF CROCHET_OUVRANT expression CROCHET_FERMANT  
                | IDF POINT expression 
                ; 

        expression: expression1                                                          { printf("Expression arithmetique reconnue ! \n"); }
                | expression_booleenne                                                   { printf("Expression booleenne reconnue ! \n"); }     
                ;

        expression1: expression1 PLUS expression2
                | expression1 MOINS expression2
                | expression2
                ;

        expression2: expression2 MULT  expression3
                | expression2 DIV expression3
                | expression3
                ;

        expression3: PARENTHESE_OUVRANTE expression1 PARENTHESE_FERMANTE
                | CSTE_ENTIERE
                ;


        expression_booleenne: expression_booleenne OU expression_booleenne1
                | expression_booleenne1
                ;

        expression_booleenne1:
                IDF
                ;
        
        %%

        int yyerror(char *s){
        fprintf(stderr, "\n ERREUR DE SYNTAXE à la ligne %d\n", yylineno);
        fprintf(stderr, " le token incorrect: %s\n", yytext);
        return 0;
        }

        int main(){

        if(yyparse() == 0) {
                printf("Analyse syntaxique terminée avec succès !\n");
        } else {
                printf("Echec de l'analyse syntaxique.\n");

        };

        return 0;
        }